// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "W_InteractionBase.h"
#include "Core/QuestSystem/PC_Quests.h"

#include "GameFramework/PlayerController.h"
#include "PC_Interaction.generated.h"

class UAC_Interact;
/**
 * 
 */
UCLASS()
class XYTOR_API APC_Interaction : public APC_Quests
{
    GENERATED_BODY()
private:
    // UPROPERTY()
    // TArray<AActor*> ObjectsToInteract;
    UPROPERTY()
    TArray<UAC_Interact*> ComponentsToInteract;
    int32 CurrentObjectIndex=-1;
    
protected:
    UPROPERTY(EditDefaultsOnly, Category="Widgets")
    TSubclassOf<UW_InteractionBase> InteractionWidgetClass;
    UPROPERTY()
    UW_InteractionBase* InteractionBase;

    virtual void BeginPlay() override;
    
    UFUNCTION(BlueprintCallable)
    void Interact();
    
public:
    virtual void SetupInputComponent() override;
    virtual void Tick(float DeltaSeconds) override;
    UFUNCTION(BlueprintCallable, Category="Interacting System")
    bool AddActor(AActor* NewActor);
    UFUNCTION(BlueprintCallable, Category="Interacting System")
    bool RemoveActor(AActor* TargetActor);

    static bool CanInteract(const AActor* TargetActor);
    static FText GetInteractText(const AActor* TargetActor);

private:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* InteractAction;
};
