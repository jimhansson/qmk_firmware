
//#include "process_combo.h"
//#include "quantum/action_util.h"
#include "quantum/quantum.h"

#include "shared_layers.h"

// mainly use combos to avoid having to leave homerow to use
// modifiers, will use one-shot-modifiers for that

// med denna kanske jag inte behöver använda mig av oneshot_mods utan
// istället sköter combo det för mig
//#define COMBO_MUST_HOLD_MODS

// - COMBO_TERM_PER_COMBO
//   uint16_t get_combo_term(uint16_t index, combo_t *combo)
//   Optional per-combo timeout window. (default: COMBO_TERM)
// - COMBO_MUST_HOLD_PER_COMBO
//   bool get_combo_must_hold(uint16_t index, combo_t *combo)
//   Controls if a given combo should fire immediately on tap or if it needs to be held. (default: false)
// - COMBO_MUST_TAP_PER_COMBO
//   bool get_combo_must_tap(uint16_t index, combo_t *combo)
//   Controls if a given combo should fire only if tapped within COMBO_HOLD_TERM. (default: false)
// - COMBO_MUST_PRESS_IN_ORDER_PER_COMBO
//   bool get_combo_must_press_in_order(uint16_t index, combo_t *combo)
//   Controls if a given combo should fire only if its keys are pressed in order. (default: true)

    /* OSM(mod) - Momentarily hold down mod. You must use the MOD_* keycodes as shown in Mod Tap, not the KC_* codes. */
    /* OSL(layer) - momentary switch to layer. */
    /* OS_ON - Turns on One Shot keys. */
    /* OS_OFF - Turns off One Shot keys. OSM act as regular mod keys, OSL act like MO. */
    /* OS_TOGG - Toggles the one shot key status. */
/*
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // Disable combo `SOME_COMBO` on layer `_LAYER_A`
    switch (combo_index) {
        case SOME_COMBO:
            if (layer_state_is(_LAYER_A)) {
                return false;
            }
    }

    return true;
}
*/

// #define COMBO_ONLY_FROM_LAYER _LAYER_A


// Normally, the timer is started on the first key press and then
// reset on every subsequent key press within the
// COMBO_TERM. Inputting combos is relaxed like this, but also
// slightly more prone to accidental misfires. 

// The next two options alter the behaviour of the timer.
// #define COMBO_STRICT_TIMER

// With COMBO_STRICT_TIMER, the timer is started only on the first key
// press. Inputting combos is now less relaxed; you need to make sure
// the full chord is pressed within the COMBO_TERM. Misfires are less
// common but if you type multiple combos fast, there is a chance that
// the latter ones might not activate properly.

//#define COMBO_NO_TIMER

// By defining COMBO_NO_TIMER, the timer is disabled completely and
// combos are activated on the first key release. This also disables
// the “must hold” functionalities as they just wouldn’t work at all.

// RIGHT
// R3
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
// R2
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
//const uint16_t PROGMEM lö_combo[] = {KC_L, SE_Ö, COMOBO_END};


// LEFT
// R3
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
// R2
const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};

combo_t key_combos[] = {
  [CMB_LCTL] = COMBO_ACTION(df_combo),
  [CMB_RCTL] = COMBO_ACTION(jk_combo),
  [CMB_LALT] = COMBO_ACTION(sd_combo),
  [CMB_RALT] = COMBO_ACTION(kl_combo),
  [CMB_INS]  = COMBO_ACTION(io_combo),
  [CMB_DEL]  = COMBO_ACTION(we_combo),
};


void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
  case CMB_LALT:
    if (pressed) {
      set_oneshot_mods(MOD_LALT);
    }
    break;
  case CMB_LCTL:
    if (pressed) {
      set_oneshot_mods(MOD_LCTL);
    }
    break;
  case CMB_RALT:
    if (pressed) {
      set_oneshot_mods(MOD_RALT);
    }
    break;
  case CMB_RCTL:
    if (pressed) {
      set_oneshot_mods(MOD_RCTL);
    }
    break;
  case CMB_INS:
    if(pressed) {
      tap_code16(KC_INS);
    }
    break;
  case CMB_DEL:
    if(pressed) {
      tap_code16(KC_DEL);
    }
    break;
  }
}
