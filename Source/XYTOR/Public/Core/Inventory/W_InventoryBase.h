// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/WidgetManager/Widgets/W_NormalBase.h"
#include "W_InventoryBase.generated.h"

class UItem;

//DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnItemRemovedDelegate, UItem*, Item, int32, Count);
DECLARE_DELEGATE_TwoParams(FOnItemRemovedDelegate, UItem*, int32);
DECLARE_DELEGATE_OneParam(FOnItemStatusChanged, UItem*);

/**
 * 
 */
UCLASS()
class XYTOR_API UW_InventoryBase : public UW_NormalBase
{
	GENERATED_BODY()
public:
    /** Delegate to notify InventoryComponent about item removing from the widget. */
    FOnItemRemovedDelegate OnItemRemoved;
    /** Delegate to notify InventoryComponent about item activating from the widget. */
    FOnItemStatusChanged OnItemActivated;
    /** Delegate to notify InventoryComponent about item deactivating from the widget. */
    FOnItemStatusChanged OnItemDeactivated;

    /**
     * Update storage information in the inventory widget.
     * @param Item  Pointer to an object whose quantity has changed. 
     * @param Count Change. Negative after item removing.
     */
    UFUNCTION(BlueprintCallable)
    void UpdateItem(UItem* Item, int32 Count);

    /**
     * Display activating of item in inventory.
     * @param Item  Pointer to an object which was activated. 
     */
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ActivateItem(UItem* Item);
    /**
     * Display deactivating of item in inventory.
     * @param Item  Pointer to an object which was deactivated. 
     */
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void DeactivateItem(UItem* Item);
    
protected:
    /**
     * Remove items from inventory component from widget.
     * @param Item Pointer to an object which was removed.
     * @param Count Quantity that was removed.
     */
    UFUNCTION(BlueprintCallable)
    void RemoveItemFromInventory(UItem* Item, int32 Count);
    /**
     * Activate item in inventory component from widget.
     * @param Item Pointer to the object which should be activated.
     * @param IsActivated true to activate, false to deactivate.
     */
    UFUNCTION(BlueprintCallable)
    void ActivateItemInInventory(UItem* Item, bool IsActivated);
    /**
     * Add items in widget.
     * @param Item Pointer to item to add.
     * @param Count Quantity to add.
     */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void AddItem(const UItem* Item, int32 Count);

    /**
     * Remove items in widget.
     * @param Item Pointer to item to remove.
     * @param Count Quantity to remove.
     */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void RemoveItem(const UItem* Item, int32 Count);
};
