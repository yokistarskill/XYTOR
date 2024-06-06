// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Core/Weapons/E_DamageType.h"
#include "S_Ammo.generated.h"
/**
 * 
 */
USTRUCT(BlueprintType)
struct FS_Ammo : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
    float AdditionalDamage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
    EE_DamageType DamageType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    UTexture2D* AmmoIcon;
};