
#pragma once
// this should be included after the layers and keycode enums, with
// markes that tells the where these enums should start.
#include "layers.h"

enum shared_layers {
  _CFG = _LAST_LAYER,
  _PLOVER,
};

enum shared_keycodes {
  EXT_PLV = _LAST_KEYCODE,
  EXT_CFG,
  PLOVER,
};
