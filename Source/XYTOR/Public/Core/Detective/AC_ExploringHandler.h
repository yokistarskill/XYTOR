// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AC_InteractionHandler.h"
#include "W_EvidenceBase.h"
#include "Components/TextRenderComponent.h"
#include "Components/WidgetComponent.h"
#include "Core/Interaction/AC_Interact.h"
#include "AC_ExploringHandler.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class XYTOR_API UAC_ExploringHandler : public UAC_InteractionHandler
{
    GENERATED_BODY()
    inline static TSubclassOf<UW_EvidenceBase> WidgetClass = {};
    inline static UMaterialInterface* Material = nullptr;
protected:
    UPROPERTY(EditAnywhere)
    FText LongInfo;
    UPROPERTY(EditAnywhere)
    FText ShortInfo;

    UPROPERTY(VisibleAnywhere)
    UW_EvidenceBase* Widget = nullptr;
    UPROPERTY(VisibleAnywhere)
    UWidgetComponent* WidgetComponent = nullptr;
    mutable bool bHighlighted = false;

    void InitWidget();
    void DisplayShortInformation() const;
    void DisplayLongInformation() const;
    void ChangeInteractionComponent() const;
public:
    UAC_ExploringHandler();
    auto Detect(TSubclassOf<UW_EvidenceBase> WidgetClass) const -> void;
    void UnDetect() const;

    virtual void Interact(AActor* InteractingActor) override;
};
