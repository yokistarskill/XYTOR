// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IPC_Energy.generated.h"


UINTERFACE(BlueprintType)
class UIPC_Energy : public UInterface
{
    GENERATED_BODY()
};

class IIPC_Energy
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ProcessDamage(float Damage);    
};
