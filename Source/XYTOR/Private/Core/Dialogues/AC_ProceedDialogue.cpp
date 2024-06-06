// XYTOR. All Rights Reserved.


#include "Core/Dialogues/AC_ProceedDialogue.h"

// Sets default values for this component's properties
UAC_ProceedDialogue::UAC_ProceedDialogue()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;

    // ...
}

void UAC_ProceedDialogue::BeginPlay()
{
    Super::BeginPlay();
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("BeginDialogue")));

}

void UAC_ProceedDialogue::ProceedDialogue(const UPlayerDialogueGraphNode* Node)
{
}