/*
    Plugin-SDK (Grand Theft Auto IV) source file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#include "CViewportRadar.h"
#include "Patch.h"

static uint32_t CViewportRadar__CViewportRadar;
CViewportRadar::CViewportRadar() {
    plugin::CallDyn(CViewportRadar__CViewportRadar);
}
