// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "W_Base.h"
#include "GameFramework/HUD.h"
#include "HUD_WidgetManager.generated.h"

/**
 * Widget Manager. Provides access to created widgets.
 * Can add normal and background widgets.
 * Can show and hide the current widget.
 */
UCLASS()
class XYTOR_API AHUD_WidgetManager : public AHUD
{
    GENERATED_BODY()

private:
    /** Array storing instantiated background UserWidgets */
    UPROPERTY(VisibleAnywhere)
    TArray<UW_Base*> BackgroundWidgets;

    /** Array storing instantiated normal UserWidgets */
    UPROPERTY(VisibleAnywhere)
    TArray<UW_Base*> NormalWidgets;
    
    /** Currently visible normal widget */
    UPROPERTY(VisibleAnywhere)
    UW_Base* CurrentWidget = nullptr;

    /**
     * Defines if the widget class is background or not. Returns the reference to the correct array.
     * Array can be modified.
     * @param WidgetClass   The specified class.
     * @return reference to NormalWidgets or BackgroundWidgets.
     */
    TArray<UW_Base*>& ChooseWidgets(TSubclassOf<UW_Base> WidgetClass);
    /**
     * Defines if the widget class is background or not. Returns the reference to the correct array.
     * Array can't be modified.
     * @param WidgetClass   The specified class.
     * @return reference to NormalWidgets or BackgroundWidgets.
     */
    const TArray<UW_Base*>& ChooseWidgets(TSubclassOf<UW_Base> WidgetClass) const;
protected:
    /**
     * Creates widgets and sets their visibility to hidden during BeginPlay.
     */
    virtual void BeginPlay() override;
    
public:
    /**
     * Retrieves the UserWidget pointer from the game widgets array based on the specified class.
     * @param WidgetClass   The specified class.
     * @return UW_Base  The pointer to the UserWidget or nullptr if the widget class doesn't exist.
     */
    UFUNCTION(BlueprintCallable, Category = "HUD")
    UW_Base* GetWidgetByClass(TSubclassOf<UW_Base> WidgetClass) const;

    /**
     * Hides the current widget and shows a new one if it exists.
     * If current widget is the target one, it hides.
     * @param WidgetClass  The widget class.
     */
    UFUNCTION(BlueprintCallable, Category = "HUD")
    void ToggleNormalWidgetByClass(const TSubclassOf<UW_Base> WidgetClass);

    /**
     * Adds a widget and returns the new one.
     * @param WidgetClass  The widget class.
     * @return UW_Base* pointer to the new widget.
     */
    UFUNCTION(BlueprintCallable, Category = "HUD")
    UW_Base* AddWidgetByClass(TSubclassOf<UW_Base> WidgetClass);

    /**
     * Hide current widget if it exists.
     */
    UFUNCTION(BlueprintCallable, Category = "HUD")
    void HideCurrentNormalWidget();
};