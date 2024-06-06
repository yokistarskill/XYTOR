// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PC_Dialogues.h"
#include "GameFramework/PlayerController.h"
#include "Widgets/W_QuestListBase.h"
#include "Core/WidgetManager/HUD_WidgetManager.h"
#include "PC_Quests.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API APC_Quests : public APC_Dialogues
{
    GENERATED_BODY()
protected:
    UPROPERTY()
    UW_QuestListBase* QuestListWidget;
    UPROPERTY(EditDefaultsOnly, Category="Widgets")
    TSubclassOf<UW_QuestListBase> QuestListWidgetClass;
public:
    virtual void SetupInputComponent() override;
    
    virtual void BeginPlay() override;
    UFUNCTION(BlueprintCallable)
    void DisplayQuests() const;

private:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* QuestsAction;

    void QuestsActionHandler();
};
