
#include "process_key_override.h"

// here we will override normal shortcuts that have a higher media key
// that we could send instead that represent the same action

const key_override_t cut_override = ko_make_basic(MOD_MASK_CTRL, KC_X, KC_CUT);
const key_override_t copy_override = ko_make_basic(MOD_MASK_CTRL, KC_C, KC_COPY);
const key_override_t paste_override = ko_make_basic(MOD_MASK_CTRL, KC_V, KC_PASTE);

#define KC_REDO KC_AGAIN
const key_override_t undo_override = ko_make_basic(MOD_MASK_CTRL, KC_Z, KC_UNDO);
const key_override_t redo_override = ko_make_basic(MOD_MASK_CTRL, KC_Y, KC_REDO);

const key_override_t **key_overrides = (const key_override_t *[]) {
  &cut_override,
  &copy_override,
  &paste_override,
  
  &undo_override,
  &redo_override,
};
