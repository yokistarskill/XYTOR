// XYTOR. All Rights Reserved.


#include "Core/QuestSystem/Objects/Subquest_Item.h"
#include "Core/QuestSystem/PS_Quests.h"
#include "Core/QuestSystem/Structures/S_Subquest_Item.h"

bool USubquest_Item::Update(const APS_Quests* PlayerState)
{
    const UAC_Inventory* Inventory = Cast<APS_Quests>(PlayerState)->GetInventory();
    
    for (auto &Item: RequiredItems)
        if (!Inventory->Contains(Item.Get<0>(), Item.Get<1>()))
            return false;

    return true;    
}

bool USubquest_Item::InitByName(FName SubquestName)
{
    static FString ItemSubquestTablePath = "/Script/Engine.DataTable'/Game/XYTOR/DataTables/QuestSystem/DT_Subquests_Item.DT_Subquests_Item'";

    // Load the DataTable asset
    UDataTable* QuestTable = LoadObject<UDataTable>(nullptr, *ItemSubquestTablePath);

    // Check if the DataTable is loaded successfully
    if (QuestTable)
    {
        const FS_Subquest_Item* QuestData = QuestTable->FindRow<FS_Subquest_Item>(SubquestName, "");
        RequiredItems.Append(QuestData->RequiredItems);
    }
    else
    {
        // Handle the case where loading the DataTable failed
        UE_LOG(LogTemp, Error, TEXT("Failed to load DataTable: %s"), *ItemSubquestTablePath);
        return false;
    }
    return true;
}