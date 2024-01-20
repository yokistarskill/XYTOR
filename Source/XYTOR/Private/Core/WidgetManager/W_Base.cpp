// XYTOR. All Rights Reserved.


#include "Core/WidgetManager/W_Base.h"

#include "Core/WidgetManager/Widgets/W_BackgroundBase.h"


bool UW_Base::IsBackgroundWidget() const
{
    return bIsBackground;
}

bool UW_Base::IsBackgroundWidgetByClass(TSubclassOf<UW_Base> WidgetClass)
{
       
    if (WidgetClass->IsChildOf(UW_BackgroundBase::StaticClass()))
        return true;
    return false;
}
