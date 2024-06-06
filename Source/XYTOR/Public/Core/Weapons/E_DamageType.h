// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "E_DamageType.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EE_DamageType : uint8 {
    Physical   UMETA(DisplayName="Physical"),
    Fire       UMETA(DisplayName="Fire")
};