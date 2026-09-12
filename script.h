#pragma once
#include <citizen_lib.h>

namespace SCRIPT
{
    inline void Wait(int ms)
    {
        citizen::script::Yield(ms);
    }
    
    inline void CreateThread(std::function<void()> func)
    {
        std::make_shared<fx::ScriptThread>(func, "Thread")->Run();
    }
}





