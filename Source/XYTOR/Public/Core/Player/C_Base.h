// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "C_Base.generated.h"

UCLASS()
class XYTOR_API AC_Base : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    AC_Base();

    // Called every frame.
    virtual void Tick(float DeltaSeconds) override;
};