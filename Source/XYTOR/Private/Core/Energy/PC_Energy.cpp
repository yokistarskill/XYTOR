// XYTOR. All Rights Reserved.


#include "Core/Energy/PC_Energy.h"

void APC_Energy::BeginPlay()
{
    Super::BeginPlay();
    if(!EnergyWidgetClass)
    {
        UE_LOG(LogTemp, Error, TEXT("No widget class in PC_Energy"));
    }

    // todo Add background widget to HUD 
}

void APC_Energy::ProcessDamage_Implementation()
{
    // todo Add damage in widget
}
