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


#include "edwardkopp.h"


// Tracking of mouse movement for RGB toggling
#ifdef RGB_MATRIX_ENABLE
bool mouse_active = false;
#endif


// Tracking of mod layer stuff
uint16_t left_space_time_pressed = 0;
bool mod_layer_listen_state = false;


// Registers or unregisters keycode according to boolean
void set_code(uint16_t keycode, bool pressed) {
    if (pressed) register_code(keycode);
    else unregister_code(keycode);
}


// Some real magic
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    bool pressed = record->event.pressed;
    switch (keycode) {
        case EK_SYM:
        case EK_NAV:
            // This prevents layer keys from changing RGB lighting state
            return true;
        case EK_MSPC:
            if (pressed) {
                left_space_time_pressed = timer_read();
                mod_layer_listen_state = true;
                layer_on(_LMOD);
                layer_on(_RMOD);
                return false;
            }
            layer_off(_LMOD);
            layer_off(_RMOD);
            if (mod_layer_listen_state && timer_elapsed(left_space_time_pressed) < TAPPING_TERM) {
                tap_code(KC_SPC);
            }
            return false;
        case EK_LMOD_START ... EK_LMOD_END:
            if (mod_layer_listen_state) {
                layer_off(_RMOD);
                mod_layer_listen_state = false;
            }
            switch (keycode) {
                case EK_LCTL: set_code(KC_LCTL, pressed); break;
                case EK_LGUI: set_code(KC_LGUI, pressed); break;
                case EK_LALT: set_code(KC_LALT, pressed); break;
                case EK_LSFT: set_code(KC_LSFT, pressed); break;
            }
            return false;
        case EK_RMOD_START ... EK_RMOD_END:
            if (mod_layer_listen_state) {
                layer_off(_LMOD);
                mod_layer_listen_state = false;
            }
            switch (keycode) {
                case EK_RCTL: set_code(KC_RCTL, pressed); break;
                case EK_RGUI: set_code(KC_LGUI, pressed); break;  // Intentionally KC_LGUI here
                case EK_RALT: set_code(KC_RALT, pressed); break;
                case EK_RSFT: set_code(KC_RSFT, pressed); break;
            }
            return false;
    }
    // Nothing beyond this point processes on release
    if (!pressed) {
        return true;
    }
    #ifdef RGB_MATRIX_ENABLE
    // Handle RGB if mouse keys are involved
    if (IS_MOUSEKEY_MOVE(keycode) && !mouse_active) {
        mouse_active = true;
        rgb_matrix_disable_noeeprom();
    } else if (mouse_active && IS_LAYER_OFF(_RAT) && IS_LAYER_OFF(_NAV)) {
        mouse_active = false;
        rgb_matrix_enable_noeeprom();
    }
    #endif
    return true;
}


// Make _RAT layer accessible
layer_state_t layer_state_set_user(layer_state_t state) {
    layer_state_t new_layer_state = update_tri_layer_state(state, _SYMBOL, _NAV, _RAT);
    if (layer_state_cmp(new_layer_state, _RAT)) {
        tap_code(MS_ACL0);
    }
    return new_layer_state;
}
