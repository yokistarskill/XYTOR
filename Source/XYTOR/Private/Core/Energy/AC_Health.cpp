// XYTOR. All Rights Reserved.


#include "Core/Energy/AC_Health.h"

// Sets default values for this component's properties
UAC_Health::UAC_Health()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_Health::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAC_Health::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UAC_Health::TakeDamage(float Value)
{
    CurrentHealth = FMath::Clamp(CurrentHealth-Value, 0, MaximumHealth);
    
    return IsDead();
}

bool UAC_Health::IsDead() const
{
    return CurrentHealth<=0;
}

