// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Interaction/AC_InteractionHandler.h"
#include "AC_ShowTipHandler.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class XYTOR_API UAC_ShowTipHandler : public UAC_InteractionHandler
{
    GENERATED_BODY()
protected:
    UPROPERTY(EditAnywhere)
    FText TipText;
public:
    virtual void Interact(AActor* InteractingActor) override;

};
