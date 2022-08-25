#ifndef GUARD_PRE_SETUP_H
#define GUARD_PRE_SETUP_H

#include "global.h"
#include "battle.h"
#include "battle_scripts.h"
#include "battle_anim.h"
#include "constants/moves.h"

#define PRE_SPIKES_1 (1 << 0)
#define PRE_SPIKES_2 (1 << 1)
#define PRE_SPIKES_3 (1 << 2)
#define PRE_SETUP_TOTAL 3

void pre_spikes(u8 amount, u8 player, u8 playerSide, u8 enemy, u8 enemySide);

void func_pre_spikes_1(u8 player, u8 playerSide, u8 enemy, u8 enemySide);
void func_pre_spikes_2(u8 player, u8 playerSide, u8 enemy, u8 enemySide);
void func_pre_spikes_3(u8 player, u8 playerSide, u8 enemy, u8 enemySide);

extern bool8 gPreSetupWasCalled[PRE_SETUP_TOTAL];

extern void (* const gPreSetupFuncs[PRE_SETUP_TOTAL])(u8 player, u8 playerSide, u8 enemy, u8 enemySide);

#endif