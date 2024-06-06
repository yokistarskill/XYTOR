// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AC_InteractionHandler.h"
#include "DialogueGraph/DialogueGraph.h"
#include "AC_DialogueHandler.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class XYTOR_API UAC_DialogueHandler : public UAC_InteractionHandler
{
    GENERATED_BODY()
    
    //FTestBool Test;
public:
    // Sets default values for this component's properties
    UAC_DialogueHandler();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogues System")
    UDialogueGraph* DialogueGraph;

public:
    UFUNCTION(Blueprintable)
    UDialogueGraph* GetDialogue() const { return DialogueGraph; }
    
    UFUNCTION(Blueprintable)
    void SetDialogue(UDialogueGraph* Dialogue) { DialogueGraph = Dialogue; }
    
    virtual void Interact(AActor* InteractingActor) override;
};
