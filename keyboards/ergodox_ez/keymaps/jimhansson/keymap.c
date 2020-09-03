#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_swedish.h"

enum layers {
  BASE, // default layer
  SYMB, // symbols
  MDIA, // media keys
  NUMB, // normal numbers
  CMDS, // commands
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,  // print version of firmware
#endif
  RGB_SLD,
  // fixing swedish special things
  // some are fixed by qmk, they have prefix of SE_, mine has SV_
  // could clash with other language, but as long I don't include that
  // we should be ok. we also reuse some norwegian macros.
  SV_LCBR = ALGR(KC_7),
  SV_LBRC = ALGR(KC_8),
  SV_LPRN = S(KC_8),
  SV_RPRN = S(KC_9),
  SV_RBRC = ALGR(KC_9),
  SV_RCBR = ALGR(KC_0),
  SV_LESS = KC_NUBS,
  SV_GRTR = S(KC_NUBS),
  SV_BSLSH = ALGR(NO_PLUS),
  // complex commands
  // LCA  = LEFT CTRL + LEFT ALT
  LOGIN = LCA(KC_DEL),
  KILLX = LCA(KC_BSPC),
  PRV_APP = LALT(S(KC_TAB)),
  NXT_APP = LALT(KC_TAB)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   ½    |   !  |  "   |  #   |  #   |  %   |  L3  |           | L5   |   &  |  /   |  (   |  )   |  =   |  ?     |
   * |   §    |   1  |  2 @ |  3 £ |  4 $ |  5   |      |           | CMDS |   6  |  7 { |  8 [ |  9 ] |  0 } |  + \   |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Delete |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L2  |   Y  |   U  |   I  |   O  |   P  |   Å    |
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | L4     |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |Ö / L2|Ä / Cmd |
   * | PLVR   |      |      |      |      |      | Hyper|           | Meh  |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | Left   |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ;  |   :  |_/Ctrl| RShift |
   * | Shift  |      |      |      |      |      |      |           |      |      |      |   ,  |   .  |-     |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   | '/L1 |  `   |AltShf| Left | L5   |                                       |  Up  | Down |  ^   |  *   | ~L1  |
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
  // If it accepts an argument (i.e, is a function), it doesn't need KC_.
  // Otherwise, it needs KC_*
  [BASE] = LAYOUT_ergodox_pretty(  // layer 0 : default
				 // left hand
    NO_HALF,          S(KC_1),        S(KC_2),       S(KC_3), S(KC_4), S(KC_5),   TG(NUMB),
    KC_DELT,          KC_Q,           KC_W,          KC_E,    KC_R,    KC_T,      TG(SYMB),
    TG(MDIA),         KC_A,           KC_S,          KC_D,    KC_F,    KC_G,
    KC_LSPO,          CTL_T(KC_Z),    KC_X,          KC_C,    KC_V,    KC_B,      ALL_T(KC_NO),
    LT(SYMB,NO_APOS), NO_ACUT,        LALT(KC_LSFT), KC_LEFT, TT(CMDS),
                                                              ALT_T(KC_APP),      KC_LGUI,
                                                                                  KC_HOME,
                                                              KC_ENT,  KC_BSPC,   KC_END,
    // right hand
    TG(CMDS),     S(KC_6), S(KC_7),   S(KC_8),    S(KC_9),    S(KC_0),              NO_PLUS,
    TG(MDIA),     KC_Y,    KC_U,      KC_I,       KC_O,       KC_P,                 SE_AA,
                  KC_H,    KC_J,      KC_K,       KC_L,       LT(MDIA, NO_OSLH),    GUI_T(NO_AE),
    MEH_T(KC_NO), KC_N,    KC_M,      KC_COMM,    KC_DOT,     CTL_T(NO_MINS),       KC_RSPC,
                           KC_UP,     KC_DOWN,    NO_CIRC,    SE_ASTR,              TT(SYMB),
    KC_ALGR,      CTL_T(KC_ESC),
    KC_PGUP,
    KC_PGDN,KC_TAB, KC_SPC
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
   * |         |   !  |   {  |   }  |   \  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
   * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |         |   <  |   (  |   )  |   >  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |  -     |
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
    KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_TRNS,
    KC_TRNS,  KC_EXLM,  SV_LCBR,  SV_RCBR,  SV_BSLSH, KC_PIPE, KC_TRNS,
    KC_TRNS,  SV_LESS,  SV_LPRN,  SV_RPRN,  SV_GRTR,  KC_GRV,
    KC_TRNS,  KC_CIRC,  SV_LBRC,  SV_RBRC,  KC_PERC,  KC_TILD, KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                      RGB_MOD, RGB_VAI,
                                                               RGB_VAD,
                                             KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
    // most of number things are using the keycodes from the numberpad, but there is some
    // more codes that could intresting to use.
    KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_F11,
    KC_TRNS,  KC_UP,    KC_P7,    KC_P8,    KC_P9,    KC_PAST, KC_F12,
    KC_DOWN,  KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  KC_PMNS,
    KC_TRNS,  KC_AMPR,  KC_P1,    KC_P2,    KC_P3,    KC_PSLS, KC_TRNS,
    KC_TRNS,  KC_PCMM,  KC_P0,    KC_PEQL,  KC_TRNS,
    RGB_TOG,  RGB_SLD,
    RGB_HUI,
    RGB_HUD,  KC_DOT,   KC_P0
),
  
  /* Keymap 2: Media and mouse keys
   *
   * we could place kc_lock here somewhere and make it easy to select things with mouse controls
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |mwleft| MsUp |mwrigh|mwup  |      |           |      |      |      | Up   |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |MsLeft|MsDown|MsRght|mwdown|------|           |------|      | Left | Down | Rght |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      | Lclk | Mclk | Rclk |      |      |           |      |      |      | Prev | Next |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |Brwser|
   *                                 |      |      |------|       |------|      |Back  |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  
  [MDIA] = LAYOUT_ergodox(
  // left hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
    KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN3, KC_BTN2, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                                 KC_TRNS, KC_TRNS,
                                                          KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_MPLY,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                      KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
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

  [NUMB] = LAYOUT_ergodox(
    // left hand
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 KC_TRNS, KC_TRNS,
                                                          KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
    KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),

  /* Keymap 5: commands
   * 
   * This keymap is for complex commands that we would like to have
   * easier access to, things like the three finger salute needed to
   * login on windows and other stuff.
   */
  [CMDS] = LAYOUT_ergodox(
         // left
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_SLCK, PRV_APP, NXT_APP, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                      KC_TRNS, KC_TRNS,
                                                               KC_TRNS,
                                             KC_TRNS, KC_TRNS, KC_TRNS, 
         // right
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                  KC_TRNS, KC_TRNS, KILLX,   LOGIN,   KC_TRNS, KC_TRNS,
         KC_TRNS, KC_NLCK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
         KC_TRNS, KC_TRNS,
         KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

rgb_config_t rgb_matrix_config;

const uint8_t PROGMEM layercolors[][2] = {
  [BASE] = {200,155}
};


#define ALL_LEDS { 255, 255, 255, 255, 255, 255 }
// these bitmaps lets me tell what keys i want to set specific colors for, these are just
// series of bits that tells for every key if it should have an individual color or not
// This allows me to compress the color maps to only contain colors for those keys I want
// to set instead of having to have a value for every key.
const uint8_t PROGMEM ledcolors_bitmap[][DRIVER_LED_TOTAL / 8] = {
  [SYMB] = { 128+64, 1+8+16+32, 7+64,
	     0, 0, 0 },
  [MDIA] = { 128, 8+16+32, 0,
	     128, 8+16+32, 16+32 },
  [NUMB] =  { 31, 0, 0,
	      31, 0, 0 }
};

// thanks to the bitmap we only need to have entries for those keys we want to change.
const uint8_t PROGMEM ledcolors[][10][3] = {
  [SYMB] = {
    // right hand
    {180,0,180}, {180,0,35}, {180,0,180},
    {180,0,180}, {180,0,35}, {180,0,180},
    {180,0,180}, {180,0,35}, {180,0,180},
    {180,0,180}
    // left hand
  },
  [MDIA] = {
    // Right hand
    {142,123,255}, 
    {142,123,255}, {142,123,255}, {142,123,255},
    // Left hand
    {142,123,255},
    {142,123,255}, {142,123,255}, {142,123,255},
    {60,0,255}, {60,0,255}
  },
  [NUMB] = {
    // Right hand
    {60,0,255}, {60,0,255}, {60,0,255}, {60,0,255}, {60,0,255},
    // Left hand
    {60,0,255}, {60,0,255}, {60,0,255}, {60,0,255}, {60,0,255},
  }
};

// don't remember what this was for.
const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1),
  [2] = ACTION_LAYER_TAP_TOGGLE(2),
  [3] = ACTION_LAYER_TAP_TOGGLE(3)
};


void set_leds_color( int layer) {
  int used = 0;
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    int major = i / 8;
    int minor = i % 8;
    if((pgm_read_byte(&ledcolors_bitmap[layer][major]) & (1 << minor)) != 0) {
      uint8_t val = pgm_read_byte(&ledcolors[layer][used][2]);
      // if the brightness of the led is set to 0 in the map,
      // the value is not overriden with global controls, allowing the led
      // to appear turned off
      HSV hsv = {
	.h = pgm_read_byte(&ledcolors[layer][used][0]),
	.s = pgm_read_byte(&ledcolors[layer][used][1]),
	.v = val == 0 ? 0 : rgb_matrix_config.hsv.v
      };
      RGB rgb = hsv_to_rgb( hsv );
      rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
      used++;
    }
  }
}

void set_layer_color( uint8_t layer ) {
  HSV hsv = {
    .h = pgm_read_byte(&layercolors[layer][0]),
    .s = pgm_read_byte(&layercolors[layer][1]),
    .v = rgb_matrix_config.hsv.v
  };
  RGB rgb = hsv_to_rgb( hsv );
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
  }
}

void rgb_matrix_indicators_user(void) {
  uint32_t mode = rgblight_get_mode();
  // assign colors if the matrix is on and the current mode
  // is SOLID COLORS => No animations running
  if(rgb_matrix_config.enable == 1 && mode == 1) {
    uint8_t layer = biton32(layer_state);
    switch (layer) {
    case BASE:
      set_layer_color(0);
      break;
    case SYMB:
      set_leds_color(1);
      break;
    case MDIA:
      set_leds_color(2);
      break;
    case NUMB:
      set_leds_color(3);
    }
  }
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
  rgb_matrix_config.raw = eeprom_read_dword(EECONFIG_RGB_MATRIX);
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
