// XYTOR. All Rights Reserved.


#include "Core/Player/PC_Base.h"
#include "GameFramework/Pawn.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/CapsuleComponent.h"
#include "Core/Player/C_Player.h"
#include "GameFramework/SpringArmComponent.h"

APC_Base::APC_Base()
{
    bShowMouseCursor = true;
    DefaultMouseCursor = EMouseCursor::Default;
}

void APC_Base::BeginPlay()
{
    Super::BeginPlay();

    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(DefaultMappingContext, 0);
    }
}

void APC_Base::SetupInputComponent()
{
    Super::SetupInputComponent();
    
    if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
    {
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APC_Base::Move);
        EnhancedInputComponent->BindAction(CameraZoomAction, ETriggerEvent::Triggered, this, &APC_Base::ZoomCamera);
    }
    
}

void APC_Base::Move(const FInputActionValue& Value)
{
    if (!GetPawn()) return;

    // input is a Vector2D
    const FVector2D MovementVector = Value.Get<FVector2D>();

    // find out which way is forward
    const FRotator Rotation = GetControlRotation();
    const FRotator YawRotation(0, Rotation.Yaw, 0);

    // get forward vector
    const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

    // get right vector 
    const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
    
    // add movement 
    GetPawn()->AddMovementInput(ForwardDirection, MovementVector.Y);
    GetPawn()->AddMovementInput(RightDirection, MovementVector.X);
}

void APC_Base::ZoomCamera(const FInputActionValue& Value)
{
    const AC_Player* PlayerPawn = GetPawn<AC_Player>();
    if (!PlayerPawn) return;
    USpringArmComponent* CameraBoom = PlayerPawn->GetComponentByClass<USpringArmComponent>();
    if (!CameraBoom)
    {
        UE_LOG(LogTemp, Warning, TEXT("No USpringArmComponent was found"));
        return;
    }
    
    constexpr float CameraZoomScale = 200.f;
    CameraBoom->TargetArmLength = FMath::Clamp(CameraBoom->TargetArmLength+Value.Get<float>()*CameraZoomScale, PlayerPawn->GetMinCameraDistance(), PlayerPawn->GetMaxCameraDistance());
}
