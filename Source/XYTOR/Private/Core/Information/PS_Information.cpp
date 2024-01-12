// XYTOR. All Rights Reserved.


#include "Core/Information/PS_Information.h"

#include "Core/WidgetManager/HUD_WidgetManager.h"

void APS_Information::AddEntity_Implementation(FName EntityName)
{
    OpenedEntities.Push(EntityName);
}

void APS_Information::DisplayInformation_Implementation() const
{
    AHUD_WidgetManager* HUD = Cast<AHUD_WidgetManager>(GetPlayerController()->GetHUD());
    check(HUD);
    UW_InformationBase* Widget = Cast<UW_InformationBase>(HUD->GetWidgetByClass(WidgetClass));
    check(Widget);
    Widget->SetEntities(OpenedEntities);
    HUD->ShowWidgetByClass(WidgetClass);
}

TArray<FName> APS_Information::GetEntities_Implementation() const
{
    return OpenedEntities;
}

void APS_Information::HideInformation_Implementation() const
{
    AHUD_WidgetManager* HUD = Cast<AHUD_WidgetManager>(GetPlayerController()->GetHUD());
    check(HUD);
    // todo Information Hiding
}
