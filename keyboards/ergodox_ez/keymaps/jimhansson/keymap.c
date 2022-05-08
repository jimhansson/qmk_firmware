
#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_swedish.h"
#include "keymap_steno.h"

#include "layers.h"
#include "shared_layers.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   !  |  "   |  #   |  #   |  %   |  L3  |           | L5   |   &  |  /   |  (   |  )   |  =   |  ?     |
 * |        |   1  |  2 @ |  3 £ |  4 $ |  5   |      |           | CMDS |   6  |  7 { |  8 [ |  9 ] |  0 } |  + \   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Delete |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L2  |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LEAD   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |Ö / L2|Ä / Cmd |
 * |        |      |      |      |      |      | Hyper|           | Meh  |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Left   |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ;  |   :  |_/Ctrl| RShift |
 * | Shift  |      |      |      |      |      |      |           |      |      |      |   ,  |   .  |-     |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | '/L1 |  `   |AltShf| Left | L2   |                                       |  L2  | Down |  ^   |  *   | ~L1  |
 *   |      |  '   |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | App  | LGui |       | AltGr|Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Enter|Back- |------|       |------|  Tab   |Space |
 *                                 |      |space | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  XXXXXXX,          SE_EXLM,        SE_DQUO,       SE_HASH, SE_CURR, SE_PERC,   TG(NUMB),         TG(CMDS),     SE_AMPR, SE_SLSH,   SE_LPRN,    SE_RPRN,    SE_EQL,               SE_PLUS,	  	 
  KC_DELT,          SE_Q,           SE_W,          SE_E,    SE_R,    SE_T,      TG(SYMB),	  TG(MDIA),     SE_Y,    SE_U,      SE_I,       SE_O,       SE_P,                 SE_ARNG,	   
  KC_LEAD,          SE_A,           SE_S,          SE_D,    SE_F,    SE_G,	       		                SE_H,    SE_J,      SE_K,       SE_L,       LT(MDIA, SE_ODIA),    GUI_T(SE_ADIA),  
  KC_LSPO,          CTL_T(SE_Z),    SE_X,          SE_C,    SE_V,    SE_B,  ALL_T(KC_NO),	  MEH_T(KC_NO), SE_N,    SE_M,      SE_COMM,    SE_DOT,     CTL_T(SE_MINS),       KC_RSPC,	   
  LT(SYMB,SE_QUOT), SE_ACUT,        LALT(KC_LSFT), KC_LEFT, TT(MDIA),				                     TT(MDIA),      KC_DOWN,    SE_CIRC,    SE_ASTR,              TT(SYMB),	   
                                                            ALT_T(KC_APP),       KC_LGUI,	  KC_ALGR,      CTL_T(KC_ESC),								   
                                                                                 KC_HOME,	  KC_PGUP,											   
                                                            KC_ENT,  KC_BSPC,    KC_END,          KC_PGDN,      KC_TAB,  KC_SPC                                                                      
),

/* Keymap 1: Symbol Layer
 *
 * regarding the right hand, mutch of it is to copy the numberpad, this means that we will
 * acctually send the specific keycodes for the numberpad and not use the keycode for the
 * number row, this also mean sth that the *, +, = and the other stuff are from the
 * numberpad. 
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   @  |   {  |   }  |   \  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   <  |   (  |   )  |   >  |   $  |------|           |------| Down |   4  |   5  |   6  |   +  |  -     |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   ^  |   [  |   ]  |   %  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   /  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|Bright|       |Toggle|Solid |
 *                                        |      |ness+ |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |Bright|       | Hue+ |.     |0     |
 *                                 |      |      |ness- |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       | Hue- |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   _______,     _______,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11, 
  _______,  SE_AT,    SE_LCBR,  SE_RCBR,  SE_BSLS,  SE_PIPE, _______,     _______,  KC_UP,    KC_P7,    KC_P8,    KC_P9,    KC_PAST,  KC_F12, 
  _______,  SE_LABK,  SE_LPRN,  SE_RPRN,  SE_RABK,  SE_DLR,	                    KC_DOWN,  KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  KC_PMNS,	     			       
  _______,  KC_CIRC,  SE_LBRC,  SE_RBRC,  KC_PERC,  SE_TILD, _______,     _______,  KC_AMPR,  KC_P1,    KC_P2,    KC_P3,    KC_PSLS,  _______,
  EPRM,     _______,  _______,  _______,  _______,		                            _______,  KC_PCMM,    KC_P0,    KC_PEQL,  _______,		     
                                                    RGB_MOD, RGB_VAI,     RGB_TOG,  RGB_SLD,						     	
                                                             RGB_VAD,     RGB_HUI,							     	
                                           _______, _______, _______,     RGB_HUD,  KC_DOT,   KC_P0                                          
),
/* Keymap 2: Media and mouse keys
 *
 * we could place kc_lock here somewhere and make it easy to select things with mouse controls
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |mwleft| MsUp |mwrigh| mwup |      |           |      |      | Home | Up   | End  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|mwdown|------|           |------| PgUp | Left | Down | Rght |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Lclk | Mclk | Rclk |      |      |           |      | PgDn |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, _______,     _______, _______, KC_HOME, KC_UP,    KC_END, _______, _______,
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,		              KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_MPLY,
  _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______,     _______, KC_PGDN, _______, KC_MPRV, KC_MNXT, _______, _______,
  _______, _______, _______, _______, _______,			                       KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                               _______, _______,     _______, _______,						
                                                        _______,     _______,							
                                      _______, _______, _______,     _______, _______, _______
),
/* Keymap 3: normal numbers
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  1   |  2   |  3   |   4  |  5   |      |           |      |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[NUMB] = LAYOUT_ergodox_pretty(
  // left hand                                                      // right hand							
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, 
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,		             _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,			                      _______, _______, _______, _______, _______,
                                               _______, _______,    _______, _______,						
                                                        _______,    _______,							
                                      _______, _______, _______,    _______, _______, _______                                       
),
/* Keymap 5: commands
 * 
 * This keymap is for complex commands that we would like to have
 * easier access to, things like the three finger salute needed to
 * login on windows and other stuff.
 */
[CMDS] = LAYOUT_ergodox_pretty(
       // left                                                            // right							     
       _______, _______, _______, _______, _______, _______, _______,	  _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,	  _______, _______, _______, _______, _______, _______, _______,
       _______, KC_SLCK, PRV_APP, NXT_APP, _______, _______,		           _______, _______, KILLX,   LOGIN,   _______, _______,
       _______, _______, _______, KC_CAPS, _______, _______, _______,	  _______, KC_NLCK, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,			                    _______, _______, _______, _______, _______,
                                                    _______, _______,	  _______, _______,					     
                                                             _______,	  _______,							     
                                           _______, _______, _______, 	  _______, _______, _______                                                 
),
#ifdef STENO_ENABLE
/* Keymap 4: TxBolt (Serial)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | BKSPC  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   #  |   #  |   #  |   #  |   #  |      |           |      |   #  |   #  |   #  |   #  |   #  |   #    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   S  |   T  |   P  |   H  |   *  |------|           |------|   *  |   F  |   P  |   L  |   T  |   D    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   S  |   K  |   W  |   R  |   *  |      |           |      |   *  |   R  |   B  |   G  |   S  |   Z    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   A  |   O  |------|       |------|   E  |   U  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_PLOVER] = LAYOUT_ergodox_pretty(
                        // Left hand                                         // right hand							
       KC_BSPC, _______, _______, _______, _______, _______, _______,      _______,  _______, _______, _______, _______, _______, _______,	
       KC_NO,   STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  KC_NO,        _______,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,	
       _______, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,	                     STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,	
       _______, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, KC_NO,        KC_NO,    STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,	
       EXT_PLV, _______, KC_NO,   KC_NO,   KC_NO,		                               KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,	
                                                    KC_NO,   KC_NO,	   KC_NO,   KC_NO,							
                                                             KC_NO,	   KC_NO,								
                                           STN_A,   STN_O,   KC_NO,	   KC_NO,   STN_E,   STN_U                                          
),
#endif
/* Keymap 6: Configuration
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  AS  |   #  |   #  |   #  |   #  |      |           |      |   #  |   #  |   #  |   #  |   #  |   #    |
 * |        |  UP  |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  AS  | COMBO| key  | Case |   #  |------|           |------|   #  |   #  |   #  |   #  |   #  |   #    |
 * |        |  TGL |  TGL | Overr| Modes|      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  AS  |   #  |   #  |   #  |   #  |      |           |      |   #  |   #  |   #  |   #  |   #  |   #    |
 * |        | DOWN |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | exit |  AS  |      |      |      |                                       |      |      |      |      |      |
 *   |      | RPRT |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   #  |   #  |------|       |------|   #  |   #  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'

 * 
 * This keymap is for complex commands that we would like to have
 * easier access to, things like the three finger salute needed to
 * login on windows and other stuff.
 */
[_CFG] = LAYOUT_ergodox_pretty(
       // left                                                            // right							     
       _______, _______, _______, _______, _______, _______, _______,	  _______, _______, _______, _______, _______, _______,   DEBUG,
       _______, KC_ASUP, _______, _______, _______, _______, _______,	  _______, _______, _______, _______, _______, _______, _______,
       _______,  AS_TOG, CMB_TOG, KEY_TOG, CAS_TOG, GAME_ON,		           _______, _______, _______, _______, _______, _______,
       _______, KC_ASDN, _______, _______, _______, _______, _______,	  _______, _______, _______, _______, _______, _______, _______,
       EXT_CFG, KC_ASRP, _______, _______, _______,			                    _______, _______, _______, _______, _______,
                                                    _______, _______,	  _______, _______,					     
                                                             _______,	  _______,							     
                                           _______, _______, _______, 	  _______, _______, _______                                                 
),
};
// clang-format on

// save layer_state_t so we can turn leds back after signaling other
// stuff with them. 
layer_state_t current_layer_state;
void set_leds_to_layer(layer_state_t state) {
  uint8_t layer = biton32(state);
  
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
  case 1:
    ergodox_right_led_1_on();
    break;
  case 2:
    ergodox_right_led_2_on();
    break;
  case 3:
    ergodox_right_led_3_on();
    break;
  case 4:
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    break;
  case 5:
    ergodox_right_led_1_on();
    ergodox_right_led_3_on();
    break;
  case 6:
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    break;
  case 7:
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    break;
  default:
    break;
  }
}

enum BlinkPattern {
  LEADER_SUCCESS,
  LEADER_FAIL,
};

static uint16_t blink_timer = 0;
static uint8_t blink_current_pattern = 255;
static uint16_t blink_interval = 200;
static uint8_t blink_state = 0; // inverse of blink_iterations could
				// be merged. 
static uint8_t blink_iterations = 255;

void blink_set_pattern(uint8_t pattern, uint16_t interval, uint8_t iterations) {
  blink_current_pattern = pattern;
  blink_interval = interval;
  blink_iterations = iterations;
  blink_timer = timer_read();
}

void blink_leader_success(uint8_t state) {
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  
  switch(state % 3) {
  case 0:
    ergodox_right_led_1_on();
    break;
  case 1:
    ergodox_right_led_2_on();
    break;
  case 2:
    ergodox_right_led_3_on();
    break;
  }
}

void blink_leader_fail(uint8_t state) {
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  
  switch(state % 2) {
  case 0:
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    break;
  }
}

void leds_blinks(void) {
  if(blink_current_pattern != 255 && blink_iterations != 0) {
    blink_iterations--;
    if(blink_iterations) {
      if(timer_elapsed(blink_timer) > blink_interval) {
	blink_timer = timer_read();
	blink_state++;
	switch(blink_current_pattern) {
	case LEADER_SUCCESS: blink_leader_success(blink_state);
	  break;
	case LEADER_FAIL: blink_leader_fail(blink_state);
	  break;
	}
      }
    } else { // iterations has ended, reset
      blink_current_pattern = 255;
      blink_state = 0;
      blink_iterations = 255;
      set_leds_to_layer(current_layer_state);
    }
    
  }
}

void matrix_scan_keymap(void) {
  leds_blinks(); // check if we should do some weird blinking;
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void leader_start_keymap(void) {
  ergodox_right_led_1_on();
  ergodox_right_led_2_on();
  ergodox_right_led_3_on();  
}

void leader_end_keymap(bool success) {
  if(success)
    blink_set_pattern(LEADER_SUCCESS, 200, 9);
  else
    blink_set_pattern(LEADER_FAIL, 300, 5);	       
}

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  current_layer_state = state;
  set_leds_to_layer(current_layer_state);
  return state;
};
