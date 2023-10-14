
#include "keymap_swedish.h"
#include "process_leader.h"

#include "shared_layers.h"

#include "casemodes.h"

/// leader stuff

void __WEAK__ matrix_scan_keymap(void) {;}
void __WEAK__ leader_start_keymap(void) {;}
void __WEAK__ leader_end_keymap(bool succeeded) {;}


// TODO: move this to a better location
void matrix_scan_user(void) {
  matrix_scan_keymap();
}


#ifdef AUDIO_ENABLE
float song_leader_start[][2] = SONG(CHROMATIC_SOUND);
float song_leader_succeed[][2] = SONG(MAJOR_SOUND);
float song_leader_fail[][2] = SONG(MINOR_SOUND);
#endif


void leader_start_user(void) {
#ifdef AUDIO_ENABLE
  PLAY_SONG(song_leader_start);
#endif
  leader_start_keymap();
}

void leader_end_user(void) {
  bool did_leader_succeed = false;

  if(leader_sequence_one_key(SE_U)) {
    enable_xcase_with(SE_UNDS);
    did_leader_succeed = true;
  } else if(leader_sequence_one_key(SE_MINS)) {
    enable_xcase_with(SE_MINS);
    did_leader_succeed = true;
  } else if(leader_sequence_one_key(SE_SLSH)) {
    enable_xcase_with(SE_SLSH);
    did_leader_succeed = true;
  } else if(leader_sequence_one_key(SE_COMM)) {
    enable_xcase_with(SE_COMM);
    did_leader_succeed = true;
  } else if(leader_sequence_one_key(SE_DOT)) {
    enable_xcase_with(SE_DOT);
    did_leader_succeed = true;
  } else if(leader_sequence_one_key(SE_Y)) {
    enable_xcase_with(SE_BSLS);
    did_leader_succeed = true;
  } else if(leader_sequence_one_key(SE_D)) {
    // easier to write defines.
    enable_xcase_with(SE_UNDS);
    enable_caps_word();
    did_leader_succeed = true;
  } else if(leader_sequence_two_keys(SE_A, SE_S)){
    // autoshift toggle
    autoshift_toggle();
    did_leader_succeed = true;
  } else if(leader_sequence_three_keys(SE_C, SE_A, SE_P)) {
    // cap = Caps lock
    register_code(KC_CAPS_LOCK);
    unregister_code(KC_CAPS_LOCK);
    did_leader_succeed = true;
  } else if(leader_sequence_four_keys(SE_C, SE_O, SE_N, SE_F)) {
    // switch to layer for configuration
    layer_on(_CFG);
    did_leader_succeed = true;
  } else if(leader_sequence_three_keys(SE_E, SE_S, SE_C)) {
    // ESC = escape key
    register_code(KC_ESC);
    unregister_code(KC_ESC);
    did_leader_succeed = true;
  } else if(leader_sequence_three_keys(SE_N, SE_U, SE_M)) {
    // num = num lock
    register_code(KC_NUM_LOCK);
    unregister_code(KC_NUM_LOCK);
    did_leader_succeed = true;
  } else if(leader_sequence_four_keys(SE_O, SE_V, SE_E, SE_R)) {
    // denna verkar ställa till med mycket problem.
    // i kombo med annat så ger det resets av hela kontrollern.
#ifdef KEY_OVERRIDE_ENABLE
    key_override_toggle();
    did_leader_succeed = true;
#endif
  } else if(leader_sequence_five_keys(SE_R, SE_E, SE_S, SE_E, SE_T)) {
    reset_keyboard();
    did_leader_succeed = true;
  } else if(leader_sequence_four_keys(SE_S, SE_C, SE_R, SE_L)) {
    // scrl = scroll lock
    register_code(KC_SCROLL_LOCK);
    unregister_code(KC_SCROLL_LOCK);
    did_leader_succeed = true;
  } else if(leader_sequence_five_keys(SE_S, SE_T, SE_E, SE_N, SE_O)) {
    // switch to steno layer
#ifdef STENO_ENABLE
    layer_on(_PLOVER);
    did_leader_succeed = true;
#endif
  } else if(leader_sequence_one_key(SE_X)) {
    // x-case
    enable_xcase();
    did_leader_succeed = true;
  }
  
#ifdef AUDIO_ENABLE  
  if (did_leader_succeed) {
    PLAY_SONG(song_leader_succeed);
  } else {
    PLAY_SONG(song_leader_fail);
  }
#endif

  leader_end_keymap(did_leader_succeed);
}
