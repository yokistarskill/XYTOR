// XYTOR. All Rights Reserved.


#include "Core/Interaction/PC_Interaction.h"

#include "EnhancedInputComponent.h"
#include "Core/Interaction/AC_InteractionHandler.h"
#include "Core/WidgetManager/HUD_WidgetManager.h"
#include "Core/Interaction/AC_Interact.h"
#include "VectorTypes.h"
#include "GameFramework/Character.h"

class AHUD_WidgetManager;

void APC_Interaction::BeginPlay()
{
    Super::BeginPlay();

    if (!InteractionWidgetClass)
    {
        UE_LOG(LogTemp, Error, TEXT("No widget class in PC_Information"));
    }
    else
    {
        AHUD_WidgetManager* HUD = Cast<AHUD_WidgetManager>(GetHUD());
        if (HUD)
        {
            UW_Base* temp = HUD->AddWidgetByClass(InteractionWidgetClass);
            InteractionBase = Cast<UW_InteractionBase>(temp);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("HUD is not correct"));
        }
    }
}

void APC_Interaction::Interact()
{
    if (CurrentObjectIndex<0 || CurrentObjectIndex>=ComponentsToInteract.Num()) return;
    {
        // Check for null actor
        const auto* CurrentComponent = ComponentsToInteract[CurrentObjectIndex];
        if (!CurrentComponent)
        { 
            // RemoveActor(CurrentComponent->GetOwner());
            return;
        }
    
        // Iterate over handlers and interact with each handler
        auto InteractOverHandlers = [this](const auto& Handlers){
            if (!Handlers.IsEmpty())
            {
                for (const auto Handler : Handlers)
                {
                    Handler->Interact(this);
                }
            }
        };
        
        if (!CurrentComponent->CanInteract())
            return;
        // Get specific handlers setup from BP
        InteractOverHandlers(CurrentComponent->GetHandlers());
    }
}

void APC_Interaction::SetupInputComponent()
{
    Super::SetupInputComponent();
    if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
    {
        EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &APC_Interaction::Interact);
    }
}

void APC_Interaction::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    
    if (ComponentsToInteract.IsEmpty())
    {
        return;
    }

    int8 MinInd = -1;
    double Min = TNumericLimits<double>().Max();
    for (int8 i = 0; i < ComponentsToInteract.Num(); ++i)
    {
        if(!ComponentsToInteract[i]->CanInteract())
            continue;
        
        const double Dist = UE::Geometry::DistanceSquared(GetCharacter()->GetActorLocation(), ComponentsToInteract[i]->GetOwner()->GetActorLocation());
        if (Dist < Min)
        {
            MinInd = i;
            Min = Dist;
        }
    }
    if (MinInd<0)
    {
        CurrentObjectIndex = -1;
        InteractionBase->CleanMessage();
    }
    else if (MinInd != CurrentObjectIndex)
    {
        CurrentObjectIndex = MinInd;
        InteractionBase->UpdateMessage(ComponentsToInteract[CurrentObjectIndex]->GetInteractingText());
    }
}

bool APC_Interaction::AddActor(AActor* NewActor)
{
    UAC_Interact* InteractComponent = NewActor->GetComponentByClass<UAC_Interact>();
    if (!InteractComponent)
        return false;
    ComponentsToInteract.Push(InteractComponent);
    return true;
}

bool APC_Interaction::RemoveActor(AActor* TargetActor)
{
    UAC_Interact* InteractComponent = TargetActor->GetComponentByClass<UAC_Interact>();
    if (!InteractComponent)
        return false;

    // For components
    const int32 IndexToRemove = ComponentsToInteract.Find(InteractComponent);
    if (IndexToRemove == CurrentObjectIndex)
    {
        CurrentObjectIndex = -1;
        InteractionBase->CleanMessage();
    }
    else if (CurrentObjectIndex == ComponentsToInteract.Num() - 1)
    {
        CurrentObjectIndex = IndexToRemove;
    }
    else if (IndexToRemove < CurrentObjectIndex)
    {
        --CurrentObjectIndex;
    }
    ComponentsToInteract.RemoveAtSwap(IndexToRemove);
    return true;
}

bool APC_Interaction::CanInteract(const AActor* TargetActor)
{
    return IsValid(TargetActor->GetComponentByClass(UAC_Interact::StaticClass()));
}

FText APC_Interaction::GetInteractText(const AActor* TargetActor)
{
    return TargetActor->GetComponentByClass<UAC_Interact>()->GetInteractingText();
}
