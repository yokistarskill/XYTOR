// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/WidgetManager/W_Base.h"
#include "W_DialogueWindow.h"
#include "DialogueGraph/PlayerDialogueGraphNode.h"
#include "W_DialogueLine.generated.h"

class UImage;
class UButton;
class UTextBlock;
class UPlayerDialogueGraphNode;

UCLASS()
class XYTOR_API UW_DialogueLine : public UW_Base
{
    GENERATED_BODY()

protected:

    UPROPERTY(meta = (BindWidget))
    UImage* PlayerDialogueIcon;
    
    UPROPERTY(meta = (BindWidget))
    UButton* PlayerDialogueButton;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* PlayerDialogueText;
    
    virtual void NativeOnInitialized() override;
    
public:
    UFUNCTION(BlueprintCallable)
    void ProceedDialogue();
    
    void SetDialogueWindow(UW_DialogueWindow* DialogueWindowWidget) { DialogueWindow = DialogueWindowWidget; };
    void SetPlayerNode(UPlayerDialogueGraphNode* Node) { PlayerNode = Node; }
    
    void SetDialogueIcon(UTexture2D* Icon);
    void SetDialogueText(const FText& Text);
    
private:
    UPROPERTY()
    UPlayerDialogueGraphNode* PlayerNode;

    UPROPERTY()
    UW_DialogueWindow* DialogueWindow;
};