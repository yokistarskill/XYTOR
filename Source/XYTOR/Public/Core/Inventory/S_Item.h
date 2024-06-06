// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "E_ItemType.h"
#include "Engine/DataTable.h"
#include "Objects/SceneItem.h"
#include "S_Item.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FS_Item : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="S_Item")
    FText Title;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="S_Item")
    FText ToolTip;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="S_Item")
    EE_ItemType ItemType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="S_Item")
    UTexture2D* Icon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="S_Item")
    TSubclassOf<ASceneItem> ItemActorClass;
};
