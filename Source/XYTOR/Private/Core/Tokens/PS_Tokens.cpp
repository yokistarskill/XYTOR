// XYTOR. All Rights Reserved.

#include "Core/Tokens/PS_Tokens.h"

void APS_Tokens::UpdateTokens(const FGameplayTagContainer& TagContainer, bool bRemove)
{
    if (bRemove)
    {
        Tokens.RemoveTags(TagContainer); 
    }
    else
    {
        Tokens.AppendTags(TagContainer);
    }

    OnTokensUpdateDelegate.Broadcast(Tokens);
}