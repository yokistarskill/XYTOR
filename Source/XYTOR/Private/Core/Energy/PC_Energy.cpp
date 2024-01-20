// XYTOR. All Rights Reserved.


#include "Core/Energy/PC_Energy.h"

#include "Core/Energy/C_Energy.h"
#include "Core/WidgetManager/HUD_WidgetManager.h"

void APC_Energy::BeginPlay()
{
    Super::BeginPlay();
    if(!EnergyWidgetClass)
    {
        UE_LOG(LogTemp, Error, TEXT("No widget class in PC_Energy"));
    }

    AHUD_WidgetManager* HUD = Cast<AHUD_WidgetManager>(GetHUD());
    EnergyWidget = Cast<UW_EnergyBase>(HUD->AddWidgetByClass(EnergyWidgetClass));
    if (!EnergyWidget)
    {
        UE_LOG(LogTemp, Error, TEXT("EnergyWidgetClass was not created: %s"), *EnergyWidgetClass->GetName());
    }
    
    if (AC_Energy* Char = Cast<AC_Energy>(GetCharacter()))
    {
        UE_LOG(LogTemp, Warning, TEXT("Findet maximum is %.3f"), Char->GetMaximumHealth());
        EnergyWidget->SetMaximum(Char->GetMaximumHealth());
        Char->OnDamageTaken.AddUniqueDynamic(EnergyWidget, &UW_EnergyBase::AddDamage);
    }
}

void APC_Energy::ProcessDamage_Implementation(float Damage)
{
}
