// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "W_InformationBase.generated.h"

/**
 * 
 */
UCLASS()
class XYTOR_API UW_InformationBase : public UUserWidget
{
	GENERATED_BODY()
protected:
    TArray<FName> Entities;
public:
    void SetEntities(const TArray<FName>& NewEntities);
};
