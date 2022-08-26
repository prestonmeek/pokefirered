#ifndef GUARD_PRE_SETUP_H
#define GUARD_PRE_SETUP_H

#include "global.h"
#include "battle.h"
#include "battle_scripts.h"
#include "battle_anim.h"
#include "battle_string_ids.h"
#include "constants/moves.h"

// Flags
#define PRE_SPIKES_1    (1 << 0)
#define PRE_SPIKES_2    (1 << 1)
#define PRE_SPIKES_3    (1 << 2)
#define PRE_REFLECT     (1 << 3)
#define PRE_SETUP_TOTAL 4

// Util functions
void pre_spikes(u8 amount, u8 enemy);

// Flag-based functions
void func_pre_spikes_1(u8 enemy);
void func_pre_spikes_2(u8 enemy);
void func_pre_spikes_3(u8 enemy);
void func_pre_reflect(u8 enemy);

// Table that checks if a flag has been called or not already
// We can't just unset the flag because they are read-only
extern bool8 gPreSetupWasCalled[PRE_SETUP_TOTAL];

// Function table
extern void (* const gPreSetupFuncs[PRE_SETUP_TOTAL])(u8 enemy);

#endif