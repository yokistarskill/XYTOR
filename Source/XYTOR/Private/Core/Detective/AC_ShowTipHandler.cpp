// XYTOR. All Rights Reserved.


#include "Core/Detective/AC_ShowTipHandler.h"

#include "Core/Detective/PC_Detective.h"

void UAC_ShowTipHandler::Interact(AActor* InteractingActor)
{
    // Super::Interact(InteractingActor);

    if (const APC_Detective* Controller = Cast<APC_Detective>(InteractingActor))
    {
        Controller->DisplayTip(TipText);
    }
    
}
