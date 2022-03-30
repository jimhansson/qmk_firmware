
#include "process_combo.h"

// mainly use combos to avoid having to leave homerow to use
// modifiers, will use one-shot-modifiers for that


const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
//const uint16_t PROGMEM lö_combo[] = {KC_L, SE_Ö, COMOBO_END};

const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};

enum combos {
  CMB_LCTL = 0,
  CMB_RCTL,
  CMB_LALT,
  CMB_RALT,
  COMBO_LENGTH,
};

combo_t key_combos[COMBO_LENGTH] = {
  [CMB_LCTL] = COMBO_ACTION(df_combo),
  [CMB_RCTL] = COMBO_ACTION(jk_combo),
  [CMB_LALT] = COMBO_ACTION(sd_combo),
  [CMB_RALT] = COMBO_ACTION(kl_combo),
};

uint16_t COMBO_LEN = COMBO_LENGTH;

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
  }
}
