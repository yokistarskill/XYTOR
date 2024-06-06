// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Core/Weapons/Data/S_Ammo.h"
#include "Ammo.generated.h"

/**
 * Base class for Ammo. It provides compatibility with inventory system. 
 */
UCLASS(BlueprintType)
class XYTOR_API UAmmo : public UItem
{
    GENERATED_BODY()

protected:
    FS_Ammo* AmmoData;

    virtual bool AdditionalInit(FName ItemName) override;
};