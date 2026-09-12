#include "InvisibilityManager.h"
#include <citizen_lib.h>

namespace InvisibilityManager
{
    void Toggle()
    {
        IsHidden = !IsHidden;
    }

    void Update(Ped ped)
    {
        if (IsHidden != LastState)
        {
            ApplyState(ped, IsHidden);
            LastState = IsHidden;
        }
    }

    void ApplyState(Ped ped, bool hide)
    {
        // Hide model
        ENTITY::SET_ENTITY_VISIBLE(ped, !hide, false);
        
        // Hide name tags globally
        HUD::SHOW_PLAYER_NAME_TAG_STREAM(PLAYER::PLAYER_ID(), !hide);
        
        // Hide own name tag
        GRAPHICS::SET_LOCAL_PLAYER_NAME_TAG_VISIBILITY(!hide);

        // Network visibility (Anti-cheat bypass)
        NETWORK::NETWORK_SET_ENTITY_VISIBLE(ped, !hide, true);
        NETWORK::NETWORK_SET_PED_VISIBLE(ped, !hide);

        // Entity properties
        if (hide)
        {
            ENTITY::SET_ENTITY_ALPHA(ped, 0, false);
            ENTITY::SET_ENTITY_COLLISION(ped, true, false); // Keep collision to avoid falling through
            PED::SET_PED_CAN_RAGDOLL(ped, false);
            GRAPHICS::SET_ENTITY_LOD_DIST(ped, 0);
        }
        else
        {
            ENTITY::SET_ENTITY_ALPHA(ped, 255, false);
            ENTITY::SET_ENTITY_COLLISION(ped, true, true);
            PED::SET_PED_CAN_RAGDOLL(ped, true);
            GRAPHICS::SET_ENTITY_LOD_DIST(ped, 999999);
        }
    }
}


NoTrack AI — https://notrack.ai/
