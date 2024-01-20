// XYTOR. All Rights Reserved.


#include "..\..\..\Public\Core\Energy\W_EnergyBase.h"

float UW_EnergyBase::GetRatio() const
{
    return CurrentHealth/MaximumHealth;
}

void UW_EnergyBase::AddDamage(float Damage)
{
    UE_LOG(LogTemp, Warning, TEXT("Damage added to widget %.3f"), Damage);
    CurrentHealth = FMath::Clamp(CurrentHealth-Damage, 0, MaximumHealth);
    UpdateHealthBar();
}

void UW_EnergyBase::SetMaximum(float MaxHP)
{
    UE_LOG(LogTemp, Warning, TEXT("New maximum %.3f"), MaxHP);
    CurrentHealth = MaximumHealth = MaxHP;
}
