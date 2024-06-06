// XYTOR. All Rights Reserved.


#include "GameModes/GM_Base.h"

#include "HUD_WidgetManager.h"
#include "Core/Player/C_Player.h"
#include "Core/Player/PC_Base.h"
#include "Core/Player/PS_Base.h"

AGM_Base::AGM_Base()
{
    PlayerControllerClass = APC_Base::StaticClass();
    DefaultPawnClass = AC_Player::StaticClass();
    HUDClass = AHUD_WidgetManager::StaticClass();
    PlayerStateClass = APS_Base::StaticClass();
}