// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_Interact.generated.h"


class UAC_InteractionHandler;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class XYTOR_API UAC_Interact : public UActorComponent
{
    GENERATED_BODY()
    
protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interacting System")
    FText InteractingText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interacting System")
    TArray<UAC_InteractionHandler*> ComponentsToInteract;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interacting System")
    bool bCanInteract = true;
    
public:
    UAC_Interact();

    void SetHandlers(TArray<TSubclassOf<UAC_InteractionHandler>> Handlers);
    void SetCanInteract(bool NewFlag);
    void SetInteractingText(const FText& NewText);
    
    UFUNCTION(BlueprintCallable)
    TArray<UAC_InteractionHandler*> GetHandlers() const;
    
    UFUNCTION(BlueprintCallable)
    FText GetInteractingText() const;
    
    UFUNCTION(BlueprintCallable)
    bool CanInteract() const;
};