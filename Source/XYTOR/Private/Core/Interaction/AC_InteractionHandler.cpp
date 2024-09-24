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
    if (!InteractConfig)
    {
        GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Detected handler without UAC_Interact"));
        return;
    }
    
    InteractConfig->SetCanInteract(false);
    GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("No implementation of UAC_InteractionHandler::Interact"));

}

bool UAC_InteractionHandler::CanInteract(AActor* InteractingActor)
{
    return true;
}
