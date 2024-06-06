// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Inventory/S_Item.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

/**
 * Base class for all items.
 */
UCLASS(BlueprintType)
class XYTOR_API UItem : public UObject
{
	GENERATED_BODY()
protected:
    /** Unique name of item in DataTable. */
    FName Name;
    /** Base data for the item. */
    FS_Item* ItemData;

    /**
     * Make additional initialisations for child classes.
     * @param ItemName Name of the item in a DataTable.
     * @return true if additional initialisation was successfull.
     */
    virtual bool AdditionalInit(FName ItemName); 
public:
    UFUNCTION(BlueprintPure)
    FName GetItemName() const;

    UFUNCTION(BlueprintPure)
    const FS_Item& GetItemData() const;

    /**
     * Initialisation of the item.
     * @param ItemName Name of item in the DataTable.
     * @return true after successfull initialisation. 
     */
    UFUNCTION(BlueprintCallable)
    bool Init(FName ItemName);
    /**
     * Initialisation of the item
     * @param ItemName Name of item in the DataTable.
     * @param ItemStructure Pointer to structure of item's data.
     * @return true after successfull initialisation.
     */
    bool Init(FName ItemName, FS_Item* ItemStructure);
    /**
     * Creates Item.
     * @param ItemName Name of the item in DataTable.
     * @param Parent Pointer to parent object.
     * @return Pointer to created item. If creating wasn't successfull method returns nullptr. 
     */
    UFUNCTION(BlueprintCallable)
    static UItem* MakeItem(FName ItemName, UObject* Parent);
    /**
     * Converts ItemType to subclass of Item.
     * @param Type ItemType.
     * @return class for this item. 
     */
    UFUNCTION(BlueprintCallable)
    static TSubclassOf<UItem> GetClass(EE_ItemType Type);

};