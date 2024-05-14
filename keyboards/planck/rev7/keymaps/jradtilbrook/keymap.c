/* Copyright 2015-2023 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "quantum_keycodes.h"

enum planck_layers { _QWERTY, _NAV, _LOWER, _RAISE, _ADJUST, _VIM };

#define NAV MO(_NAV)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define HMSPN KC_F19
#define RAYCAST KC_F20

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Nav  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | GUI  |Lower | Shift|Space |Raise | Rpt  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    HYPR_T(KC_ESC),LGUI_T(KC_A),LALT_T(KC_S),LSFT_T(KC_D),LCTL_T(KC_F),KC_G,KC_H,RCTL_T(KC_J),RSFT_T(KC_K),RALT_T(KC_L),RGUI_T(KC_SCLN), KC_QUOT,
    NAV, LT(_VIM,KC_Z),KC_X,   KC_C,    KC_V,    KC_B,      KC_N,LSG_T(KC_M),    KC_COMM, KC_DOT,KC_SLSH, KC_ENT ,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI, LOWER,   KC_LSFT, KC_SPC,  RAISE,    QK_REP, XXXXXXX, XXXXXXX,   XXXXXXX
),

[_NAV] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______,   HMSPN, RAYCAST, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_LALT, _______, _______, _______, _______, _______, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_HOME, KC_END, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT(
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
    KC_GRV,LGUI_T(KC_1),LALT_T(KC_2),LSFT_T(KC_3),LCTL_T(KC_4),KC_5,KC_6,RCTL_T(KC_7),RSFT_T(KC_8),RALT_T(KC_9),RGUI_T(KC_0),KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,
    _______, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, KC_MPLY,  _______, _______,  _______,  _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  _______, _______,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_VIM] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,    KC_H,    KC_J,    KC_K,    KC_L, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};
/* clang-format on */

// shift + backspace = delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};

layer_state_t layer_state_set_user(layer_state_t state) {
    layer_state_t tri = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    rgblight_set_layer_state(0, layer_state_cmp(tri, _NAV));
    rgblight_set_layer_state(1, layer_state_cmp(tri, _LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(tri, _RAISE));
    rgblight_set_layer_state(3, layer_state_cmp(tri, _ADJUST));
    rgblight_set_layer_state(4, layer_state_cmp(tri, _VIM));
    return tri;
}

/**
 * LED locations looking top down
 * 6     5     4     3
 *          0
 * 7     8     1     2
 */
const rgblight_segment_t PROGMEM rgb_caps_word[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 2, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM rgb_nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8, 1, HSV_GOLDENROD}
);
const rgblight_segment_t PROGMEM rgb_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 2, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM rgb_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 2, HSV_GREEN}
);
const rgblight_segment_t PROGMEM rgb_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 2, HSV_GREEN}
);
const rgblight_segment_t PROGMEM rgb_vim_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_GOLDENROD}
);
const rgblight_segment_t PROGMEM rgb_bootloader[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_RED}
);
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_nav_layer,
    rgb_lower_layer,
    rgb_raise_layer,
    rgb_adjust_layer,
    rgb_vim_layer,
    rgb_caps_word,
    rgb_bootloader
);
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

// change underglow colour when caps word is active
void caps_word_set_user(bool active) {
    rgblight_set_layer_state(5, active);
}

bool shutdown_user(bool jump_to_bootloader) {
    rgblight_set_layer_state(6, jump_to_bootloader);
    rgblight_set();
    return true; // Process all other keycodes normally
}
