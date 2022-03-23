
#include "process_leader.h"
#include "keymap_swedish.h"
#include "shared_layers.h"

bool __WEAK__ process_record_keymap(uint16_t keycode, keyrecord_t *record) {return true;};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
  case PLOVER:
    if (record->event.pressed) {
#ifdef AUDIO_ENABLE
      stop_all_notes();
      PLAY_SONG(plover_song);
#endif
      layer_on(_PLOVER);
      if (!eeconfig_is_enabled()) {
	eeconfig_init();
      }
      keymap_config.raw = eeconfig_read_keymap();
      keymap_config.nkro = 1;
      eeconfig_update_keymap(keymap_config.raw);
    }
    return false;
    break;
  case EXT_PLV:
#ifdef AUDIO_ENABLE
    if (record->event.pressed)
      PLAY_SONG(plover_gb_song);
#endif
  case EXT_CFG:
    if (record->event.pressed) {
      // handling both in same case, if I have entered cfg from plover
      // this might be odd but would be seldom..
      layer_off(_PLOVER);
      layer_off(_CFG);
      return false;
      break;
    }
  default:
    // pass on to keymap.
    return process_record_keymap(keycode, record);
  }
  return true;
}


/// leader stuff

bool did_leader_succeed; // used in leader_start/end_keymap functions

LEADER_EXTERNS();
void __WEAK__ matrix_scan_keymap(void) {;}
void __WEAK__ leader_start_keymap(void) {;}
void __WEAK__ leader_end_keymap(bool succeeded) {;}

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    did_leader_succeed = leading = false;

    SEQ_FOUR_KEYS(SE_C, SE_O, SE_N, SE_F) {
      // switch to layer for configuration
      layer_on(_CFG);
      did_leader_succeed = true;
    }

    // keep the sequences in order
    SEQ_TWO_KEYS(KC_D, KC_D) {
      SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
      did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
      SEND_STRING("https://start.duckduckgo.com\n");
      did_leader_succeed = true;
    }

    SEQ_THREE_KEYS(SE_E, SE_S, SE_C) {
      // ESC = escape key
      register_code(KC_ESC);
      unregister_code(KC_ESC);
      did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(SE_E, SE_S, SE_D) {
      // ESC = escape key
      register_code(KC_ESC);
      unregister_code(KC_ESC);
      did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(SE_E, SE_S, SE_E) {
      // ESC = escape key
      register_code(KC_ESC);
      unregister_code(KC_ESC);
      did_leader_succeed = true;
    }

    SEQ_THREE_KEYS(SE_E, SE_S, SE_F) {
      // ESC = escape key
      register_code(KC_ESC);
      unregister_code(KC_ESC);
      did_leader_succeed = true;
    }

    SEQ_FIVE_KEYS(SE_R, SE_E, SE_S, SE_E, SE_T) {
      reset_keyboard();
      did_leader_succeed = true;
    }
    SEQ_FIVE_KEYS(SE_S, SE_T, SE_E, SE_N, SE_O) {
      // switch to steno layer
      layer_on(_PLOVER);
      did_leader_succeed = true;
    }

    leader_end();
  }
  matrix_scan_keymap();
}

void leader_start(void) {
  leader_start_keymap();
}

void leader_end(void) {
  leader_end_keymap(did_leader_succeed);
}
