/*
    Plugin-SDK (Grand Theft Auto IV) source file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#include "CWanted.h"

static uint32_t CWanted__SetMaximumWantedLevelAddr;
void CWanted::SetMaximumWantedLevel(int32_t level) {
    plugin::CallDyn(CWanted__SetMaximumWantedLevelAddr, level);
}

template<>
void plugin::InitPatterns<CWanted>() {
    CWanted__SetMaximumWantedLevelAddr = plugin::GetPattern("8B 44 24 04 83 F8 06 0F 87 ? ? ? ? FF 24 85 ? ? ? ? C7 05", 0);
}
