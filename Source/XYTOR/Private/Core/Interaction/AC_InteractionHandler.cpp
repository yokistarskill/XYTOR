// XYTOR. All Rights Reserved.


#include "Core/Interaction/AC_InteractionHandler.h"
#include "AC_Interact.h"

// Sets default values for this component's properties
UAC_InteractionHandler::UAC_InteractionHandler()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UAC_InteractionHandler::Interact(AActor* InteractingActor)
{
    // Turn off interaction after interaction
    const auto InteractConfig = GetOwner()->GetComponentByClass<UAC_Interact>();
    if (!InteractConfig) return;
    
    InteractConfig->SetCanInteract(false);

}