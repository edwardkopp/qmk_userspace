/*
Copyright 2022 Edward Kopp <edward@edwardkopp.com>

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


// The layers
enum rainbow_layer_cake
{
    _QWERTY,
    _SYMBOL,
    _NAV,
    _RAT,
    _RMOD,
    _LMOD
};


// Keycodes for exploration of the rainbow layer cake
#define EK_SYM MO(_SYMBOL)
#define EK_NAV MO(_NAV)
#define EK_LMOD MO(_LMOD)
#define EK_RMOD MO(_RMOD)


// Single modifier keycodes associated with the modifier layers
#define EK_GUI KC_LGUI
#define EK_LCTL KC_LCTL
#define EK_LALT KC_LALT
#define EK_RCTL KC_RCTL
#define EK_RALT KC_RALT


// Special keycodes associated with the modifier layers
#define EK_CS S(KC_LCTL)
#define EK_GS S(KC_LGUI)
#define EK_AS S(KC_LALT)
#define EK_CG C(KC_LGUI)
#define EK_CA C(KC_LALT)
#define EK_GA A(KC_LGUI)
#define EK_CGS C(S(KC_LGUI))
#define EK_CAS C(A(KC_LSFT))
#define EK_GAS A(S(KC_LGUI))
#define EK_CGA C(A(KC_LGUI))
#define EK_____ _______


// Tuple for referencing these special modifiers
const uint16_t specialModifiers[] = {
    EK_GUI,
    EK_LCTL,
    EK_LALT,
    EK_RCTL,
    EK_RALT,
    EK_CS,
    EK_GS,
    EK_AS,
    EK_CG,
    EK_CA,
    EK_GA,
    EK_CGS,
    EK_CAS,
    EK_GAS,
    EK_CGA,
    EK_____
};
