#pragma once
#include <citizen_lib.h>
#include <citizen/script/scriptContext.hpp>
#include <citizen/script/scriptTask.hpp>

namespace InvisibilityManager
{
    bool IsHidden = false;
    bool LastState = false;

    void Toggle();
    void Update(Ped ped);
    void ApplyState(Ped ped, bool hide);
}
