// XYTOR. All Rights Reserved.


#include "Core/Dialogues/W_DialogueLine.h"

#include "AC_DialogueHandler.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Core/Tokens/PS_Tokens.h"

void UW_DialogueLine::NativeOnInitialized()
{
    Super::NativeOnInitialized();
}

void UW_DialogueLine::ProceedDialogue()
{
    if (DialogueWindow && PlayerNode)
    {            

        if (const auto ProceedDialogue = DialogueWindow->ProceedDialogue)
        {

            ProceedDialogue->ProceedDialogue(PlayerNode);
        }
    }
}

void UW_DialogueLine::SetDialogueIcon(UTexture2D* Icon)
{
    PlayerDialogueIcon->SetBrushFromTexture(Icon);
}

void UW_DialogueLine::SetDialogueText(const FText& Text)
{
    PlayerDialogueText->SetText(Text);
}