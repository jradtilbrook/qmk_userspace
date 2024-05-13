#include QMK_KEYBOARD_H
#include "quantum_keycodes.h"

// TODO: I want to make this better. some combos are only available on certain layers
// see https://docs.qmk.fm/#/feature_combo

const uint16_t PROGMEM paren_l[]     = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM paren_r[]     = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM brace_l[]     = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM brace_r[]     = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM bracket_l[]   = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM bracket_r[]   = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM colon[]       = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM raycast[]     = {KC_M, KC_LT, COMBO_END};
const uint16_t PROGMEM hammerspoon[] = {KC_LT, KC_GT, COMBO_END};

combo_t                key_combos[]  = {
    COMBO(paren_l, KC_LPRN),
    COMBO(paren_r, KC_RPRN),
    COMBO(brace_l, KC_LCBR),
    COMBO(brace_r, KC_RCBR),
    COMBO(bracket_l, KC_LBRC),
    COMBO(bracket_r, KC_RBRC),
    COMBO(colon, LSFT(KC_SCLN)),
    COMBO(raycast, KC_F20),
    COMBO(hammerspoon, KC_F19),
};
