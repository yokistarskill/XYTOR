// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Player/C_Base.h"
#include "C_Energy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamageTaken, float, Damage);

UCLASS()
class XYTOR_API AC_Energy : public AC_Base
{
    GENERATED_BODY()

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class UAC_Health* HealthComponent; 

public:
	// Sets default values for this character's properties
	AC_Energy();

    UPROPERTY(BlueprintAssignable, VisibleAnywhere)
    FOnDamageTaken OnDamageTaken;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable)
    void MakeDead();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UFUNCTION(BlueprintPure)
    float GetMaximumHealth() const;
    
    UFUNCTION(BlueprintPure)
    float GetCurrentHealth() const;
    
    virtual float TakeDamage(float Damage, const FDamageEvent& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
};
