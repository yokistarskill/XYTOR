// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AC_InteractionHandler.h"
#include "AC_PickUpHandler.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class XYTOR_API UAC_PickUpHandler : public UAC_InteractionHandler
{
    GENERATED_BODY()

public:
    UAC_PickUpHandler();
    
protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
    TMap<FName, int32> Items;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
    bool bDestroyAfterPickUp = true;
    
public:
    virtual void Interact(AActor* InteractingActor) override;

    void SetItem(FName Name, int32 Count);
};
