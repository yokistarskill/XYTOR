// XYTOR. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Inventory/Objects/Item.h"
// #include "ExtraTools.generated.h"
//
// #define DECLARE_COUNTER_STRUCT(VALUE_TYPE, STRUCT_NAME) \
//     USTRUCT() \
//     struct STRUCT_NAME \
//     { \
//         GENERATED_BODY()\
//         UPROPERTY()\
//         VALUE_TYPE Value;\
//         int32 Count;\
//     }
//
//
// DECLARE_COUNTER_STRUCT(UItem*, FCounterItem);

namespace ExtraTools
{

    template<typename StructureType>
    StructureType* GetStructureFromTable(const FString& Path, FName RowName)
    {
        if (const UDataTable* Table = LoadObject<UDataTable>(nullptr, *Path))
        {
            return Table->FindRow<StructureType>(RowName, "");
        }
        
        UE_LOG(LogTemp, Error, TEXT("Failed to load DataTable: %s"), *Path);
        return nullptr;
    }
}
