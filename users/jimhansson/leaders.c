
#include "keymap_swedish.h"
#include "process_leader.h"


#include "shared_layers.h"

#include "casemodes.h"

/// leader stuff

bool did_leader_succeed; // used in leader_start/end_keymap functions

LEADER_EXTERNS();
void __WEAK__ matrix_scan_keymap(void) {;}
void __WEAK__ leader_start_keymap(void) {;}
void __WEAK__ leader_end_keymap(bool succeeded) {;}

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    did_leader_succeed = leading = false;

    SEQ_ONE_KEY(SE_U) {
      enable_xcase_with(SE_UNDS);
      did_leader_succeed = true;
    }
    SEQ_ONE_KEY(SE_MINS) {
      enable_xcase_with(SE_MINS);
      did_leader_succeed = true;
    }
    SEQ_ONE_KEY(SE_SLSH) {
      enable_xcase_with(SE_SLSH);
      did_leader_succeed = true;
    }
    SEQ_ONE_KEY(SE_COMM) {
      enable_xcase_with(SE_COMM);
      did_leader_succeed = true;
    }
    SEQ_ONE_KEY(SE_DOT) {
      enable_xcase_with(SE_DOT);
      did_leader_succeed = true;
    }
    SEQ_ONE_KEY(SE_Y) {
      enable_xcase_with(SE_BSLS);
      did_leader_succeed = true;
    }
    
    SEQ_ONE_KEY(SE_D) {  // eisier to write defines.  
      enable_xcase_with(SE_UNDS);
      enable_caps_word();
      did_leader_succeed = true;
    }   

    SEQ_TWO_KEYS(SE_A, SE_S){ // autoshift toggle
      autoshift_toggle();
      did_leader_succeed = true;
    }
   
    SEQ_THREE_KEYS(SE_C, SE_A, SE_P) { // cap = Caps lock
      register_code(KC_CAPS_LOCK);
      unregister_code(KC_CAPS_LOCK);
      did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(SE_C, SE_O, SE_N, SE_F) {
      // switch to layer for configuration
      layer_on(_CFG);
      did_leader_succeed = true;
    }
    
    SEQ_THREE_KEYS(SE_E, SE_S, SE_C) { // esc = escape
      // ESC = escape key
      register_code(KC_ESC);
      unregister_code(KC_ESC);
      did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(SE_N, SE_U, SE_M) { // num = num lock
      register_code(KC_NUM_LOCK);
      unregister_code(KC_NUM_LOCK);
      did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(SE_O, SE_V, SE_E, SE_R) {
      key_override_toggle();
      did_leader_succeed = true;
    }

    SEQ_FIVE_KEYS(SE_R, SE_E, SE_S, SE_E, SE_T) {
      reset_keyboard();
      did_leader_succeed = true;
    }

    SEQ_FOUR_KEYS(SE_S, SE_C, SE_R, SE_L) { // scrl = scroll lock
      register_code(KC_SCROLL_LOCK);
      unregister_code(KC_SCROLL_LOCK);
      did_leader_succeed = true;
    }
#ifdef STENO_ENABLE
    SEQ_FIVE_KEYS(SE_S, SE_T, SE_E, SE_N, SE_O) {
      // switch to steno layer
      layer_on(_PLOVER);
      did_leader_succeed = true;
    }
#endif

    SEQ_ONE_KEY(SE_X) { // x-case
      enable_xcase();
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
