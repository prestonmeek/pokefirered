#include "pre_setup.h"

void pre_spikes(u8 amount, u8 enemy) {
    u8 enemySide = GetBattlerSide(enemy) ^ BIT_SIDE;

    // Sets the spikes
    gSideStatuses[enemySide] |= SIDE_STATUS_SPIKES;
    gSideTimers[enemySide].spikesAmount = amount;

    // Spikes animation
    gCurrentMove = MOVE_SPIKES;
    BattleScriptPushCursorAndCallback(BattleScript_PreSetup_Spikes);
}

void func_pre_spikes_1(u8 enemy) 
{
    pre_spikes(1, enemy);
}

void func_pre_spikes_2(u8 enemy) 
{
    pre_spikes(2, enemy);
}

void func_pre_spikes_3(u8 enemy) 
{
    pre_spikes(3, enemy);
}

void func_pre_reflect(u8 enemy)
{
    u8 enemySide = GET_BATTLER_SIDE(enemy);

    // Sets reflect
    gSideStatuses[enemySide] |= SIDE_STATUS_REFLECT;
    gSideTimers[enemySide].reflectTimer = 5;
    gSideTimers[enemySide].reflectBattlerId = enemy;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && CountAliveMonsInBattle(BATTLE_ALIVE_ATK_SIDE) == 2)
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SET_REFLECT_DOUBLE;
    else
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SET_REFLECT_SINGLE;

    // Reflect animation
    gCurrentMove = MOVE_REFLECT;
    BattleScriptPushCursorAndCallback(BattleScript_PreSetup_Reflect);
}

void (* const gPreSetupFuncs[PRE_SETUP_TOTAL])(u8 enemy) = 
{
    func_pre_spikes_1,                   // (1 << 0)
    func_pre_spikes_2,                   // (1 << 1)
    func_pre_spikes_3,                   // (1 << 2)
    func_pre_reflect,                    // (1 << 3)
};