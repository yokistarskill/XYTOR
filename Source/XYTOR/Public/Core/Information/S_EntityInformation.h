// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "S_EntityInformation.generated.h"

USTRUCT(BlueprintType)
struct FS_EntityInformation : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Entity information")
    FText Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Entity information")
    FText Description;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Entity information")
    FText Signs;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Entity information")
    FText Victims;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Entity information")
    FText Habitancy;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Entity information")
    FText Manifestation;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Entity information")
    FText Fighting;
};