// XYTOR. All Rights Reserved.


#include "Core/QuestSystem/Objects/Subquest_Token.h"

#include "Core/QuestSystem/PS_Quests.h"
#include "Core/QuestSystem/Structures/S_Subquest_Token.h"

bool USubquest_Token::InitByName(FName SubquestName)
{
    static FString TockenSubquestTablePath = "/Script/Engine.DataTable'/Game/XYTOR/DataTables/QuestSystem/DT_Subquests_Token.DT_Subquests_Token'";

    // Load the DataTable asset
    UDataTable* QuestTable = LoadObject<UDataTable>(nullptr, *TockenSubquestTablePath);

    // Check if the DataTable is loaded successfully
    if (QuestTable)
    {
        const FS_Subquest_Token* QuestData = QuestTable->FindRow<FS_Subquest_Token>(SubquestName, "");
        RequiredTokens.Append(QuestData->RequiredTokens);
    }
    else
    {
        // Handle the case where loading the DataTable failed
        UE_LOG(LogTemp, Error, TEXT("Failed to load DataTable: %s"), *TockenSubquestTablePath);
        return false;
    }
    return true;
} 

bool USubquest_Token::Update(const APS_Quests* PlayerState)
{
    return false;
}
