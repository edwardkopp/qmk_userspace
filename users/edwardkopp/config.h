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


// Gamer keyboard
#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 12
#define FORCE_NKRO


// Undo Voyager mouse defaults
#ifdef MOUSEKEY_INTERVAL
    #undef MOUSEKEY_INTERVAL
#endif
#ifdef MOUSEKEY_DELAY
    #undef MOUSEKEY_DELAY
#endif
#ifdef MOUSEKEY_MAX_SPEED
    #undef MOUSEKEY_MAX_SPEED
#endif
#ifdef MOUSEKEY_TIME_TO_MAX
    #undef MOUSEKEY_TIME_TO_MAX
#endif


// Undo Voyager mousewheel defaults
#ifdef MOUSEKEY_WHEEL_INTERVAL
    #undef MOUSEKEY_WHEEL_INTERVAL
#endif
#ifdef MOUSEKEY_WHEEL_DELAY
    #undef MOUSEKEY_WHEEL_DELAY
#endif
#ifdef MOUSEKEY_WHEEL_MAX_SPEED
    #undef MOUSEKEY_WHEEL_MAX_SPEED
#endif
#ifdef MOUSEKEY_WHEEL_TIME_TO_MAX
    #undef MOUSEKEY_WHEEL_TIME_TO_MAX
#endif


// Somewhat smooth mouse
#define MOUSEKEY_INERTIA
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 2
#define MOUSEKEY_MAX_SPEED 16
#define MOUSEKEY_TIME_TO_MAX 200
#define MOUSEKEY_FRICTION 40
#define MOUSEKEY_MOVE_DELTA 1


// Somewhat smooth mousewheel
#define MOUSEKEY_WHEEL_DELAY 10
#define MOUSEKEY_WHEEL_INTERVAL 80
#define MOUSEKEY_WHEEL_DELTA 1
#define MOUSEKEY_WHEEL_MAX_SPEED 1
#define MOUSEKEY_WHEEL_TIME_TO_MAX 0
