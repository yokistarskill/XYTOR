// XYTOR. All Rights Reserved.


#include "Core/Inventory/PC_Inventory.h"

#include "EnhancedInputComponent.h"
#include "Core/Inventory/PS_Inventory.h"
#include "Core/WidgetManager/HUD_WidgetManager.h"
#include "GameFramework/Character.h"

void APC_Inventory::BeginPlay()
{
    Super::BeginPlay();
    INIT_WIDGET_IN_BEGIN_PLAY(PC_Inventory, UW_InventoryBase, InventoryWidgetClass, InventoryWidget);
    APS_Inventory* PS = GetPlayerState<APS_Inventory>();
    if (PS)
    {
        PS->GetInventory()->OnInventoryChanged.AddUniqueDynamic(InventoryWidget, &UW_InventoryBase::UpdateItem);
        PS->GetInventory()->OnItemActivated.AddUniqueDynamic(InventoryWidget, &UW_InventoryBase::UW_InventoryBase::ActivateItem);
        PS->GetInventory()->OnItemDeactivated.AddUniqueDynamic(InventoryWidget, &UW_InventoryBase::UW_InventoryBase::DeactivateItem);
        
        InventoryWidget->OnItemRemoved.BindUObject(this, &APC_Inventory::DropItem);
        InventoryWidget->OnItemActivated.BindUObject(PS->GetInventory(), &UAC_Inventory::ActivateItem);
        InventoryWidget->OnItemDeactivated.BindUObject(PS->GetInventory(), &UAC_Inventory::DeactivateItem);
    }
    
}

void APC_Inventory::DropItem(UItem* Item, int32 Count) const
{
    if (const auto& ItemActorClass = Item->GetItemData().ItemActorClass)
    {
        GetPlayerState<APS_Inventory>()->GetInventory()->RemoveItemByPointer(Item, Count);
    
        const FVector Location = GetCharacter()->GetActorLocation() + GetCharacter()->GetActorForwardVector()*100;
        const FRotator Rotation(0.0f, 0.0f, 0.0f);
        const FActorSpawnParameters SpawnInfo;
    
        GetWorld()->SpawnActor<ASceneItem>(ItemActorClass, Location, Rotation, SpawnInfo)->Init(Item->GetItemName(), Count);
    }
}

void APC_Inventory::PickUpItem(FName ItemName, int32 Count) const
{
    GetPlayerState<APS_Inventory>()->GetInventory()->AddItem(ItemName, Count);
}

void APC_Inventory::DisplayInventory() const
{
    AHUD_WidgetManager* HUD = Cast<AHUD_WidgetManager> (GetHUD());
    if(HUD)
    {
        HUD->ToggleNormalWidgetByClass(InventoryWidgetClass);
    }
}

void APC_Inventory::SetupInputComponent()
{
    Super::SetupInputComponent();
    if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
    {
        EnhancedInputComponent->BindAction(InventoryAction, ETriggerEvent::Started, this, &APC_Inventory::InventoryActionHandler);
    }
}

void APC_Inventory::InventoryActionHandler()
{
    DisplayInventory();
}
