// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/WidgetManager/W_Base.h"
#include "W_EvidenceBase.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API UW_EvidenceBase : public UW_Base
{
	GENERATED_BODY()

protected:
    UPROPERTY(BlueprintReadOnly)
    FText LongInfo;
    UPROPERTY(BlueprintReadOnly)
    FText ShortInfo;

    UPROPERTY(BlueprintReadWrite)
    bool bLoaded = false; 
public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void InitInfo(const FText& NewLongInfo, const FText& NewShortInfo);
    
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void DisplayShortInfo();
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void DisplayLongInfo();
};


