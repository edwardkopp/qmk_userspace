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


// Calculate the keycode count of the tuple
size_t specialModifiersCount = sizeof(specialModifiers) / sizeof(specialModifiers[0]);


// Checks if a given keycode is on the modifier layers
bool isModifierLayerKey(uint16_t keycode)
{
    for (size_t i = 0; i < specialModifiersCount; i++)
    {
        if (specialModifiers[i] == keycode)
        {
            return true;
        }
    }
    return false;
}


// Tracking for modifier layers
bool isModFresh = false;


// Handles additional functionality for modifier layer activation keys
bool shiftModifierLayerKey(uint16_t shiftKeycode, uint16_t modifierLayer, bool pressed)
{
    if (pressed)
    {
        register_code(shiftKeycode);
        isModFresh = true;
        return true;
    }
    if (isModFresh || IS_LAYER_OFF(modifierLayer))
    {
        unregister_code(shiftKeycode);
    }
    isModFresh = false;
    return true;
}


// Some real magic
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    bool pressed = record->event.pressed;
    // Handle layer activation keys
    switch (keycode)
    {
        case EK_LMOD:
            return shiftModifierLayerKey(KC_LSFT, _LMOD, pressed);
        case EK_RMOD:
            return shiftModifierLayerKey(KC_RSFT, _RMOD, pressed);
        case EK_SYM:
        case EK_NAV:
            return true;
    }
    // Handle keys on the special modifier layers
    if (isModifierLayerKey(keycode) && pressed)
    {
        if (!isModFresh)
        {
            return true;
        }
        if (IS_LAYER_ON(_LMOD))
        {
            unregister_code(KC_LSFT);
        }
        if (IS_LAYER_ON(_RMOD))
        {
            unregister_code(KC_RSFT);
        }
        isModFresh = false;
        return true;
    }
    // At this point, the keycode isn't on the modifier layer
    if (isModFresh && pressed)
    {
        layer_off(_LMOD);
        layer_off(_RMOD);
        isModFresh = false;
    }
    return true;
}


// Make _RAT layer accessible
layer_state_t layer_state_set_user(layer_state_t state)
{
    layer_state_t new_layer_state = update_tri_layer_state(state, _SYMBOL, _NAV, _RAT);
    #ifdef RGB_MATRIX_ENABLE
    if (layer_state_cmp(new_layer_state, _RAT))
    {
        rgb_matrix_set_speed_noeeprom(0);
    }
    else
    {
        rgb_matrix_set_speed_noeeprom(RGB_MATRIX_DEFAULT_SPD);
    }
    #endif
    return new_layer_state;
}
