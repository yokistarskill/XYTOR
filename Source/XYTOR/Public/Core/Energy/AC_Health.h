// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_Health.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class XYTOR_API UAC_Health : public UActorComponent
{
	GENERATED_BODY()

protected:
    UPROPERTY(BlueprintReadWrite)
    float MaximumHealth;
    UPROPERTY(BlueprintReadWrite)
    float CurrentHealth;
    
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
};
