// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/QuestSystem/Structures/S_Subquest.h"
#include "UObject/NoExportTypes.h"
#include "Subquest.generated.h"

class APS_Quests;
/**
 * 
 */
UCLASS(BlueprintType)
class XYTOR_API USubquest : public UObject
{
	GENERATED_BODY()

protected:
    UPROPERTY(BlueprintReadOnly)
    FS_Subquest Data;
    UPROPERTY(BlueprintReadOnly)
    bool bComplete;
public:
    bool Init(const FS_Subquest& SubquestInfo);
    bool IsComplete() const;
    bool Update(EE_SubquestType Type, const APS_Quests* PlayerState);
    static USubquest* MakeSubquest(const FS_Subquest& Data, UObject* Parent);
protected:
    virtual bool Update(const APS_Quests* PlayerState) PURE_VIRTUAL(USubquest::Update, return false;);
    virtual bool InitByName(FName SubquestName) PURE_VIRTUAL(USubquest::InitByName, return false;);
};
