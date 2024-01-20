// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_Health.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class XYTOR_API UAC_Health : public UActorComponent
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    float GetMaximumHealth() const
    {
        return MaximumHealth;
    }

    UFUNCTION(BlueprintCallable)
    float GetCurrentHealth() const
    {
        return CurrentHealth;
    }

protected:
    UPROPERTY(BlueprintReadWrite)
    float CurrentHealth;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Blueprintable)
    float MaximumHealth = 100;
public:	
	UAC_Health();

protected:
	virtual void BeginPlay() override;

public:	
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UFUNCTION(BlueprintCallable)
	bool TakeDamage(float Value);
    UFUNCTION(BlueprintPure)
    bool IsDead() const;

    UFUNCTION(BlueprintCallable)
    float SetMaximum(float NewMax);
};
