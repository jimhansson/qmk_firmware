#pragma once
// this should be included after the layers and keycode enums, with
// markes that tells the where these enums should start.
#include "layers.h"

enum shared_layers {
  _CFG = _LAST_LAYER,
#ifdef STENO_ENABLE
  _PLOVER,
#endif
};

enum shared_keycodes {
  EXT_PLV = _LAST_KEYCODE,
  EXT_CFG,
  CAS_TOG,
  GAME_ON,
  PRINT_CFG_SETTINGS,
  PLOVER,
};

enum combos {
  CMB_LCTL = 0,
  CMB_RCTL,
  CMB_LALT,
  CMB_RALT,
  CMB_INS,
  CMB_DEL,
  CMB_LENGTH
};

combo_t key_combos[CMB_LENGTH];

#define PRNCFG PRINT_CFG_SETTINGS
