// XYTOR. All Rights Reserved.


#include "Core/Energy/C_Energy.h"

#include "Core/Energy/AC_Health.h"

// Sets default values
AC_Energy::AC_Energy()
{
    
    HealthComponent = Cast<UAC_Health>(AddComponentByClass(UAC_Health::StaticClass(), false, {}, false));
    if(!HealthComponent)
    {
        UE_LOG(LogTemp, Error, TEXT("Incorrect health component"));
    }
}

// Called when the game starts or when spawned
void AC_Energy::BeginPlay()
{
	Super::BeginPlay();
	
}

void AC_Energy::MakeDead()
{
}

// Called every frame
void AC_Energy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AC_Energy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AC_Energy::TakeDamage(float Damage, const FDamageEvent& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
    Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

    if (HealthComponent->TakeDamage(Damage))
        MakeDead();
        
    return Damage;
}

