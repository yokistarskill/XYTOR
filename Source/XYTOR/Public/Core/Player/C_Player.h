// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "C_Energy.h"
#include "C_Player.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class XYTOR_API AC_Player : public AC_Energy
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    AC_Player();
    
private:
    /** Top down camera */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    UCameraComponent* TopDownCameraComponent;

    /** Camera boom positioning the camera above the character */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    USpringArmComponent* CameraBoom;

public:
    // Called every frame.
    virtual void Tick(float DeltaSeconds) override;

    /** Returns TopDownCameraComponent subobject **/
    FORCEINLINE UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
    /** Returns CameraBoom subobject **/
    FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
};