// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AC_ProceedDialogue.h"
#include "DialogueGraph/DialogueGraph.h"
#include "AC_Dialogues.generated.h"

class APS_Tokens;
class UNPCDialogueGraphNode;
class UPlayerDialogueGraphNode;
struct FGameplayTagContainer;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBeginDialogueSignature, const UNPCDialogueGraphNode*, NPCNode, const TArray<UPlayerDialogueGraphNode*>, PlayerDialogueNodes);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnProceedDialogueSignature, const UNPCDialogueGraphNode*, NPCNode, const TArray<UPlayerDialogueGraphNode*>, PlayerDialogueNodes);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndDialogueSignature);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class XYTOR_API UAC_Dialogues : public UAC_ProceedDialogue
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UAC_Dialogues();

    UPROPERTY(BlueprintAssignable, VisibleAnywhere)
    FOnBeginDialogueSignature OnBeginDialogueDelegate;
    
    UPROPERTY(BlueprintAssignable, VisibleAnywhere)
    FOnProceedDialogueSignature OnProceedDialogueDelegate;
    
    UPROPERTY(BlueprintAssignable, VisibleAnywhere)
    FOnEndDialogueSignature OnEndDialogueDelegate;

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogues System")
    UDialogueGraph* DialogueGraph;
    
    UPROPERTY(BlueprintReadOnly,Category = "Dialogues System")
    UNPCDialogueGraphNode* CurrentNPCNode;

    UPROPERTY(BlueprintReadOnly, Category = "Dialogues System")
    TArray<UPlayerDialogueGraphNode*> CurrentPlayerDialogueNodes;

    bool InitializeTokens();

public:
    UFUNCTION(BlueprintCallable)
    void BeginDialogue(UDialogueGraph* Dialogue);

    virtual void ProceedDialogue(const UPlayerDialogueGraphNode* Node) override;
    
    UFUNCTION(BlueprintCallable)
    void EndDialogue();

private:
    UPROPERTY()
    APS_Tokens* Tokens;
};