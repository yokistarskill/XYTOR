// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "PC_Base.generated.h"

UCLASS()
class XYTOR_API APC_Base : public APlayerController
{
    GENERATED_BODY()

public:
    APC_Base();
    
protected:
    /** MappingContext */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    class UInputMappingContext* DefaultMappingContext;

    /** Move Input Action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    class UInputAction* MoveAction;

    virtual void BeginPlay() override;

    virtual void SetupInputComponent() override;

    void Move(const FInputActionValue& Value);
};