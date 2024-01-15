// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IPC_Information.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UIPC_Information : public UInterface
{
    GENERATED_BODY()
};

class IIPC_Information
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void DisplayInformation() const;
};
