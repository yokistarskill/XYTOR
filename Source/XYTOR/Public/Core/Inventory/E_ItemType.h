// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "E_ItemType.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EE_ItemType : uint8 {
    Item       UMETA(DisplayName="Item"),
    Weapon     UMETA(DisplayName="Weapon"),
    Ammo       UMETA(DisplayName="Ammo")
};