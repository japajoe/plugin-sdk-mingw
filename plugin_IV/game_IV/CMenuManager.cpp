/*
    Plugin-SDK (Grand Theft Auto IV) source file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#include "CMenuManager.h"
#include "Patch.h"

static CSprite2d* CMenuManager__Frontend360SpritesAddr;
CSprite2d* CMenuManager::Frontend360Sprites = (CSprite2d*)CMenuManager__Frontend360SpritesAddr; // [10]

static CSprite2d* CMenuManager__MouseCursorSprite;
CSprite2d& CMenuManager::MouseCursorSprite = *(CSprite2d*)CMenuManager__MouseCursorSprite;

static CSprite2d* CMenuManager__ReplayPointerSpriteAddr;
CSprite2d& CMenuManager::ReplayPointerSprite = *(CSprite2d*)CMenuManager__ReplayPointerSpriteAddr;

static CSprite2d* CMenuManager__ReplayPointerSprite2Addr;
CSprite2d& CMenuManager::ReplayPointerSprite2 = *(CSprite2d*)CMenuManager__ReplayPointerSprite2Addr;

static CSprite2d* CMenuManager__ControllerSpriteAddr;
CSprite2d& CMenuManager::ControllerSprite = *(CSprite2d*)CMenuManager__ControllerSpriteAddr;

static CSprite2d* CMenuManager__MapSpritesAddr;
CSprite2d* CMenuManager::MapSprites = (CSprite2d*)CMenuManager__MapSpritesAddr; // [4]

static int32_t* CMenuManager__m_PrefsAspectRatio;
int32_t& CMenuManager::m_PrefsAspectRatio = *(int32_t*)CMenuManager__m_PrefsAspectRatio;

static int32_t* CMenuManager__m_PrefsLanguage;
int32_t& CMenuManager::m_PrefsLanguage = *(int32_t*)CMenuManager__m_PrefsLanguage;

static int32_t* CMenuManager__m_PrefsUseVibration;
int32_t& CMenuManager::m_PrefsUseVibration = *(int32_t*)CMenuManager__m_PrefsUseVibration;

static bool* CMenuManager__m_MenuActive;
bool& CMenuManager::m_MenuActive = *(bool*)CMenuManager__m_MenuActive;

static int32_t* CMenuManager__m_nWaypointIndexAddr;
int32_t& CMenuManager::m_nWaypointIndex = *(int32_t*)CMenuManager__m_nWaypointIndexAddr;

template<>
void plugin::InitPatterns<CMenuManager>() {
    CMenuManager__Frontend360SpritesAddr = (CSprite2d*)plugin::patch::GetPointer(plugin::GetPattern("BE ? ? ? ? 8B CE E8 ? ? ? ? 83 C6 04 81 FE ? ? ? ? 7C EE E8 ? ? ? ? 83 FF FF 74 47", 1));

    CMenuManager__MouseCursorSprite = (CSprite2d*)plugin::patch::GetPointer(plugin::GetPattern("B9 ? ? ? ? 68 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? E8", 1));
    CMenuManager__ReplayPointerSpriteAddr = (CSprite2d*)plugin::patch::GetPointer(plugin::GetPattern("B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? E8", 1));
    CMenuManager__ReplayPointerSprite2Addr = (CSprite2d*)plugin::patch::GetPointer(plugin::GetPattern("B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? E8", 1));
    CMenuManager__ControllerSpriteAddr = (CSprite2d*)plugin::patch::GetPointer(plugin::GetPattern("B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? E8", 1));
    CMenuManager__MapSpritesAddr = (CSprite2d*)plugin::patch::GetPointer(plugin::GetPattern("B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? E8", 1));

    CMenuManager__m_PrefsAspectRatio = (int32_t*)plugin::patch::GetPointer(plugin::GetPattern("C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? 33 F6", 2));
    CMenuManager__m_PrefsLanguage = (int32_t*)plugin::patch::GetPointer(plugin::GetPattern("A3 ? ? ? ? A3 ? ? ? ? 75 5E", 1));
    CMenuManager__m_PrefsUseVibration = (int32_t*)plugin::patch::GetPointer(plugin::GetPattern("C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? A3 ? ? ? ? C7 05", 2));

    CMenuManager__m_MenuActive = (bool*)plugin::patch::GetPointer(plugin::GetPattern("C6 05 ? ? ? ? ? C6 05 ? ? ? ? ? C6 05 ? ? ? ? ? 5E C3 CC CC CC CC CC CC CC CC CC CC", 2));
    CMenuManager__m_nWaypointIndexAddr = (int32_t*)plugin::patch::GetPointer(plugin::GetPattern("C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? F3 0F 11 05 ? ? ? ? 8B 01", 2));
}
