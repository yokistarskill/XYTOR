// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
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
    UFUNCTION(BlueprintCallable)
    virtual void HideInformation_Implementation() const override;

    UFUNCTION(BlueprintCallable)
    virtual void DisplayInformation_Implementation() const override;

private:
    GENERATED_BODY()

};
