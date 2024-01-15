// XYTOR. All Rights Reserved.


#include "Core/Information/PC_Information.h"
#include "Core/Information/Interfaces/IPS_Information.h"
#include "Core/WidgetManager/HUD_WidgetManager.h"
#include "GameFramework/PlayerState.h"

class APS_Information;

void APC_Information::BeginPlay()
{
    if(!WidgetClass)
    {
        UE_LOG(LogTemp, Error, TEXT("No widget class in PC_Information"));
    }
}

void APC_Information::DisplayInformation_Implementation() const
{
    APlayerState* PS = GetPlayerState<APlayerState>();
    check(PS->Implements<UIPS_Information>());

    AHUD_WidgetManager* HUD = Cast<AHUD_WidgetManager>(GetHUD());
    check(HUD);

    if (UUserWidget* Widget = HUD->GetWidgetByClass(WidgetClass))
    {
        UW_InformationBase* InfoWidget = Cast<UW_InformationBase>(Widget);
        InfoWidget->SetEntities(IIPS_Information::Execute_GetEntities(PS));

        HUD->ShowWidgetByClass(WidgetClass);
    }
}
