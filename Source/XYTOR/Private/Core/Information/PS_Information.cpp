// XYTOR. All Rights Reserved.


#include "Core/Information/PS_Information.h"

#include "Engine/DataTable.h"


void APS_Information::BeginPlay()
{
    FString DataTableAsset = "/Script/Engine.DataTable'/Game/XYTOR/DataTables/Information/DT_EntityInformation.DT_EntityInformation'";

    // Load the DataTable asset
    UDataTable* Table = LoadObject<UDataTable>(nullptr, *DataTableAsset);

    // Check if the DataTable is loaded successfully
    if (Table)
    {
        OpenedEntities = Table->GetRowNames();
    }
    else
    {
        // Handle the case where loading the DataTable failed
        UE_LOG(LogTemp, Error, TEXT("Failed to load DataTable: %s"), *DataTableAsset);
    }
}

void APS_Information::AddEntity_Implementation(FName EntityName)
{
    OpenedEntities.Push(EntityName);
}

TArray<FName> APS_Information::GetEntities_Implementation() const
{
    return OpenedEntities;
}
