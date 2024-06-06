// XYTOR. All Rights Reserved.


#include "Core/QuestSystem/Objects/Quest.h"

#include "Core/QuestSystem/PS_Quests.h"
#include "Core/ExtraTools.h"
#include "Core/QuestSystem/Structures/S_Quest.h"

bool UQuest::Init(FName QuestName)
{
    const FString QuestTablePath = "/Script/Engine.DataTable'/Game/XYTOR/DataTables/QuestSystem/DT_Quests.DT_Quests'";
    if (const FS_Quest* QuestData = ExtraTools::GetStructureFromTable<FS_Quest>(QuestTablePath, QuestName))
    {
        NameInTable = QuestName;
        Title = QuestData->Title;
        Description = QuestData->Description;
        for (auto SubquestInfo: QuestData->Subquests)
        {
            Subquests.Push(USubquest::MakeSubquest(SubquestInfo, this));
        }
        return true;
    }
    return false;
}

UQuest::UQuest(FName QuestName)
{
    Init(QuestName);
}

bool UQuest::IsCompleted() const
{
    return CurrentSubquest>=Subquests.Num();
}

bool UQuest::Update(EE_SubquestType Type, const APS_Quests* PlayerState)
{
    if (Subquests[CurrentSubquest]->Update(Type, PlayerState))
    {
        ++CurrentSubquest;
        return true;
    }
    return false;
}

const FText& UQuest::GetTitle() const
{
    return Title;
}

const FText& UQuest::GetDescription() const
{
    return Description;
}

const FName& UQuest::GetNameInTable() const
{
    return NameInTable;
}

const TArray<USubquest*>& UQuest::GetSubquests() const
{
    return Subquests;
}
