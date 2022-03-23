
#pragma once

//#include <stdbool.h>
#define __WEAK__ __attribute__((weak))

// Fix Space Cadet keys for swedish layout
#define LSPO_KEYS KC_LSFT, KC_LSFT, KC_8
#define RSPC_KEYS KC_RSFT, KC_RSFT, KC_9

// make sure we can press as many buttons as possible at the same time.
#define FORCE_NKRO

//#define NO_ACTION_TAPPING

#define NO_ACTION_ONESHOT

// auto shift //
// if we want to auto-shift anything else than the alphas,
// we will do that in the keymap instead.
#define AUTO_SHIFT_TIMEOUT 200
#define NO_AUTO_SHIFT_NUMERIC
#define NO_AUTO_SHIFT_SPECIAL
#define AUTO_SHIFT_REPEAT

// leader key
#define LEADER_TIMEOUT 250
#define LEADER_PER_KEY_TIMING

// we dont have space for that
#define NO_MUSIC_MODE

#define NO_ACTION_FUNCTION

// dont think this does anything
#define NO_ACTION_MACRO

// not real, have stash for it
#define NO_STENO_GEMINI
