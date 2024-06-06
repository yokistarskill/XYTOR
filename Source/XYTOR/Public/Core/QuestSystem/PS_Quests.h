// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "E_SubquestType.h"
#include "PS_Dialogues.h"
#include "./Objects/Quest.h"
#include "PS_Quests.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestChanged, UQuest*, QuestObject);

/**
 * 
 */
UCLASS()
class XYTOR_API APS_Quests : public APS_Dialogues
{
    GENERATED_BODY()

protected:
    UPROPERTY(VisibleAnywhere, Category = "Quest System")
    TArray<UQuest*> AvailableQuests;
    
    UPROPERTY(VisibleAnywhere, Category = "Quest System")
    TArray<UQuest*> CompletedQuests;

    void FinishQuest(uint8 Index);
public:
    UPROPERTY(BlueprintAssignable, VisibleAnywhere)
    FOnQuestChanged OnQuestChanged;
    
    void UpdateQuests(EE_SubquestType Type);
    UFUNCTION(BlueprintCallable)
    void AddQuest(FName QuestName);

    void TokensChanged();
    UFUNCTION()
    void ItemsChanged(UItem* Item, int32 Count);

    virtual void BeginPlay() override;

};
