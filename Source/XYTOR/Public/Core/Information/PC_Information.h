// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "W_InformationBase.h"
#include "GameFramework/PlayerController.h"
#include "Interfaces/IPC_Information.h"
#include "PC_Information.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class XYTOR_API APC_Information : public APlayerController, public IIPC_Information
{
protected:

    UPROPERTY(EditDefaultsOnly, Category="Widgets")
    TSubclassOf<UW_InformationBase> InformationWidgetClass;
    
   // UW_InformationBase* InformationWidget = nullptr;
public:

    virtual void BeginPlay() override;
    
    UFUNCTION(BlueprintCallable)
    virtual void DisplayInformation_Implementation() const override;

private:
    GENERATED_BODY()

};
