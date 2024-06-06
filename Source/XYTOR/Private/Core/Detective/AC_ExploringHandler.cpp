// XYTOR. All Rights Reserved.


#include "Core/Detective/AC_ExploringHandler.h"
#include "Components/WidgetComponent.h"


void UAC_ExploringHandler::ChangeInteractionComponent() const
{
    
    UAC_Interact* InteractComponent = Cast<UAC_Interact> (GetOwner()->GetComponentByClass(UAC_Interact::StaticClass()));
    if (!InteractComponent)
    {
        UE_LOG(LogTemp, Error, TEXT("Evidence without AC_Interaction"));
        return;
    }
    if (bHighlighted)
        InteractComponent->SetInteractingText(FText::FromString("Explore"));

    InteractComponent->SetCanInteract(bHighlighted);
 
}

UAC_ExploringHandler::UAC_ExploringHandler()
{
    if (!Material)
    {
        static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialFinder(TEXT("/Script/Engine.Material'/Game/XYTOR/Core/Detective/Highlighing.Highlighing'"));
        if (MaterialFinder.Succeeded())
        {
            Material = MaterialFinder.Object;
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("UYourActorComponent: Material not found!"));
        }
    }
}

void UAC_ExploringHandler::Detect(TSubclassOf<UW_EvidenceBase> WidgetClass_) const
{
    if(!WidgetClass)
        WidgetClass=WidgetClass_;
    UE_LOG(LogTemp, Warning, TEXT("DETECTING"));
    GetOwner()->GetComponentByClass<UStaticMeshComponent>()->SetOverlayMaterial(Material);
    if (WidgetComponent && !bHighlighted)
    {
        UE_LOG(LogTemp, Warning, TEXT("DETECTING WITH WIDGET"));
        DisplayShortInformation();
    }
    bHighlighted = true;
    ChangeInteractionComponent();
}

void UAC_ExploringHandler::UnDetect() const
{
    bHighlighted = false;
    GetOwner()->GetComponentByClass<UStaticMeshComponent>()->SetOverlayMaterial(nullptr);
    
    if (WidgetComponent)
        WidgetComponent->SetVisibility(false);
    ChangeInteractionComponent();
}

void UAC_ExploringHandler::Interact(AActor* InteractingActor)
{
   // Super::Interact(InteractingActor);

    if (!WidgetComponent)
        InitWidget();
    DisplayLongInformation();
}

void UAC_ExploringHandler::InitWidget()
{
    if (!WidgetClass)
    {
        UE_LOG(LogTemp, Error, TEXT("No WidgetClass in UAC_ExploringHandler"));
        return;
    }
    if (WidgetComponent)
    {
        UE_LOG(LogTemp, Error, TEXT("Double Widget Initialisation in UAC_ExploringHandler"));
        return;
    }
    AActor* Owner = GetOwner();
    if (!Owner)
    {
        UE_LOG(LogTemp, Error, TEXT("Owner of UAC_Evidence is nullptr"));
        return;
    }
    WidgetComponent = NewObject<UWidgetComponent>(Owner, UWidgetComponent::StaticClass(), TEXT("EvidenceWidget"));
    if (WidgetComponent)
    {
        WidgetComponent->SetRelativeLocation({0,0,50});
        WidgetComponent->AttachToComponent(Owner->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
        WidgetComponent->RegisterComponent();
        WidgetComponent->SetWidgetClass(WidgetClass);
        WidgetComponent->SetVisibility(false);

        WidgetComponent->SetDrawAtDesiredSize(true);
        WidgetComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
        WidgetComponent->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
        WidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);

        // Получите виджет и вызовите метод InitInfo
        //WidgetComponent->InitWidget();
        
        Widget = Cast<UW_EvidenceBase>(WidgetComponent->GetWidget());
        Widget->InitInfo(LongInfo,ShortInfo);
    }
    else
        UE_LOG(LogTemp, Error, TEXT("Failed to create TextRenderComponent"));
}

void UAC_ExploringHandler::DisplayShortInformation() const
{
    Widget->DisplayShortInfo();
    WidgetComponent->SetVisibility(true);
}

void UAC_ExploringHandler::DisplayLongInformation() const
{
    Widget->DisplayLongInfo();
    WidgetComponent->SetVisibility(true);
}
