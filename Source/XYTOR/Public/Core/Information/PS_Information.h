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
protected:

private:
    GENERATED_BODY()

protected:
    UPROPERTY(BlueprintReadWrite)
    TArray<FName> OpenedEntities;
    
public:
    virtual void BeginPlay() override;
    UFUNCTION(BlueprintCallable)
    virtual void AddEntity_Implementation(FName EntityName) override;
    UFUNCTION(BlueprintCallable)
    virtual TArray<FName> GetEntities_Implementation() const override;

};
