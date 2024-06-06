// XYTOR. All Rights Reserved.


#include "Core/QuestSystem/Objects/Subquest.h"

#include "Core/QuestSystem/E_SubquestType.h"
#include "Core/QuestSystem/Objects/Subquest_Item.h"
#include "Core/QuestSystem/Objects/Subquest_Token.h"

bool USubquest::Init(const FS_Subquest& SubquestInfo)
{
    const bool bInitialised = InitByName(SubquestInfo.DataName);
    if (!bInitialised)
        return false;

    this->Data = SubquestInfo;
    return true;
}

bool USubquest::IsComplete() const
{
    return bComplete;
}

bool USubquest::Update(EE_SubquestType Type, const APS_Quests* PlayerState)
{
    if (Data.Type == Type)
        return Update(PlayerState);
    return false;
}

USubquest* USubquest::MakeSubquest(const FS_Subquest& Data, UObject* Parent)
{
    switch (Data.Type)
    {
        case EE_SubquestType::Token:
        {
            USubquest_Token* Subquest = NewObject<USubquest_Token>(Parent, USubquest_Token::StaticClass());
            if (!Subquest->Init(Data))
                return nullptr;
            return Subquest;
        }
        case EE_SubquestType::Item:
        {
            USubquest_Item* Subquest = NewObject<USubquest_Item>(Parent, USubquest_Item::StaticClass());
            if (!Subquest->Init(Data))
                return nullptr;
            return Subquest;
        }
    }
    return nullptr;
}