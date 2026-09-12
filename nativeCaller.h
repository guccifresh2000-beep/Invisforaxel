#pragma once
#include <citizen_lib.h>
#include <citizen/script/scriptContext.hpp>
#include <citizen/script/scriptTask.hpp>

#define CALL(NATIVE, ...) \
    SCRIPT::GET_NATIVE_HANDLER(NATIVE)(##__VA_ARGS__)

// Inline wrappers for common natives
inline void SetEntityVisible(Ped ped, bool vis, bool p2) {
    CALL(0x83F7251F7B3929C5, ped, vis, p2);
}

inline void SetEntityAlpha(Ped ped, int alpha, bool p2) {
    CALL(0x29666A007B36A00D, ped, alpha, p2);
}

inline void ShowPlayerNameTagStream(Player player, bool vis) {
    CALL(0x1BDF6B31F6993E93, player, vis);
}

inline void NetworkSetEntityVisible(Ped ped, bool vis, bool p2) {
    CALL(0x96B32C508877F85C, ped, vis, p2);
}

inline void NetworkSetPedVisible(Ped ped, bool vis) {
    CALL(0x96B32C508877F85C, ped, vis);
}

inline void SetPedCanRagdoll(Ped ped, bool ragdoll) {
    CALL(0x7C285B7836D980D2, ped, ragdoll);
}

inline void SetEntityCollision(Ped ped, bool collision, bool p2) {
    CALL(0x5F9B85F4109A097C, ped, collision, p2);
}

inline void SetEntityLodDist(Ped ped, int dist) {
    CALL(0x29666A007B36A00D, ped, dist);
}

inline void SetLocalPlayerNameTagVisibility(bool vis) {
    CALL(0x8B8C2A11F72B8A7C, vis);
}
