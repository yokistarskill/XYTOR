// XYTOR. All Rights Reserved.

#include "Core/WidgetManager/HUD_WidgetManager.h"
#include "Blueprint/UserWidget.h"

DEFINE_LOG_CATEGORY_STATIC(LogHUD, All, All)

void AHUD_WidgetManager::BeginPlay()
{
    Super::BeginPlay();

    // Create widgets for each widget class stored
    for (const auto WidgetClass : GameWidgetClasses)
    {
        GameWidgets.Add(CreateWidget<UUserWidget>(GetWorld(), WidgetClass));
    }

    // Add all game widgets to the viewport and set visibility to hidden
    for (const auto GameWidget : GameWidgets)
    {
        if (!GameWidget) continue;

        GameWidget->AddToViewport();
        GameWidget->SetVisibility(ESlateVisibility::Hidden);
    }
}

UUserWidget* AHUD_WidgetManager::GetWidgetByClass(TSubclassOf<UUserWidget> WidgetClass) const
{
    // Iterate through the array of game widgets
    for (const auto GameWidget : GameWidgets)
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

void AHUD_WidgetManager::ShowWidgetByClass(const TSubclassOf<UUserWidget> WidgetClass)
{
    // Hide the current widget if it exists
    if (CurrentWidget)
    {
        CurrentWidget->SetVisibility(ESlateVisibility::Hidden);
    }

    // Get the new widget by class
    CurrentWidget = GetWidgetByClass(WidgetClass);

    if (CurrentWidget)
    {
        // Show the new widget
        CurrentWidget->SetVisibility(ESlateVisibility::Visible);
        UE_LOG(LogHUD, Display, TEXT("Show widget by class: %s"), *WidgetClass->GetName());
    }
    else
    {
        // Log an error if the specified widget class is not found
        UE_LOG(LogHUD, Error, TEXT("Widget class not found: %s"), *WidgetClass->GetName());
    }
}