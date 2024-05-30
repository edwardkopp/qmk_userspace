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


// I would like to lower this back to 1 someday
#define USB_POLLING_INTERVAL_MS 4


// Allow mashing
#define QMK_KEYS_PER_SCAN 12
#define FORCE_NKRO


// Slower lights
#ifdef RGB_MATRIX_ENABLE
    #undef RGB_MATRIX_DEFAULT_SPD
    #define RGB_MATRIX_DEFAULT_SPD 63
#endif


// Good mouse
#define MK_VARIANT MK_TYPE_KINETIC
#define MK_KINETIC_MOUSE_ACCN 12
#define MK_KINETIC_MOUSE_DRAG 8
#define MK_KINETIC_MOUSE_FRIC 32
#define MK_KINETIC_MOUSE_MAXS 196

// Good mousewheel
#define MK_KINETIC_WHEEL_ACCN 16
#define MK_KINETIC_WHEEL_MAXS 1
