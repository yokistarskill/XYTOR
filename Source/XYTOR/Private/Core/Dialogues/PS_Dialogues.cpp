// XYTOR. All Rights Reserved.


#include "Core/Dialogues/PS_Dialogues.h"

APS_Dialogues::APS_Dialogues()
{
    DialogueComponent = CreateDefaultSubobject<UAC_Dialogues>(TEXT("Dialogue"));
}

UAC_Dialogues* APS_Dialogues::GetDialogue() const
{
    return DialogueComponent;
}