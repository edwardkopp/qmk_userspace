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
        KC_ESC,  EK_A,    EK_S,    EK_D,    EK_F,    KC_G,    KC_H,    EK_J,    EK_K,    EK_L,    EK_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            EK_SYM,  EK_LSPC, KC_SPC,  EK_NAV
    ),
    [_SYMBOL] = LAYOUT_voyager(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ENT,
        _______, KC_BSLS, KC_PIPE, KC_PLUS, KC_EQL,  KC_UNDS, KC_MINS, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, _______,
                                            _______, _______, _______, _______
    ),
    [_NAV] = LAYOUT_voyager(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_INS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_MPRV, KC_DEL,
        KC_CAPS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY, KC_ENT,
        _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, KC_PGDN, KC_MNXT, _______,
                                            _______, _______, _______, _______
    ),
    [_RAT] = LAYOUT_voyager(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, MS_WHLU, KC_PSCR, XXXXXXX, XXXXXXX, KC_HOME, MS_UP,   KC_END,  KC_MPRV, KC_DEL,
        KC_ESC,  XXXXXXX, MS_ACL1, MS_WHLD, MS_BTN1, XXXXXXX, XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, KC_MPLY, KC_ENT,
        _______, XXXXXXX, XXXXXXX, MS_BTN3, MS_BTN2, XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, KC_PGDN, KC_MNXT, _______,
                                            _______, _______, _______, _______
    ),
    [_LMOD] = LAYOUT_voyager(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, EK_LSFT, EK_LALT, EK_LGUI, EK_LCTL, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______
    ),
    [_RMOD] = LAYOUT_voyager(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, EK_RCTL, EK_RGUI, EK_RALT, EK_RSFT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______
    )
};
