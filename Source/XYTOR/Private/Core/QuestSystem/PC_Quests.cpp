// XYTOR. All Rights Reserved.


#include "Core/QuestSystem/PC_Quests.h"

#include "EnhancedInputComponent.h"
#include "Core/QuestSystem/PS_Quests.h"


class AHUD_WidgetManager;

void APC_Quests::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
    {
        EnhancedInputComponent->BindAction(QuestsAction, ETriggerEvent::Started, this, &APC_Quests::QuestsActionHandler);
    }
}

void APC_Quests::BeginPlay()
{
    Super::BeginPlay();
    
    INIT_WIDGET_IN_BEGIN_PLAY(PC_Quests, UW_QuestListBase, QuestListWidgetClass, QuestListWidget);
    if (APS_Quests* PS_Quests = Cast<APS_Quests>(GetPlayerState<APS_Quests>()))
    {
        PS_Quests->OnQuestChanged.AddUniqueDynamic(QuestListWidget, &UW_QuestListBase::UpdateQuest);
    }
}

void APC_Quests::DisplayQuests() const
{
    AHUD_WidgetManager* HUD = Cast<AHUD_WidgetManager> (GetHUD());
    if(HUD)
    {
        HUD->ToggleNormalWidgetByClass(QuestListWidgetClass);
    }
}

void APC_Quests::QuestsActionHandler()
{
    DisplayQuests();
}
