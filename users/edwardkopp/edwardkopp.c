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
bool mouseActive = false;
#endif


// Some real magic
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    bool pressed = record->event.pressed;
    // Make _RAT layer accessible
    if ((keycode == EK_SYM || keycode == EK_NAV) && pressed)
    {
        update_tri_layer(_SYMBOL, _NAV, _RAT);
    }
#ifdef RGB_MATRIX_ENABLE
    // Handle RGB if mouse keys are involved
    if (IS_MOUSEKEY_MOVE(keycode) && !mouseActive)
    {
        mouseActive = true;
        rgb_matrix_disable_noeeprom();
    }
    else if (mouseActive && IS_LAYER_OFF(_RAT) && IS_LAYER_OFF(_NAV))
    {
        mouseActive = false;
        rgb_matrix_enable_noeeprom();
    }
#endif
    return true;
}


// Reset mouse acceleration whenever entering _RAT layer
layer_state_t layer_state_set_user(layer_state_t state)
{
    if (layer_state_cmp(state, _RAT))
    {
        register_code(KC_ACL0);
        unregister_code(KC_ACL0);
    }
    return state;
}
