// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_InteractionHandler.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class XYTOR_API UAC_InteractionHandler : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UAC_InteractionHandler();

    UFUNCTION(BlueprintCallable)
    virtual void Interact(AActor* InteractingActor);
};