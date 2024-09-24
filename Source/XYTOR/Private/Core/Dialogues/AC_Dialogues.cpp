// XYTOR. All Rights Reserved.

#include "Core/Dialogues/AC_Dialogues.h"

#include "AC_Interact.h"
#include "PS_Quests.h"
#include "PS_Tokens.h"
#include "DialogueGraph/PlayerDialogueGraphNode.h"

// Sets default values for this component's properties
UAC_Dialogues::UAC_Dialogues()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = false;
    // ...
}

bool UAC_Dialogues::InitializeTokens()
{
    if (Tokens) return true;

    Tokens = Cast<APS_Tokens>(GetOwner());
    if (Tokens) return true;

    return false;
}

bool UAC_Dialogues::InitializeQuests()
{
    if (Quests) return true;

    Quests = Cast<APS_Quests>(GetOwner());
    if (Quests) return true;

    return false;
}

bool UAC_Dialogues::InitializeInventory()
{
    if (Inventory) return true;

    Inventory = GetOwner()->GetComponentByClass<UAC_Inventory>();
    if (Inventory) return true;

    return false;
}

bool UAC_Dialogues::Initialization()
{
    return InitializeQuests() | InitializeTokens() | InitializeInventory();
}

bool UAC_Dialogues::ValidatePlayerNode(const UPlayerDialogueGraphNode* Node) const
{
    return Inventory->Contains(Node->GetConditionData().Items);
}

void UAC_Dialogues::BeginDialogue(UDialogueGraph* Dialogue)
{    

    DialogueGraph = Dialogue;

    if (!DialogueGraph || !Initialization())
    {
        UE_LOG(LogTemp, Warning, TEXT("Initialization in UAC_Dialogues::BeginDialogue failed"))
        return;
    }
    DialogueGraph->UpdateValidationTags(Tokens->GetTokens());
    
    CurrentNPCNode = DialogueGraph->GetStartDialogueNode();
    if (!CurrentNPCNode)
        return;
    
    CurrentPlayerDialogueNodes = DialogueGraph->GetPlayerDialogueNodes(CurrentNPCNode);
    
    OnBeginDialogueDelegate.Broadcast(CurrentNPCNode, CurrentPlayerDialogueNodes);
    
    GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, FString::Printf(TEXT("BeginDialogue.")));
}

void UAC_Dialogues::ProceedDialogue(const UPlayerDialogueGraphNode* Node)
{
    if (!DialogueGraph || !Node || !Tokens || !Inventory || !Quests)
    {
        return;
    }
    
    CurrentNPCNode = nullptr;

    Quests->AddQuest(Node->GetResultData().Quest);
    Inventory->AddItems(Node->GetResultData().Items);
    Tokens->UpdateTokens(Node->GetResultData().ResultTags);
    DialogueGraph->UpdateValidationTags(Tokens->GetTokens());
    
    CurrentNPCNode = DialogueGraph->GetNPCDialogueNode(Node);

    if (CurrentNPCNode)
    {
        CurrentPlayerDialogueNodes.Empty();
        CurrentPlayerDialogueNodes = DialogueGraph->GetPlayerDialogueNodes(CurrentNPCNode);
        CurrentPlayerDialogueNodes.RemoveAll([this](auto Node)
        {
            return !this->ValidatePlayerNode(Node);
        });
        OnProceedDialogueDelegate.Broadcast(CurrentNPCNode, CurrentPlayerDialogueNodes);
    }

    if (!CurrentNPCNode)
    {
        EndDialogue();
    }
}

void UAC_Dialogues::EndDialogue()
{
    OnEndDialogueDelegate.Broadcast();

    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("EndDialogue")));

    DialogueGraph = nullptr;
}


