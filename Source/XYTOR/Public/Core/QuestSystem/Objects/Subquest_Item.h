// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subquest.h"
#include "UObject/NoExportTypes.h"
#include "Subquest_Item.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API USubquest_Item : public USubquest
{

private:
    GENERATED_BODY()
    TMap<FName, uint8> RequiredItems;

protected:
    virtual bool Update(const APS_Quests* PlayerState) override;
    virtual bool InitByName(FName SubquestName) override;
    
};
