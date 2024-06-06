// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "W_InformationBase.h"
#include "Core/Player/PC_Base.h"
#include "Interfaces/IPC_Information.h"
#include "PC_Information.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class XYTOR_API APC_Information : public APC_Base, public IIPC_Information
{
    GENERATED_BODY()
protected:
    UPROPERTY(EditDefaultsOnly, Category="Widgets")
    TSubclassOf<UW_InformationBase> InformationWidgetClass;


public:
    virtual void BeginPlay() override;
    UFUNCTION(BlueprintCallable)
    virtual void DisplayInformation_Implementation() const override;

    virtual void SetupInputComponent() override;
private:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* InformationAction;

    void InformationActionHandler();
};
