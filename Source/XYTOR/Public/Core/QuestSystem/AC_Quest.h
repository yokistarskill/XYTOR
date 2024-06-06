// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AC_InteractionHandler.h"
#include "AC_Quest.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class XYTOR_API UAC_Quest : public UAC_InteractionHandler
{
    GENERATED_BODY()

public:
    UAC_Quest();
    
protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quests")
    FName Quest;
    
public:
    virtual void Interact(AActor* InteractingActor) override;
};