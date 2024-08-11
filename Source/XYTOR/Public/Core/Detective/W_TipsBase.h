// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/WidgetManager/Widgets/W_BackgroundBase.h"
#include "W_TipsBase.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API UW_TipsBase : public UW_BackgroundBase
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void DisplayTip(const FText& Tip) const;
    
};
