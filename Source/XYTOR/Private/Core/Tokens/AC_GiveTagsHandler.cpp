// XYTOR. All Rights Reserved.


#include "Core/Tokens/AC_GiveTagsHandler.h"

#include "PS_Tokens.h"

void UAC_GiveTagsHandler::Interact(AActor* InteractingActor)
{
    Super::Interact(InteractingActor);
    APS_Tokens* Tokens = StaticCast<APlayerController*>(InteractingActor)->GetPlayerState<APS_Tokens>();
    if (!Tokens)
    {
        UE_LOG(LogTemp, Error, TEXT("Can't take APS_Tokens in UAC_GiveTagsHandler::Interact"));
        return;
    }
    Tokens->UpdateTokens(TagsToGive);
}
