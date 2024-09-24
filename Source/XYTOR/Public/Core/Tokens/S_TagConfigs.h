// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "S_TagConfigs.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FS_TagConfigs
{
    GENERATED_USTRUCT_BODY()
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tag configs")
    FGameplayTagContainer PositiveTags;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tag configs")
    FGameplayTagContainer NegativeTags;
};