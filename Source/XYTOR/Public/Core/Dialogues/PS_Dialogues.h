// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Inventory/PS_Inventory.h"
#include "Core/Dialogues/AC_Dialogues.h"
#include "PS_Dialogues.generated.h"

UCLASS()
class XYTOR_API APS_Dialogues : public APS_Inventory
{
    GENERATED_BODY()

protected:
    /** Component for dialogue managing. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UAC_Dialogues* DialogueComponent;

public:
    APS_Dialogues();
    
    /**
     * @return pointer to DialogueComponent.
     */
    UFUNCTION(BlueprintCallable)
    UAC_Dialogues* GetDialogue() const;
};