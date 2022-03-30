
#include "process_leader.h"
#include "keymap_swedish.h"
#include "shared_layers.h"

bool __WEAK__ process_record_keymap(uint16_t keycode, keyrecord_t *record) {return true;};

#if defined(AUDIO_ENABLE) || defined(STENO_ENABLE)
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
  default:
    // pass on to keymap.
    return process_record_keymap(keycode, record);
  }
  return true;
}

