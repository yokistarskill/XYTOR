// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IPS_Information.generated.h"


UINTERFACE(MinimalAPI, Blueprintable)
class UIPS_Information: public UInterface
{
    GENERATED_BODY()
};

class IIPS_Information
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<FName> GetEntities() const;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AddEntity(FName EntityName);
};