
#pragma once

enum planck_layers {
  _QWERTY,
#if 0
  _COLEMAK,
  _DVORAK,
#endif
  _SYMBOLS,
  _MEDIA,
#if 0
  _LOWER,
  _RAISE,
#endif
  _LAST_LAYER,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  BACKLIT,
  _LAST_KEYCODE,
};
