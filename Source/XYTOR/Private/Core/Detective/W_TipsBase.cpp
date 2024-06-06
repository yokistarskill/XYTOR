// XYTOR. All Rights Reserved.


#include "Core/Detective/W_TipsBase.h"

void UW_TipsBase::DisplayTip_Implementation(const FText& Tip) const
{
    UE_LOG(LogTemp, Warning, TEXT("UW_TipsBase::DisplayTip is not defined. Message is: %s"), *Tip.ToString());
}
