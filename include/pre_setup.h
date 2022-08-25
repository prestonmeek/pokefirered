#ifndef GUARD_PRE_SETUP_H
#define GUARD_PRE_SETUP_H

#include "global.h"
#include "battle.h"
#include "battle_scripts.h"
#include "battle_anim.h"
#include "constants/moves.h"

#define PRE_SPIKES_1 0
#define PRE_SETUP_TOTAL 1

void func_pre_spikes_1(u8 player, u8 playerSide, u8 enemy, u8 enemySide);

extern bool8 gPreSetupWasCalled[PRE_SETUP_TOTAL];

extern void (* const gPreSetupFuncs[PRE_SETUP_TOTAL])(u8 player, u8 playerSide, u8 enemy, u8 enemySide);

#endif