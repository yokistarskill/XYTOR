// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/PlayerState.h"
#include "PS_Tokens.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTokensUpdate, const FGameplayTagContainer&, TagContainer);

UCLASS()
class XYTOR_API APS_Tokens : public APlayerState
{
    GENERATED_BODY()

public:
    FOnTokensUpdate OnTokensUpdateDelegate;
    
protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tokens")
    FGameplayTagContainer Tokens;

public:
    const FGameplayTagContainer& GetTokens() { return Tokens; }
    
    UFUNCTION(BlueprintCallable)
    void UpdateTokens(const FGameplayTagContainer& TagContainer, bool bRemove = false);
};