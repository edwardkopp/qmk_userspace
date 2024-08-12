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


#pragma once
#include QMK_KEYBOARD_H


// The layers
enum rainbow_layer_cake
{
    _QWERTY,
    _SYMBOL,
    _NAV,
    _RAT,
    _MOD
};


// Keycodes for exploration of the rainbow layer cake
#define EK_SYM MO(_SYMBOL)
#define EK_NAV MO(_NAV)
#define EK_MOD MO(_MOD)
