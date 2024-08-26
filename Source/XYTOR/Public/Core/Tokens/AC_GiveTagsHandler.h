// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Core/Interaction/AC_InteractionHandler.h"
#include "AC_GiveTagsHandler.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class XYTOR_API UAC_GiveTagsHandler : public UAC_InteractionHandler
{
protected:
    UPROPERTY(EditAnywhere)
    FGameplayTagContainer TagsToGive;
public:
    virtual void Interact(AActor* InteractingActor) override;
    
private:
    GENERATED_BODY()

};
