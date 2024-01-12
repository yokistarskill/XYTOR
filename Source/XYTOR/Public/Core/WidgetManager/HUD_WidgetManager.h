// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HUD_WidgetManager.generated.h"

class UUserWidget;

/**
 * Widget Manager. Provides access to created widgets.
 * Can show and hide the current widget.
 */
UCLASS()
class XYTOR_API AHUD_WidgetManager : public AHUD
{
    GENERATED_BODY()

protected:
    /** Array storing widget classes for instantiation */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HUD")
    TArray<TSubclassOf<UUserWidget>> GameWidgetClasses;

private:
    /** Array storing instantiated UserWidgets */
    UPROPERTY()
    TArray<UUserWidget*> GameWidgets;

    /** Currently visible widget */
    UPROPERTY()
    UUserWidget* CurrentWidget = nullptr;

protected:
    /**
     * Creates widgets and sets their visibility to hidden during BeginPlay.
     */
    virtual void BeginPlay() override;
    
public:
    /**
     * Retrieves the UserWidget pointer from the game widgets array based on the specified class.
     * @param WidgetClass   The specified class.
     * @return UUserWidget  The pointer to the UserWidget or nullptr if the widget class doesn't exist.
     */
    UFUNCTION(BlueprintCallable, Category = "HUD")
    UUserWidget* GetWidgetByClass(TSubclassOf<UUserWidget> WidgetClass) const;

    /**
     * Hides the current widget and shows a new one if it exists.
     * @param WidgetClass  The widget class.
     */
    UFUNCTION(BlueprintCallable, Category = "HUD")
    void ShowWidgetByClass(const TSubclassOf<UUserWidget> WidgetClass);
};