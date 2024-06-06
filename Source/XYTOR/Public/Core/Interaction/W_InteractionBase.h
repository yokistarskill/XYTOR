// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/WidgetManager/Widgets/W_BackgroundBase.h"
#include "W_InteractionBase.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API UW_InteractionBase : public UW_BackgroundBase
{
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void UpdateMessage(const FText &NewMessage);
    
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void CleanMessage();
};
