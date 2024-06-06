// XYTOR. All Rights Reserved.


#include "Core/Inventory/Objects/Item.h"
#include "Core/ExtraTools.h"
#include "..\..\..\..\Public\Core\Inventory\Objects\Ammo.h"
#include "..\..\..\..\Public\Core\Inventory\Objects\Weapon.h"

bool UItem::AdditionalInit(FName ItemName)
{
    return true;
}

FName UItem::GetItemName() const
{
    return Name;
}

const FS_Item& UItem::GetItemData() const
{
    return *ItemData;
}

bool UItem::Init(FName ItemName)
{
    Name = ItemName;
    FS_Item* Data = ExtraTools::GetStructureFromTable<FS_Item>(
        "/Script/Engine.DataTable'/Game/XYTOR/DataTables/Inventory/DT_Items.DT_Items'", ItemName);
    if (Data)
    {
        ItemData = Data;
        return AdditionalInit(ItemName);
    }
    return false;
}

bool UItem::Init(FName ItemName, FS_Item* ItemStructure)
{
    if (!ItemStructure)
        return Init(ItemName);

    Name = ItemName;
    ItemData = ItemStructure;
    return AdditionalInit(ItemName);
}
//
// UItem::UItem(FName ItemName)
// {
//     Init(ItemName);
// }
//
// UItem::UItem(FName ItemName, FS_Item* ItemStructure)
// {
//     Init(ItemName, ItemStructure);
// }

UItem* UItem::MakeItem(FName ItemName, UObject* Parent)
{
    FS_Item* Data = ExtraTools::GetStructureFromTable<FS_Item>(
        "/Script/Engine.DataTable'/Game/XYTOR/DataTables/Inventory/DT_Items.DT_Items'", ItemName);

    if (!Data)
        return nullptr;

    const auto ItemClass = GetClass(Data->ItemType);
    
    UItem* Item = NewObject<UItem>(Parent, ItemClass);
    if (Item->Init(ItemName, Data))
        return Item;

    Item->BeginDestroy();
    UE_LOG(LogTemp, Error, TEXT("Object with Name '%s' could not be created"), *ItemName.ToString());
    return nullptr;
}

TSubclassOf<UItem> UItem::GetClass(EE_ItemType Type)
{
    switch (Type)
    {
        case EE_ItemType::Item:
            return UItem::StaticClass();
        case EE_ItemType::Weapon:
            return UWeapon::StaticClass();
        case EE_ItemType::Ammo:
            return UAmmo::StaticClass();
        default:
            UE_LOG(LogTemp, Error, TEXT("Unknown EE_ItemType in UItem::GetClass"));
            return UItem::StaticClass();
    }
}
