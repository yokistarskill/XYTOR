// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "W_InventoryBase.h"
#include "Core/Energy/PC_Energy.h"
#include "Objects/SceneItem.h"
#include "PC_Inventory.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API APC_Inventory : public APC_Energy
{
	GENERATED_BODY()

protected:
    UPROPERTY()
    UW_InventoryBase* InventoryWidget;
    UPROPERTY(EditDefaultsOnly, Category="Widgets")
    TSubclassOf<UW_InventoryBase> InventoryWidgetClass;

public:
    virtual void BeginPlay() override;
    UFUNCTION()
    void DropItem(UItem* Item, int32 Count) const;
    void PickUpItem(FName ItemName, int32 Count) const;
    UFUNCTION(BlueprintCallable)
    void DisplayInventory() const;
    
    virtual void SetupInputComponent() override;

private:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* InventoryAction;

    void InventoryActionHandler();
};
