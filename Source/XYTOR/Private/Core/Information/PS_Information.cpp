// XYTOR. All Rights Reserved.


#include "Core/Information/PS_Information.h"

void APS_Information::AddEntity_Implementation(FName EntityName)
{
    OpenedEntities.Push(EntityName);
}

TArray<FName> APS_Information::GetEntities_Implementation() const
{
    return OpenedEntities;
}
