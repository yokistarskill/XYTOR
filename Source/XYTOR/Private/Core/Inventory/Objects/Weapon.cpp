// XYTOR. All Rights Reserved.


#include "Core/Inventory/Objects/Weapon.h"
#include "Core/ExtraTools.h"

bool UWeapon::AdditionalInit(FName ItemName)
{
    FS_Weapon* Data = ExtraTools::GetStructureFromTable<FS_Weapon>(
       "/Script/Engine.DataTable'/Game/XYTOR/DataTables/Inventory/DT_Weapons.DT_Weapons'", ItemName);
    if (Data)
    {
        WeaponData = Data;
        return true;
    }
    return false;
}