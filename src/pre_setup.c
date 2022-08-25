#include "pre_setup.h"

void func_pre_spikes_1(u8 player, u8 playerSide, u8 enemy, u8 enemySide) 
{
    // Sets the spikes
    gSideStatuses[player] |= SIDE_STATUS_SPIKES;
    gSideTimers[playerSide].spikesAmount = 1;

    // Spikes animation
    gCurrentMove = MOVE_SPIKES;
    BattleScriptPushCursorAndCallback(BattleScript_SpikesSetBeforeBattle);
}

void (* const gPreSetupFuncs[PRE_SETUP_TOTAL])(u8 player, u8 playerSide, u8 enemy, u8 enemySide) = 
{
    func_pre_spikes_1                   // 0x01
};