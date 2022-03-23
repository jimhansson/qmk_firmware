
#pragma once

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
    NUMB,
    CMDS,
    _LAST_LAYER,
    //_CFG,   // Configuration
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
    EPRM = EZ_SAFE_RANGE,
#else
    EPRM = SAFE_RANGE,
#endif
    RGB_SLD,
    // complex commands
    // LCA  = LEFT CTRL + LEFT ALT
    LOGIN = LCA(KC_DEL),
    KILLX = LCA(KC_BSPC),
    PRV_APP = LALT(S(KC_TAB)),
    NXT_APP = LALT(KC_TAB),
    _LAST_KEYCODE,
};
