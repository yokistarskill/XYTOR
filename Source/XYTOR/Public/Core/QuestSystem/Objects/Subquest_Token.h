// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subquest.h"
#include "UObject/NoExportTypes.h"
#include "Subquest_Token.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API USubquest_Token : public USubquest
{
    GENERATED_BODY()

    TArray<FName> RequiredTokens;
    
protected:
    virtual bool InitByName(FName SubquestName) override;
    virtual bool Update(const APS_Quests* PlayerState) override;

    

};
