// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SceneItem.generated.h"

class UBoxComponent;
class UAC_PickUpHandler;
class UAC_Interact;

UCLASS(BlueprintType)
class XYTOR_API ASceneItem : public AActor
{
    GENERATED_BODY()

public:
    ASceneItem();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    FName ItemName;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UBoxComponent* BoxComponent;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USkeletalMeshComponent* MeshComponent;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UAC_PickUpHandler* PickUpComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UAC_Interact* InteractConfig;

public:
    void Init(FName Name, int32 Count) const;
    
};