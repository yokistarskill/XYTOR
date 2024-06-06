// XYTOR. All Rights Reserved.

#include "Core/Dialogues/AC_Dialogues.h"
#include "PS_Tokens.h"
#include "DialogueGraph/PlayerDialogueGraphNode.h"

// Sets default values for this component's properties
UAC_Dialogues::UAC_Dialogues()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;
    // ...
}

bool UAC_Dialogues::InitializeTokens()
{
    if (Tokens) return true;

    Tokens = Cast<APS_Tokens>(GetOwner());
    if (Tokens) return true;

    return false;
}

void UAC_Dialogues::BeginDialogue(UDialogueGraph* Dialogue)
{    

    DialogueGraph = Dialogue;

    if (!DialogueGraph || !InitializeTokens())
    {
        return;
    }
    DialogueGraph->UpdateValidationTags(Tokens->GetTokens());
    
    CurrentNPCNode = DialogueGraph->GetStartDialogueNode();

    CurrentPlayerDialogueNodes = DialogueGraph->GetPlayerDialogueNodes(CurrentNPCNode);

    OnBeginDialogueDelegate.Broadcast(CurrentNPCNode, CurrentPlayerDialogueNodes);
    
    GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, FString::Printf(TEXT("BeginDialogue.")));
}

void UAC_Dialogues::ProceedDialogue(const UPlayerDialogueGraphNode* Node)
{
    if (!DialogueGraph || !Node || !Tokens)
    {
        return;
    }
    
    CurrentNPCNode = nullptr;

    Tokens->UpdateTokens(Node->GetResultData().ResultTags);
    DialogueGraph->UpdateValidationTags(Tokens->GetTokens());
    
    CurrentNPCNode = DialogueGraph->GetNPCDialogueNode(Node);

    if (CurrentNPCNode)
    {
        CurrentPlayerDialogueNodes.Empty();
        CurrentPlayerDialogueNodes = DialogueGraph->GetPlayerDialogueNodes(CurrentNPCNode);

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


