// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "W_Base.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API UW_Base : public UUserWidget
{
	GENERATED_BODY()
protected:
    UPROPERTY(EditDefaultsOnly)
    bool bIsBackground = false;
public:
    UFUNCTION(BlueprintPure)
    bool IsBackgroundWidget() const;

    static bool IsBackgroundWidgetByClass(TSubclassOf<UW_Base> WidgetClass);
};
