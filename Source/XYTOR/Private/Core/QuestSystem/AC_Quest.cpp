// XYTOR. All Rights Reserved.


#include "Core/QuestSystem/AC_Quest.h"
#include "Core/QuestSystem/PS_Quests.h"

UAC_Quest::UAC_Quest()
{
}

void UAC_Quest::Interact(AActor* InteractingActor)
{
    Super::Interact(InteractingActor);

    if (!InteractingActor) return;

    const auto Controller = Cast<AController>(InteractingActor);
    if (!Controller) return;

    const auto PlayerState = Controller->GetPlayerState<APS_Quests>();
    if (!PlayerState) return;

    PlayerState->AddQuest(Quest);
}