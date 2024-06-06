// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Core/Inventory/Objects/Item.h"
#include "AC_Inventory.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInventoryChanged, UItem*, UpdatedItem, int32, Count);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FItemShareDelegate, UItem*, Item);

/**
 * Counter of items. Created to easy storing of count of items.
 */
USTRUCT(BlueprintType)
struct FCounterItem
{
    GENERATED_BODY()
    UPROPERTY()
    UItem* Value;
    int32 Count;
};

/** 
 * ActorComponent for storing and managing items.
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class XYTOR_API UAC_Inventory : public UActorComponent
{
    GENERATED_BODY()
private:
    void CallDelegateIfChanged(UItem* Item, int32 Count) const;
    UItem*& GetActiveItemSlotByType(EE_ItemType ItemType);
    UItem*& GetActiveItemSlotByType(const UItem* ItemType);

protected:
    /** Array of all items */
    UPROPERTY(VisibleAnywhere, Category = "Inventory")
    TArray<FCounterItem> Storage;

    /** Array of activated items */
    UPROPERTY(VisibleAnywhere, Category = "Inventory")
    TArray<UItem*> ActiveItems; 

    /**
     * Find a pair of Item and Count in Storage.
     * @param ItemName    Name of item to search.
     * @return pointer to FCounterItem if the item is storing and nullptr if doesn't.
     */
    FCounterItem* GetCounterByName(FName ItemName);
    /**
     * Find a pair of Item and Count in Storage.
     * @param ItemName    Name of item to search.
     * @return const pointer to FCounterItem if the item is storing and nullptr if doesn't.
     */
    const FCounterItem* GetCounterByName(FName ItemName) const;

    /**
     * Find a pair of Item and Count in Storage.
     * @param ItemName    Name of item to search.
     * @param Index    Reference to uint32 to write an index of FCounterItem in Storage.
     * @return pointer to FCounterItem if the item is storing and nullptr if doesn't.
     */
    FCounterItem* GetCounterByName(FName ItemName, uint32 &Index);
    /**
     * Find a pair of Item and Count in Storage.
     * @param ItemName    Name of item to search.
     * @param Index    Reference to uint32 to write an index of FCounterItem in Storage.
     * @return const pointer to FCounterItem if the item is storing and nullptr if doesn't.
     */
    const FCounterItem* GetCounterByName(FName ItemName, uint32 &Index) const;

public:
	UAC_Inventory();

    /**
     * Activate item in the inventory if it is possible.
     * @param Item    Pointer to item to activate.
     */
    UFUNCTION()
    void ActivateItem(UItem* Item);
    /**
     * Deactivate item in the inventory if it is possible.
     * @param Item    Pointer to item to deactivate.
     */
    UFUNCTION()
    void DeactivateItem(UItem* Item);

    /**
     * Adds items in the storage.
     * @param ItemName    Name of item to add.
     * @param Count    Quantity to add.
     * @return quantity of successfully added items.
     */
    UFUNCTION(BlueprintCallable)
    uint8 AddItem(FName ItemName, uint8 Count);
    /**
     * Adds items in the storage by pointer to item.
     * This method just use the ItemName from the item.
     * @param Item    Pointer to item to add.
     * @param Count    Quantity to add.
     * @return quantity of successfully added items.
     */
    UFUNCTION(BlueprintCallable)
    void AddItemByPointer(UItem* Item, int32 Count);
    /**
     * Removes items from the storage.
     * @param ItemName    Name of item to remove.
     * @param Count    Quantity to remove.
     * @return quantity of successfully removed items.
     */
    UFUNCTION(BlueprintCallable)
    uint8 RemoveItem(FName ItemName, uint8 Count);
    /**
    * Removes items from the storage by pointer to item.
    * This method just use the ItemName from the item.
    * @param Item    Pointer to item to remove.
    * @param Count    Quantity to remove.
    * @return quantity of successfully removed items.
    */
    UFUNCTION(BlueprintCallable)
    void RemoveItemByPointer(UItem* Item, int32 Count);

    /**
     * Check if there are enough items in the storage.
     * @param ItemName    Name of item to check.
     * @param Count    Required quantity.
     * @return true if there are enough such items in the Storage.
     */
    UFUNCTION(BlueprintPure)
    bool Contains(FName ItemName, uint8 Count) const;
    /**
     * @param ItemName    Name of item to count.
     * @return quantity of such items in the storage.
     */
    UFUNCTION(BlueprintPure)
    int32 GetCountOfItem(FName ItemName) const;
    /**
     * @return array of all pairs of Items and their quantities.
     */
    UFUNCTION(BlueprintPure)
    const TArray<FCounterItem>& GetItems() const;

public:
    /** Delegate to notify about storage changing. */
    FOnInventoryChanged OnInventoryChanged;
    /** Delegate to notify about activating of an item. */
    FItemShareDelegate OnItemActivated;
    /** Delegate to notify about deactivating of an item. */
    FItemShareDelegate OnItemDeactivated;
};
