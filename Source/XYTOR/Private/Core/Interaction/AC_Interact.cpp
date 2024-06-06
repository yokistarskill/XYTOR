// XYTOR. All Rights Reserved.


#include "Core/Interaction/AC_Interact.h"
#include "Core/Interaction/AC_InteractionHandler.h"


// Sets default values for this component's properties
UAC_Interact::UAC_Interact()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UAC_Interact::SetHandlers(TArray<TSubclassOf<UAC_InteractionHandler>> Handlers)
{
    for (const auto& HandlerClass: Handlers)
        if (auto Handler = Cast<UAC_InteractionHandler>(GetOwner()->GetComponentByClass(HandlerClass)))
            ComponentsToInteract.Push(Handler);
}

void UAC_Interact::SetCanInteract(bool CanInteract)
{
    bCanInteract = CanInteract;  
}

void UAC_Interact::SetInteractingText(const FText& NewText)
{
    InteractingText = NewText;
}

TArray<UAC_InteractionHandler*> UAC_Interact::GetHandlers() const
{
    if (!ComponentsToInteract.IsEmpty())
    {
        return ComponentsToInteract;
    }
    TArray<UAC_InteractionHandler*> Handlers;
    GetOwner()->GetComponents<UAC_InteractionHandler>(Handlers);
    return Handlers;
}

FText UAC_Interact::GetInteractingText() const
{
    return InteractingText;
}

bool UAC_Interact::CanInteract() const
{
    return bCanInteract;
}



