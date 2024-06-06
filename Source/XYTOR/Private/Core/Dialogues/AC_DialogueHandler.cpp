// XYTOR. All Rights Reserved.


#include "Core/Dialogues/AC_DialogueHandler.h"
#include "PS_Dialogues.h"

// Sets default values for this component's properties
UAC_DialogueHandler::UAC_DialogueHandler()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = false;
}

void UAC_DialogueHandler::Interact(AActor* InteractingActor)
{
    if (!InteractingActor) return;

    const auto DialogueComponent = Cast<AController>(InteractingActor)->GetPlayerState<APS_Dialogues>()->GetDialogue();
    if(!DialogueComponent) return;

    DialogueComponent->BeginDialogue(DialogueGraph);
}