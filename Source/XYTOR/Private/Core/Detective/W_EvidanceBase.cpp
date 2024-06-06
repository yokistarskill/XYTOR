// XYTOR. All Rights Reserved.


#include "..\..\..\Public\Core\Detective\W_EvidenceBase.h"

void UW_EvidenceBase::InitInfo_Implementation(const FText& NewLongInfo, const FText& NewShortInfo)
{
    LongInfo = NewLongInfo;
    ShortInfo = NewShortInfo;
}
//
// void UW_EvidenceBase::DisplayLongInfo_Implementation() const
// {
//     UE_LOG(LogTemp, Warning, TEXT("UW_EvidenceBase::DisplayLoading_Implementation not initialised"));
// }
void UW_EvidenceBase::DisplayLongInfo_Implementation()
{
    UE_LOG(LogTemp, Warning, TEXT("UW_EvidenceBase::DisplayLongInfo_Implementation not initialised"));
}

void UW_EvidenceBase::DisplayShortInfo_Implementation()
{
    UE_LOG(LogTemp, Warning, TEXT("UW_EvidenceBase::DisplayShortInfo_Implementation not initialised"));
}
