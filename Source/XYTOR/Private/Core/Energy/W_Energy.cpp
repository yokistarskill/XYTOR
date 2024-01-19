// XYTOR. All Rights Reserved.


#include "Core/Energy/W_Energy.h"

float UW_Energy::GetRatio() const
{
    return CurrentHealth/MaximumHealth;
}

void UW_Energy::AddDamage(float Value)
{
    CurrentHealth = FMath::Clamp(CurrentHealth-Value, 0, MaximumHealth);
}

void UW_Energy::SetMaximum(float Value)
{
    MaximumHealth = Value;
}
