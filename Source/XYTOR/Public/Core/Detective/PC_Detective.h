// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AC_ExploringHandler.h"
#include "W_TipsBase.h"
#include "Core/Interaction/PC_Interaction.h"
#include "PC_Detective.generated.h"

class UW_EvidenceBase;
/**
 * 
 */
UCLASS()
class XYTOR_API APC_Detective : public APC_Interaction
{
protected:
    virtual void BeginPlay() override;

private:
    GENERATED_BODY()

protected:
    UPROPERTY(EditAnywhere)
    TSubclassOf<UW_TipsBase> TipsWidgetClass;
    UPROPERTY()
    UW_TipsBase* TipsWidget;
    
    UPROPERTY(EditAnywhere, Category="Widgets")
    TSubclassOf<UW_EvidenceBase> EvidenceWidgetClass;
    UPROPERTY()
    TArray<UAC_ExploringHandler*> DetectiveComponents;
    UPROPERTY(BlueprintReadOnly)
    bool bShouldDetect = false;

    void DetectAll() const;
    void UnDetectAll() const;
public:
    void DisplayTip(const FText& Tip) const;
    
    UFUNCTION(BlueprintCallable)
    bool SetShouldDetect(bool Value);
    UFUNCTION(BlueprintCallable)
    bool ToggleShouldDetect();
    UFUNCTION(BlueprintCallable)
    bool DetectEvidence(AActor* Actor);
    UFUNCTION(BlueprintCallable)
    bool UnDetectEvidence(AActor* Actor);

};
