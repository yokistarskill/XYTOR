// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IPC_Energy.h"
#include "W_EnergyBase.h"
#include "Core/Information/PC_Information.h"
#include "PC_Energy.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API APC_Energy : public APC_Information, public IIPC_Energy
{
public:
    virtual void BeginPlay() override;

private:
    GENERATED_BODY()

    UW_EnergyBase* EnergyWidget = nullptr;

protected:
    UPROPERTY(EditDefaultsOnly, Category="Widgets")
    TSubclassOf<UW_EnergyBase> EnergyWidgetClass;
public:
    UFUNCTION(BlueprintCallable)
    virtual void ProcessDamage_Implementation(float Damage) override;
    
};
