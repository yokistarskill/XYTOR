// XYTOR. All Rights Reserved.


#include "Core/QuestSystem/PS_Quests.h"

#include "Core/QuestSystem/Structures/S_Quest.h"

void APS_Quests::FinishQuest(uint8 Index)
{
    CompletedQuests.Push(AvailableQuests[Index]);
    AvailableQuests.RemoveAt(Index);
}

void APS_Quests::UpdateQuests(EE_SubquestType Type)
{
    for (uint8 i=0; i<AvailableQuests.Num(); i++)
        if (AvailableQuests[i]->Update(Type, this))
        {
            OnQuestChanged.Broadcast(AvailableQuests[i]);
            if (AvailableQuests[i]->IsCompleted())
                FinishQuest(i--); // Decrement is only for TArray
        }
}

void APS_Quests::AddQuest(FName QuestName)
{
    for (const UQuest* Quest : AvailableQuests)
        if (Quest->GetNameInTable() == QuestName)
            return;
    for (const UQuest* Quest : CompletedQuests)
        if (Quest->GetNameInTable() == QuestName)
            return;

    if (UQuest* Quest = NewObject<UQuest>(UQuest::StaticClass()))
    {
        Quest->Init(QuestName);
        AvailableQuests.Push(Quest);
        OnQuestChanged.Broadcast(Quest);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No such quest"));
    }
}

void APS_Quests::TokensChanged()
{
    UpdateQuests(EE_SubquestType::Token);
}

void APS_Quests::ItemsChanged(UItem* Item, int32 Count)
{
    UpdateQuests(EE_SubquestType::Item);
}

void APS_Quests::BeginPlay()
{
    Super::BeginPlay();
    GetInventory()->OnInventoryChanged.AddUniqueDynamic(this, &APS_Quests::ItemsChanged);
}
