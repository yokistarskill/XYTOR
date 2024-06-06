// XYTOR. All Rights Reserved.

#include "Core/WidgetManager/HUD_WidgetManager.h"
#include "Blueprint/UserWidget.h"
#include "Core/WidgetManager/Widgets/W_BackgroundBase.h"
#include "Core/WidgetManager/Widgets/W_NormalBase.h"

DEFINE_LOG_CATEGORY_STATIC(LogHUD, All, All)

TArray<UW_Base*>& AHUD_WidgetManager::ChooseWidgets(TSubclassOf<UW_Base> WidgetClass)
{
    if (UW_Base::IsBackgroundWidgetByClass(WidgetClass))
        return BackgroundWidgets;
    return NormalWidgets;
}

const TArray<UW_Base*>& AHUD_WidgetManager::ChooseWidgets(TSubclassOf<UW_Base> WidgetClass) const
{
    if (UW_Base::IsBackgroundWidgetByClass(WidgetClass))
        return BackgroundWidgets;
    return NormalWidgets;
}

void AHUD_WidgetManager::BeginPlay()
{
    Super::BeginPlay();
}

UW_Base* AHUD_WidgetManager::GetWidgetByClass(TSubclassOf<UW_Base> WidgetClass) const
{
    // Choosing array of background or normal widgets.
    const TArray<UW_Base*>& Widgets = ChooseWidgets(WidgetClass);
    
    // Iterate through the array of widgets
    for (const auto& GameWidget : Widgets)
    {
        // Check if the current game widget is of the specified class
        if (GameWidget->IsA(WidgetClass))
        {
            // Return the game widget if it matches the specified class
            return GameWidget;
        }
    }

    // Return nullptr if no matching widget is found
    return nullptr;
}

void AHUD_WidgetManager::ToggleNormalWidgetByClass(const TSubclassOf<UW_Base> WidgetClass)
{
    if (UW_Base::IsBackgroundWidgetByClass(WidgetClass))
    {
        UE_LOG(LogTemp, Error, TEXT("It is impossible to toggle a background widget"));
        return;
    }

    // Hide the current widget if it exists
    if (CurrentWidget)
    {
        CurrentWidget->SetVisibility(ESlateVisibility::Hidden);
        
        // If the target widget was the current one, the job is finished
        if (CurrentWidget->IsA(WidgetClass))
        {
            CurrentWidget = nullptr;
            return;
        }
    }
    
    // Get the new widget by class
    CurrentWidget = GetWidgetByClass(WidgetClass);
    if (CurrentWidget)
    {
        // Show the new widget
        CurrentWidget->SetVisibility(ESlateVisibility::Visible);

        //CurrentWidget->SetFocus();
        UE_LOG(LogHUD, Display, TEXT("Show widget by class: %s"), *WidgetClass->GetName());
    }
    else
    {
        // Log an error if the specified widget class is not found
        UE_LOG(LogHUD, Error, TEXT("Widget class not found: %s"), *WidgetClass->GetName());
    }
}

UW_Base* AHUD_WidgetManager::AddWidgetByClass(TSubclassOf<UW_Base> WidgetClass)
{
    
    if (const auto& GameWidget = GetWidgetByClass(WidgetClass))
    {
        UE_LOG(LogHUD, Warning, TEXT("Widget class is already in the HUD: %s"), *WidgetClass->GetName());
        return GameWidget;
    }
    
    // If it is possible, create and add widget to array and Viewport
    if (UW_Base* NewWidget = CreateWidget<UW_Base>(GetWorld(), WidgetClass))
    {
        if (UW_Base::IsBackgroundWidgetByClass(WidgetClass))
        {
            BackgroundWidgets.Add(NewWidget);
            NewWidget->AddToViewport(0);
            NewWidget->SetVisibility(ESlateVisibility::Visible);
        }
        else{
            NormalWidgets.Add(NewWidget);
            NewWidget->AddToViewport(10);
            NewWidget->SetVisibility(ESlateVisibility::Hidden);
        }
        return NewWidget;
    }

    UE_LOG(LogHUD, Error, TEXT("Fail to create widget from class: %s"), *WidgetClass->GetName());
    return nullptr;
}

void AHUD_WidgetManager::HideCurrentNormalWidget()
{
    // Hide the current widget if it exists
    if (CurrentWidget)
    {
        CurrentWidget->SetVisibility(ESlateVisibility::Hidden);
        CurrentWidget = nullptr;
    }
}
