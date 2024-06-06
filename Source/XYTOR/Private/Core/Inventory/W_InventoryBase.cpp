// XYTOR. All Rights Reserved.


#include "Core/Inventory/W_InventoryBase.h"

void UW_InventoryBase::UpdateItem(UItem* Item, int32 Count)
{
    if (Count>0)
        AddItem(Item, Count);
    else
        RemoveItem(Item, -Count);
}

void UW_InventoryBase::ActivateItem_Implementation(UItem* Item)
{
}

void UW_InventoryBase::DeactivateItem_Implementation(UItem* Item)
{
}

void UW_InventoryBase::RemoveItemFromInventory(UItem* Item, int32 Count)
{
    OnItemRemoved.ExecuteIfBound(Item, Count);
}

void UW_InventoryBase::ActivateItemInInventory(UItem* Item, bool IsActivated)
{
    if (IsActivated)
        OnItemActivated.ExecuteIfBound(Item);
    else
        OnItemDeactivated.ExecuteIfBound(Item);
}


void UW_InventoryBase::RemoveItem_Implementation(const UItem* Item, int32 Count)
{
}

void UW_InventoryBase::AddItem_Implementation(const UItem* Item, int32 Count)
{
}
