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
        EK_LMOD, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, EK_RMOD,
                                            EK_SYM,  KC_SPC,  KC_SPC,  EK_NAV
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
        KC_PAUS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY, KC_ENT,
        _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KC_PGUP, KC_CAPS, KC_PGDN, KC_MNXT, _______,
                                            _______, _______, _______, _______
    ),
    [_RAT] = LAYOUT_voyager(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        XXXXXXX, KC_VOLU, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_MS_U, KC_END,  KC_MPRV, KC_DEL,
        KC_ESC,  KC_MUTE, KC_ACL0, KC_WH_D, KC_BTN1, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_MPLY, KC_ENT,
        _______, KC_VOLD, XXXXXXX, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX, KC_PGUP, KC_PSCR, KC_PGDN, KC_MNXT, _______,
                                            _______, _______, _______, _______
    ),
    [_RMOD] = LAYOUT_voyager(
        _______, _______, _______, _______, _______, _______, EK_____, EK_____, EK_____, EK_____, EK_____, EK_____,
        _______, _______, _______, _______, _______, _______, EK_CGS,  EK_CS,   EK_GS,   EK_AS,   EK_____, EK_____,
        _______, _______, _______, _______, _______, _______, EK_CAS,  EK_RCTL, EK_GUI,  EK_RALT, EK_CGA,  EK_____,
        XXXXXXX, _______, _______, _______, _______, _______, EK_GAS,  EK_CG,   EK_CA,   EK_GA,   EK_____, _______,
                                            _______, _______, _______, _______
    ),
    [_LMOD] = LAYOUT_voyager(
        EK_____, EK_____, EK_____, EK_____, EK_____, EK_____, _______, _______, _______, _______, _______, _______,
        EK_____, EK_____, EK_AS,   EK_GS,   EK_CS,   EK_CGS,  _______, _______, _______, _______, _______, _______,
        EK_____, EK_CGA,  EK_LALT, EK_GUI,  EK_LCTL, EK_CAS,  _______, _______, _______, _______, _______, _______,
        _______, EK_____, EK_GA,   EK_CA,   EK_CG,   EK_GAS,  _______, _______, _______, _______, _______, XXXXXXX,
                                            _______, _______, _______, _______
    )
};
