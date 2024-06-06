// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/WidgetManager/Widgets/W_NormalBase.h"
#include "DialogueGraph/PlayerDialogueGraphNode.h"
#include "W_DialogueWindow.generated.h"

class IITokens;
class UAC_ProceedDialogue;
class UVerticalBox;
class UW_DialogueLine;
class UImage;
class UTextBlock;

UCLASS()
class XYTOR_API UW_DialogueWindow : public UW_NormalBase
{
    GENERATED_BODY()
public:
    UPROPERTY()
    UAC_ProceedDialogue* ProceedDialogue;
    
protected:
    UPROPERTY(meta = (BindWidget))
    UVerticalBox* PlayerDialogueLineContainer;

    UPROPERTY(meta = (BindWidget))
    UImage* NPCDialogueIcon;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* NPCDialogueText;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> DialogueLineClass;
    
    virtual void NativeOnInitialized() override;

public:
    void InitializeWidget(UAC_ProceedDialogue* DialogueHandler);
    
    UFUNCTION(BlueprintCallable)
    void OnUpdateDialogue(const UNPCDialogueGraphNode* NPCNode, const TArray<UPlayerDialogueGraphNode*> PlayerDialogueNodes);
};