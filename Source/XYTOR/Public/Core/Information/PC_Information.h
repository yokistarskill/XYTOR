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
public:

protected:
    UPROPERTY(BlueprintReadWrite, Category="PC_Information")
    TSubclassOf<UW_InformationBase> WidgetClass;
public:

    UFUNCTION(BlueprintCallable)
    virtual void DisplayInformation_Implementation() const override;

private:
    GENERATED_BODY()

};
