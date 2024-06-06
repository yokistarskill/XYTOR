// XYTOR. All Rights Reserved.


#include "Core/Inventory/Objects/Ammo.h"
#include "Core/ExtraTools.h"

bool UAmmo::AdditionalInit(FName ItemName)
{
    FS_Ammo* Data = ExtraTools::GetStructureFromTable<FS_Ammo>(
       "/Script/Engine.DataTable'/Game/XYTOR/DataTables/Inventory/DT_Ammo.DT_Ammo'", ItemName);
    if (Data)
    {
        AmmoData = Data;
        return true;
    }
    return false;
}