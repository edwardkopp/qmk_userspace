/*
Copyright 2024 Edward Kopp <edward@edwardkopp.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <https://www.gnu.org/licenses/>.
*/


#include "edwardkopp.h"


// The keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_voyager(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            EK_LEFT, KC_SPC,  KC_SPC,  EK_RGHT
    ),
    [_LMOD] = LAYOUT_voyager(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_LGUI, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, _______,
        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_MUTE, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_LPRN, KC_LBRC, KC_LCBR, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______
    ),
    [_RMOD] = LAYOUT_voyager(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_LGUI, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_MPLY, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, _______,
        _______, _______, _______, _______, _______, _______, KC_RCBR, KC_RBRC, KC_RPRN, KC_PIPE, KC_BSLS, _______,
                                            _______, _______, _______, _______
    ),
    [_SYMBOL] = LAYOUT_voyager(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX, KC_DEL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ENT,
        _______, XXXXXXX, XXXXXXX, KC_PLUS, KC_EQL,  KC_UNDS, KC_MINS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                            _______, _______, EK_NAV,  _______
    ),
    [_NAV] = LAYOUT_voyager(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_INS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_END,  XXXXXXX, KC_DEL,
        KC_PAUS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_ENT,
        _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KC_PGUP, KC_PAUS, KC_PGDN, XXXXXXX, _______,
                                            _______, EK_SYM,  _______, _______
    ),
    [_RAT] = LAYOUT_voyager(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_MS_U, KC_END,  XXXXXXX, KC_DEL,
        XXXXXXX, KC_ESC,  KC_ACL1, KC_WH_D, KC_BTN1, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, KC_ENT,
        _______, XXXXXXX, XXXXXXX, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX, KC_PGUP, KC_PSCR, KC_PGDN, XXXXXXX, _______,
                                            _______, _______, _______, _______
    )
};
