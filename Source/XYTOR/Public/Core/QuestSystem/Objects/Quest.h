// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subquest.h"
#include "UObject/NoExportTypes.h"
#include "Quest.generated.h"

class APS_Quests;
/**
 * 
 */
UCLASS(BlueprintType)
class XYTOR_API UQuest : public UObject
{
	GENERATED_BODY()
protected:
    UPROPERTY(BlueprintReadOnly)
    TArray<USubquest*> Subquests;
    UPROPERTY(BlueprintReadOnly)
    uint8 CurrentSubquest = 0u;
    // APS_Quests* QuestCore; 

    UPROPERTY(BlueprintReadOnly)
    FText Title;
    UPROPERTY(BlueprintReadOnly)
    FText Description;
    UPROPERTY(BlueprintReadOnly)
    FName NameInTable;

public:
    bool Init(FName QuestName);

    
    UQuest() = default;
    UQuest(FName QuestName);
    UFUNCTION(BlueprintPure)
    bool IsCompleted() const;
    bool Update(EE_SubquestType Type, const APS_Quests* PlayerState);

    const FText& GetTitle() const;
    const FText& GetDescription() const;
    const FName& GetNameInTable() const;
    UFUNCTION(BlueprintPure)
    const TArray<USubquest*>& GetSubquests() const;
};
