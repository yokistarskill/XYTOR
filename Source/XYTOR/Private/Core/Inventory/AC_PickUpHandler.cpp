// XYTOR. All Rights Reserved.


#include "Core/Inventory/AC_PickUpHandler.h"
#include "Core/Inventory/PC_Inventory.h"

UAC_PickUpHandler::UAC_PickUpHandler()
{
}

void UAC_PickUpHandler::Interact(AActor* InteractingActor)
{
    Super::Interact(InteractingActor);

    if (!InteractingActor) return;

    const auto Controller = Cast<APC_Inventory>(InteractingActor);
    if (!Controller) return;
    
    for (const auto& Item : Items)
    {
        Controller->PickUpItem(Item.Key, Item.Value);
    }
    if (bDestroyAfterPickUp)
    {
        GetOwner()->Destroy();
    }
}

void UAC_PickUpHandler::SetItem(FName Name, int32 Count)
{
    Items.Empty();
    Items.Add(Name, Count);
}
