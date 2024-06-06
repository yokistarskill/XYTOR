// XYTOR. All Rights Reserved.


#include "Core/Energy/PC_Energy.h"

#include "Core/Energy/C_Energy.h"
#include "Core/WidgetManager/HUD_WidgetManager.h"

void APC_Energy::BeginPlay()
{
    Super::BeginPlay();

    INIT_WIDGET_IN_BEGIN_PLAY(APC_Energy, UW_EnergyBase, EnergyWidgetClass, EnergyWidget);
    
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
