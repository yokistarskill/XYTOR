// XYTOR. All Rights Reserved.


#include "Core/Inventory/Objects/SceneItem.h"
#include "AC_Interact.h"
#include "Components/BoxComponent.h"
#include "Core/Inventory/AC_PickUpHandler.h"

// Sets default values
ASceneItem::ASceneItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
    RootComponent = MeshComponent;
    
    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollison"));
    BoxComponent->SetupAttachment(RootComponent);
    
    PickUpComponent = CreateDefaultSubobject<UAC_PickUpHandler>(TEXT("AC_PickUpHandler"));
    
    InteractConfig = CreateDefaultSubobject<UAC_Interact>(TEXT("AC_Interact"));
    InteractConfig->SetInteractingText(FText::FromString(TEXT("Pick up (E)")));
}

void ASceneItem::Init(FName Name, int32 Count) const
{
    PickUpComponent->SetItem(Name, Count);
}