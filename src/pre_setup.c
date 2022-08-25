#include "pre_setup.h"

void pre_spikes(u8 amount, u8 player, u8 playerSide, u8 enemy, u8 enemySide) {
    // Sets the spikes
    // I don't really get how this works, but the player has the SPIKES flag and the enemy has the SPIKES count (??)
    gSideStatuses[player] |= SIDE_STATUS_SPIKES;
    gSideTimers[enemySide].spikesAmount = amount;

    // Spikes animation
    gCurrentMove = MOVE_SPIKES;
    BattleScriptPushCursorAndCallback(BattleScript_SpikesSetBeforeBattle);
}

void func_pre_spikes_1(u8 player, u8 playerSide, u8 enemy, u8 enemySide) 
{
    pre_spikes(1, player, playerSide, enemy, enemySide);
}

void func_pre_spikes_2(u8 player, u8 playerSide, u8 enemy, u8 enemySide) 
{
    pre_spikes(2, player, playerSide, enemy, enemySide);
}

void func_pre_spikes_3(u8 player, u8 playerSide, u8 enemy, u8 enemySide) 
{
    pre_spikes(3, player, playerSide, enemy, enemySide);
}

void (* const gPreSetupFuncs[PRE_SETUP_TOTAL])(u8 player, u8 playerSide, u8 enemy, u8 enemySide) = 
{
    func_pre_spikes_1,                   // 0x01
    func_pre_spikes_2,                   // 0x02
    func_pre_spikes_3,                   // 0x03
};