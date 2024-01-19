// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Core/WidgetManager/Widgets/W_BackgroundBase.h"
#include "W_Energy.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API UW_Energy : public UW_BackgroundBase
{
	GENERATED_BODY()

protected:
    UPROPERTY(BlueprintReadWrite, Category="Health")
    float MaximumHealth;
    UPROPERTY(BlueprintReadWrite, Category="Health")
    float CurrentHealth;

    float GetRatio() const;
public:
	void AddDamage(float Value);
    void SetMaximum(float Value);
};
