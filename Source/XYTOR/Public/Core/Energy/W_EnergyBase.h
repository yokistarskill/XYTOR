// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Core/WidgetManager/Widgets/W_BackgroundBase.h"
#include "W_EnergyBase.generated.h"


/**
 * 
 */
UCLASS()
class XYTOR_API UW_EnergyBase : public UW_BackgroundBase
{
	GENERATED_BODY()

protected:
    UPROPERTY(BlueprintReadWrite, Category="Health")
    float MaximumHealth;
    UPROPERTY(BlueprintReadWrite, Category="Health")
    float CurrentHealth;

    UFUNCTION(BlueprintPure, Category="Heapth")
    float GetRatio() const;

    UFUNCTION(BlueprintImplementableEvent, Category="Heapth")
    void UpdateHealthBar() const;
public:

    UFUNCTION(BlueprintCallable)
	void AddDamage(float Value);
    UFUNCTION(BlueprintCallable)
    void SetMaximum(float Value);
};
