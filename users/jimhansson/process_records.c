
#include "process_leader.h"
#include "keymap_swedish.h"
#include "shared_layers.h"
#include "casemodes.h"

bool __WEAK__ process_record_keymap(uint16_t keycode, keyrecord_t *record) {return true;};

#if defined(AUDIO_ENABLE) || defined(STENO_ENABLE)
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

void show_cfg_settings(void);

void show_cfg_settings() {
  SEND_STRING(SS_LWIN("r"));
  wait_ms(50);
  SEND_STRING("notepad");
  tap_code(KC_ENT);
  wait_ms(50);
  SEND_STRING("AS: ");
  get_autoshift_state() ? SEND_STRING("on") : SEND_STRING("off");
  SEND_STRING(" timeout: ");
  char display[8];
  snprintf(display, 8, "%d", get_generic_autoshift_timeout());
  send_string((const char*)display);
  tap_code(KC_ENT);
  SEND_STRING("COMBO: ");
  is_combo_enabled() ? SEND_STRING("on") : SEND_STRING("off");
  tap_code(KC_ENT);
  SEND_STRING("KEY OVERRIDE: ");
  key_override_is_enabled() ? SEND_STRING("on") : SEND_STRING("off");
  tap_code(KC_ENT);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if(!process_case_modes(keycode, record)) {
    return false; // else I get both the sep and a space.
  }
  
  switch(keycode) {
#ifdef STENO_ENABLE
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
#endif // STENO_ENABLE
  case EXT_CFG:
    if (record->event.pressed) {
      // handling both in same case, if I have entered cfg from plover
      // this might be odd but would be seldom..
#ifdef STENO_ENABLE
      layer_off(_PLOVER);
#endif
      layer_off(_CFG);
      return false;
      break;
    }
  case GAME_ON:
    if(record->event.pressed) {
      if(get_autoshift_state())
	autoshift_disable();
      if(is_combo_enabled())
	combo_disable();
      if(key_override_is_enabled())
	key_override_off();
    }
    break;
  case CAS_TOG:
    if(record->event.pressed) {
      toggle_caps_word();
    }
  case PRINT_CFG_SETTINGS:
    if(record->event.pressed)
      show_cfg_settings();
    return false;
    break;
  default:
    // pass on to keymap.
    return process_record_keymap(keycode, record);
  }
  return true;
}

