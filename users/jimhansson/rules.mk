# Enable media keys on all keyboards.
EXTRAKEY_ENABLE = yes

# Enable N-key rollover on all keyboards. In addition to its intended
# functionality, as of July 2020, this is required for Chrome OS to process
# media keys. (It appears that Chrome OS filters out key events from the second
# USB endpoint's consumer and system control devices unless that endpoint also
# reports a keyboard or mouse device.)
NKRO_ENABLE = yes

# Enable link-time optimization to reduce binary size.
LTO_ENABLE = yes
#EXTRAFLAGS        += -flto

# steno support of until I actually start to use.
STENO_ENABLE = no

# space cadet
SPACE_CADET_ENABLE = yes

# auto shift.
AUTO_SHIFT_ENABLE = yes

# Gives us a command mode where we can write things like quit,
# and it does ctrl+f4
LEADER_ENABLE = yes

# yes I use them
MOUSEKEY_ENABLE = yes

DYNAMIC_MACRO_ENABLE = no

COMBO_ENABLE = yes

KEY_OVERRIDE_ENABLE = yes

AUDIO_ENABLE = yes
# Include common utilities shared across all our keymaps.
SRC +=  \
	combos.c \
	overrides.c \
	leaders.c \
	process_records.c

#PROGRAMMABLE_BUTTON_ENABLE = yes

# Disable unwanted build options on all keyboards. (Mouse keys are turned off
# due to https://github.com/qmk/qmk_firmware/issues/8323, and the rest are
# turned off to reduce firmware size.)
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
TERMINAL_ENABLE = no
AUDIO_ENABLE = no
BACKLIGHT_ENABLE = no
# Disable unwanted hardware options on all keyboards. (Some keyboards turn
# these features on by default even though they aren't actually required.)
MIDI_ENABLE = no
SLEEP_LED_ENABLE = no
BOOTMAGIC_ENABLE = no
# Disable other unused options on all keyboards.
QMK_SETTINGS = no
GRAVE_ESC_ENABLE = no
KEY_LOCK_ENABLE = no
MAGIC_ENABLE = no
SWAP_HANDS_ENABLE = no
TAP_DANCE_ENABLE = no
UCIS_ENABLE = no
UNICODEMAP_ENABLE = no
UNICODE_ENABLE = no



