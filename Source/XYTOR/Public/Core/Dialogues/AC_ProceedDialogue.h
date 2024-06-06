// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_ProceedDialogue.generated.h"

class UPlayerDialogueGraphNode;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class XYTOR_API UAC_ProceedDialogue : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UAC_ProceedDialogue();
    
    virtual void BeginPlay() override;
    UFUNCTION(BlueprintCallable)
    virtual void ProceedDialogue(const UPlayerDialogueGraphNode* Node);
};