/*
    Plugin-SDK (Grand Theft Auto Vice City) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "PluginBase.h"
#include "C3dMarker.h"

class PLUGIN_API C3dMarkers {
public:
    SUPPORTED_10EN_11EN_STEAM static C3dMarker *m_aMarkerArray; // static C3dMarker m_aMarkerArray[32]
    static void PlaceMarkerSet(unsigned int id, unsigned short type, CVector& pos, float size, unsigned char r, unsigned char g, unsigned char b, unsigned char a, unsigned short pulsePeriod, float pulseFraction, short rotateRate);

};

