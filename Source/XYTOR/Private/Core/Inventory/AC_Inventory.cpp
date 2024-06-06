// XYTOR. All Rights Reserved.


#include "Core/Inventory/AC_Inventory.h"


// Sets default values for this component's properties
UAC_Inventory::UAC_Inventory()
{
	PrimaryComponentTick.bCanEverTick = false;
    // UE_LOG(LogTemp, Warning, TEXT("CONSTUCTOR WORKS"));
    ActiveItems.SetNumZeroed(20);
}

void UAC_Inventory::CallDelegateIfChanged(UItem* Item, int32 Count) const
{
    if (Count!=0)
        OnInventoryChanged.Broadcast(Item, Count);
}

UItem*& UAC_Inventory::GetActiveItemSlotByType(EE_ItemType ItemType)
{
    return ActiveItems[StaticCast<uint8>(ItemType)];
}

UItem*& UAC_Inventory::GetActiveItemSlotByType(const UItem* ItemType)
{
    return GetActiveItemSlotByType(ItemType->GetItemData().ItemType);
}

FCounterItem* UAC_Inventory::GetCounterByName(FName ItemName)
{
    uint32 t;
    return GetCounterByName(ItemName, t);
}

const FCounterItem* UAC_Inventory::GetCounterByName(FName ItemName) const
{
    uint32 t;
    return GetCounterByName(ItemName, t);
}

FCounterItem* UAC_Inventory::GetCounterByName(FName ItemName, uint32& Index)
{
    Index = 0;
    for (auto& Counter: Storage)
    {
        if (Counter.Value->GetItemName()==ItemName)
            return &Counter;
        Index++;
    }
    return nullptr;
}

const FCounterItem* UAC_Inventory::GetCounterByName(FName ItemName, uint32& Index) const
{
    Index = 0;
    for (const auto& Counter: Storage)
    {
        if (Counter.Value->GetItemName()==ItemName)
            return &Counter;
        Index++;
    }
    return nullptr;
}

void UAC_Inventory::ActivateItem(UItem* Item)
{
    if (Item->GetItemData().ItemType==EE_ItemType::Item)
        return;
    if (Item->GetItemData().ItemType==EE_ItemType::Ammo && !GetActiveItemSlotByType(EE_ItemType::Weapon))
        return;
    if (!Contains(Item->GetItemName(), 1))
        return;
    
    UItem*& Slot = GetActiveItemSlotByType(Item);
    if (Slot==Item)
        return;
    
    if (Slot)
    {
        DeactivateItem(Slot);
    }
    
    Slot = Item;
    OnItemActivated.Broadcast(Item);
}

void UAC_Inventory::DeactivateItem(UItem* Item)
{
    if (!Item)
    {
        UE_LOG(LogTemp, Warning, TEXT("[AC_Inventory] Try to deactivate nullptr"));
        return;
    }
    
    UItem*& Slot = GetActiveItemSlotByType(Item);
    if (Slot!=Item)
        return;
    
    OnItemDeactivated.Broadcast(Item);
    Slot = nullptr;

    if (Item->GetItemData().ItemType==EE_ItemType::Weapon)
    {
        UItem*& SlotAmmo = GetActiveItemSlotByType(EE_ItemType::Ammo);
        if (SlotAmmo)
        {
            OnItemDeactivated.Broadcast(SlotAmmo);
            SlotAmmo=nullptr;
        }
    }
}

uint8 UAC_Inventory::AddItem(FName ItemName, uint8 Count)
{
    FCounterItem* Counter = GetCounterByName(ItemName);
    UItem* Item;
    if (Counter)
    {
        Counter->Count+=Count;
        Item = Counter->Value;
    }
    else
    {
        Item = UItem::MakeItem(ItemName, this);
        if (!Item)
            return 0;
        
        Storage.Push({Item, Count});
    }
    CallDelegateIfChanged(Item, Count);
    return Count;
}

uint8 UAC_Inventory::RemoveItem(FName ItemName, uint8 Count)
{
    uint32 Index; 
    FCounterItem* Counter = GetCounterByName(ItemName, Index);
    if (!Counter)
        return 0;
    
    Count = FMath::Min(Counter->Count, StaticCast<int32>(Count));
    Counter->Count-=Count;
    CallDelegateIfChanged(Counter->Value, -Count);
    if (Counter->Count<=0)
    {
        DeactivateItem(Counter->Value);
        Storage.RemoveAtSwap(Index);
    }
    return Count;
}

bool UAC_Inventory::Contains(FName ItemName, uint8 Count) const
{
    if (Count<=0)
        return true;
    
    const FCounterItem* Counter = GetCounterByName(ItemName);
    return Counter && Counter->Count>=Count;
}

int32 UAC_Inventory::GetCountOfItem(FName ItemName) const
{
    const FCounterItem* Counter = GetCounterByName(ItemName);
    if (Counter)
        return Counter->Count;
    return 0;
}

void UAC_Inventory::AddItemByPointer(UItem* ItemName, int32 Count)
{
    AddItem(ItemName->GetItemName(), Count);
}

void UAC_Inventory::RemoveItemByPointer(UItem* ItemName, int32 Count)
{
    RemoveItem(ItemName->GetItemName(), Count);
}

const TArray<FCounterItem>& UAC_Inventory::GetItems() const
{
    return Storage;
}
