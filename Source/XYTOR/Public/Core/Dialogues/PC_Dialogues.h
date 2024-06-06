// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Core/Inventory/PC_Inventory.h"
#include "PC_Dialogues.generated.h"

class UAC_DialogueHandler;
class UW_DialogueWindow;

UCLASS()
class XYTOR_API APC_Dialogues : public APC_Inventory
{
    GENERATED_BODY()

public:
    APC_Dialogues();
    
protected:
    UPROPERTY(EditDefaultsOnly, Category = "Widgets")
    TSubclassOf<UW_DialogueWindow> DialogueWindowWidgetClass;

    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable)
    void OnBeginDialogue(const UNPCDialogueGraphNode* NPCNode, const TArray<UPlayerDialogueGraphNode*> PlayerDialogueNodes);
    
    UFUNCTION(BlueprintCallable)
    void OnEndDialogue();
    
private:
    UPROPERTY()
    UW_DialogueWindow* DialogueWindowWidget = nullptr;

    bool InitializeWidget();
};