// XYTOR. All Rights Reserved.


#include "Core/Dialogues/W_DialogueWindow.h"
#include "Core/Dialogues/AC_ProceedDialogue.h"
#include "DialogueGraph/PlayerDialogueGraphNode.h"
#include "DialogueGraph/NPCDialogueGraphNode.h"
#include "W_DialogueLine.h"
#include "Components/VerticalBox.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UW_DialogueWindow::NativeOnInitialized()
{
    Super::NativeOnInitialized();
}

void UW_DialogueWindow::InitializeWidget(UAC_ProceedDialogue* DialogueHandler)
{
    ProceedDialogue = DialogueHandler;
}

void UW_DialogueWindow::OnUpdateDialogue(const UNPCDialogueGraphNode* NPCNode, const TArray<UPlayerDialogueGraphNode*> PlayerDialogueNodes)
{
    if (!NPCNode || !PlayerDialogueLineContainer || !NPCDialogueIcon || !NPCDialogueText) return;

    PlayerDialogueLineContainer->ClearChildren();
    
    const auto NPCIcon = NPCNode->GetVisualData().Icon;
    if (!NPCIcon)
    {
        NPCDialogueIcon->SetBrushFromTexture(NPCIcon);
    }
    
    const auto Text = NPCNode->GetVisualData().DialogueText;
    NPCDialogueText->SetText(Text);

    for (const auto Node : PlayerDialogueNodes)
    {
        const auto PlayerDialogueLineWidget = CreateWidget<UW_DialogueLine>(GetWorld(), DialogueLineClass);
        if (!PlayerDialogueLineWidget) continue;
        
        PlayerDialogueLineWidget->SetDialogueWindow(this);
        PlayerDialogueLineWidget->SetPlayerNode(Node);

        const auto PlayerIcon = Node->GetVisualData().Icon;
        if (PlayerIcon)
        {
            PlayerDialogueLineWidget->SetDialogueIcon(PlayerIcon);
        }

        const auto PlayerText = Node->GetVisualData().DialogueText;
        PlayerDialogueLineWidget->SetDialogueText(PlayerText);

        PlayerDialogueLineContainer->AddChild(PlayerDialogueLineWidget);
    }
}

