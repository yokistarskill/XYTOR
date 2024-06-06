// XYTOR. All Rights Reserved.


#include "Core/Inventory/PS_Inventory.h"

APS_Inventory::APS_Inventory()
{
    InventoryComponent = CreateDefaultSubobject<UAC_Inventory>(TEXT("Inventory"));

}

UAC_Inventory* APS_Inventory::GetInventory() const
{
    return InventoryComponent;
}
