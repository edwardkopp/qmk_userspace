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
#include "pointing_device.h"


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
    EK_____,
    EK_XXXX
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
void shiftModifierLayerKey(uint16_t shiftKeycode, uint16_t modifierLayer, bool pressed)
{
    if (pressed)
    {
        register_code(shiftKeycode);
        isModFresh = true;
        return;
    }
    if (isModFresh || IS_LAYER_OFF(modifierLayer))
    {
        unregister_code(shiftKeycode);
    }
    isModFresh = false;
}


// Mouse booleans initialization
bool mouseUpActive = false;
bool mouseDownActive = false;
bool mouseLeftActive = false;
bool mouseRightActive = false;
bool scrollUpActive = false;
bool scrollDownActive = false;


// Some real magic
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    bool pressed = record->event.pressed;
    // Custom or additional key implementations
    switch (keycode)
    {
        // Handle layer activation keys
        case EK_LMOD:
            shiftModifierLayerKey(KC_LSFT, _LMOD, pressed);
            return true;
        case EK_RMOD:
            shiftModifierLayerKey(KC_RSFT, _RMOD, pressed);
            return true;
        case EK_SYM:
        case EK_NAV:
            return true;
        // Handle mouse movement keys
        case EK_MS_U:
            if (pressed)
            {
                mouseUpActive = true;
            }
            mouseUpActive = false;
        case EK_MS_D:
            if (pressed)
            {
                mouseDownActive = true;
            }
            mouseDownActive = false;
        case EK_MS_L:
            if (pressed)
            {
                mouseLeftActive = true;
            }
            mouseLeftActive = false;
        case EK_MS_R:
            if (pressed)
            {
                mouseRightActive = true;
            }
            mouseRightActive = false;
        // Handle mouse wheel keys
        case EK_WH_U:
            if (pressed)
            {
                scrollUpActive = true;
            }
            scrollUpActive = false;
        case EK_WH_D:
            if (pressed)
            {
                scrollDownActive = true;
            }
            scrollDownActive = false;
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
    if (layer_state_cmp(new_layer_state, _RAT))
    {
        #ifdef RGB_MATRIX_ENABLE
        rgb_matrix_disable_noeeprom();
        #endif
    }
    else
    {
        #ifdef RGB_MATRIX_ENABLE
        rgb_matrix_enable_noeeprom();
        #endif
    }
    return new_layer_state;
}


// Times for mouse magic
uint16_t lastMouseTime;
uint16_t lastScrollTime;


// Initialize times for mouse magic
void keyboard_post_init_user(void)
{
    lastMouseTime = timer_read();
    lastScrollTime = timer_read();
}


// Dangerous magic
void matrix_scan_user(void)
{
    // Dangerous mouse magic
    report_mouse_t report;
    if ((mouseUpActive || mouseDownActive || mouseLeftActive || mouseRightActive) && timer_elapsed(lastMouseTime) >= 4)
    {
        report = pointing_device_get_report();
        // TODO implement mouse movement
    }
    if ((scrollUpActive || scrollDownActive) && timer_elapsed(lastScrollTime) >= 100)
    {
        if (!report)
        {
            report = pointing_device_set_report();
        }
        report.v = scrollUpActive ? 1 : -1;
    }
    if (report)
    {
        pointing_device_set_report(report);
        pointing_device_send();
    }
}