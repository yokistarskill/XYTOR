// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "W_InformationBase.h"
#include "GameFramework/PlayerState.h"
#include "Interfaces/IPS_Information.h"
#include "PS_Information.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API APS_Information : public APlayerState, public IIPS_Information

{
public:

protected:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UW_InformationBase> WidgetClass;
    UPROPERTY(BlueprintReadWrite)
    TArray<FName> OpenedEntities;
    
public:
    UFUNCTION(BlueprintCallable)
    virtual void AddEntity_Implementation(FName EntityName) override;
    UFUNCTION(BlueprintCallable)
    virtual void DisplayInformation_Implementation() const override;
    UFUNCTION(BlueprintCallable)
    virtual TArray<FName> GetEntities_Implementation() const override;
    UFUNCTION(BlueprintCallable)
    virtual void HideInformation_Implementation() const override;

private:
    GENERATED_BODY()

};
