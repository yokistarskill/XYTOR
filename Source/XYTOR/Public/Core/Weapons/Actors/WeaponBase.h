// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Inventory/Objects/SceneItem.h"
#include "WeaponBase.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API AWeaponBase : public ASceneItem
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
    UAnimMontage* ReloadAnimMontage;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
    UAnimMontage* EquipAnimMontage;
};