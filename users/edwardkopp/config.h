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


// Somewhat smooth mouse
#define MK_KINETIC_SPEED
#define MOUSEKEY_INTERVAL 5
#define MOUSEKEY_MOVE_DELTA 50
#define MOUSEKEY_INITIAL_SPEED 50
#define MOUSEKEY_BASE_SPEED 10000
#define MOUSEKEY_DECELERATED_SPEED 50
#define MOUSEKEY_ACCELERATED_SPEED 5000
