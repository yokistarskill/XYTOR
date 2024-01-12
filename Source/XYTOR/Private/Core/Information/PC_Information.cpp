// XYTOR. All Rights Reserved.


#include "Core/Information/PC_Information.h"

#include "Core/Information/Interfaces/IPS_Information.h"
#include "GameFramework/PlayerState.h"

class APS_Information;

void APC_Information::HideInformation_Implementation() const
{
    APlayerState* PS = GetPlayerState<APlayerState>();
    check(PS->Implements<UIPS_Information>());
    IIPS_Information::Execute_HideInformation(PS);
}

void APC_Information::DisplayInformation_Implementation() const
{
    APlayerState* PS = GetPlayerState<APlayerState>();
    check(PS->Implements<UIPS_Information>());
    IIPS_Information::Execute_DisplayInformation(PS);
}
