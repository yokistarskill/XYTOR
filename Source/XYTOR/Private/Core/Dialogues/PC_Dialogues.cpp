// XYTOR. All Rights Reserved.


#include "Core/Dialogues/PC_Dialogues.h"
#include "AC_Dialogues.h"
#include "PS_Dialogues.h"
#include "Core/Dialogues/W_DialogueWindow.h"
#include "Core/WidgetManager/HUD_WidgetManager.h"
#include "DialogueGraph/PlayerDialogueGraphNode.h"

APC_Dialogues::APC_Dialogues()
{
}

void APC_Dialogues::BeginPlay()
{
    Super::BeginPlay();
    
    if(InitializeWidget())
    {

        const auto DialogueComponent = GetPlayerState<APS_Dialogues>()->GetDialogue();

        if (!DialogueComponent) return;
        
        DialogueWindowWidget->InitializeWidget(DialogueComponent);

        DialogueComponent->OnBeginDialogueDelegate.AddDynamic(this, &APC_Dialogues::OnBeginDialogue);
        DialogueComponent->OnBeginDialogueDelegate.AddDynamic(DialogueWindowWidget, &UW_DialogueWindow::OnUpdateDialogue);
        DialogueComponent->OnProceedDialogueDelegate.AddDynamic(DialogueWindowWidget, &UW_DialogueWindow::OnUpdateDialogue);
        DialogueComponent->OnEndDialogueDelegate.AddUniqueDynamic(this, &APC_Dialogues::OnEndDialogue);
    }
}

void APC_Dialogues::OnBeginDialogue(const UNPCDialogueGraphNode* NPCNode, const TArray<UPlayerDialogueGraphNode*> PlayerDialogueNodes)
{

    AHUD_WidgetManager* HUD = Cast<AHUD_WidgetManager>(GetHUD());

    if (!HUD)
    {
        UE_LOG(LogTemp, Error, TEXT("HUD doesn't exist."));
    }
    
    // if widget created and exists toggle it
    if (DialogueWindowWidget)
    {
        HUD->ToggleNormalWidgetByClass(DialogueWindowWidgetClass);
    }

}

void APC_Dialogues::OnEndDialogue()
{
    AHUD_WidgetManager* HUD = Cast<AHUD_WidgetManager>(GetHUD());

    if (!HUD)
    {
        UE_LOG(LogTemp, Error, TEXT("HUD doesn't exist."));
        return;
    }

    HUD->HideCurrentNormalWidget();
}

bool APC_Dialogues::InitializeWidget()
{
    if(!DialogueWindowWidgetClass)
    {
        UE_LOG(LogTemp, Error, TEXT("No widget class in PC_Dialogues."));
        return false;
    }

    AHUD_WidgetManager* HUD = Cast<AHUD_WidgetManager>(GetHUD());

    if (!HUD)
    {
        UE_LOG(LogTemp, Error, TEXT("HUD doesn't exist."));
        return false;
    }
    // if widget is nullptr get it from HUD
    if (!DialogueWindowWidget)
    {
        DialogueWindowWidget = Cast<UW_DialogueWindow>(HUD->GetWidgetByClass(DialogueWindowWidgetClass));
    }

    // if widget doesn't exist in HUD - add widget
    if (!DialogueWindowWidget)
    {
        DialogueWindowWidget = Cast<UW_DialogueWindow>(HUD->AddWidgetByClass(DialogueWindowWidgetClass));
    }
    
    return true;
}