/* Copyright 2021 Lord_Reset
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
extern uint8_t  is_master;
enum custom_keycodes {
DOTCOMM,
    FLIPEQL = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_7,    KC_8,    KC_9,    KC_0,LT(1, KC_ESC), KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_4,    KC_5,    KC_6,SFT_T(KC_BSPC),KC_TAB,  KC_A,  KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_ENT,
        KC_1,    KC_2,    KC_3,LT(1,KC_ENT),  KC_LSFT, KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT, KC_UP,   KC_GRV, 
        SFT_T(KC_MINS), DOTCOMM, FLIPEQL,LT(1,KC_ENT),KC_LCTL,KC_LGUI,KC_LALT,MO(1),KC_SPC,KC_SPC,KC_BSPC, MO(1),   KC_LALT, KC_LGUI, KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_GRV,  KC_BTN3, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, KC_PWR,  _______, KC_WH_U, KC_MINS, FLIPEQL, KC_LPRN, KC_RPRN, KC_BSLS,
        KC_F4,   KC_F5,   KC_F6,  _______,  _______, KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN3, RESET,   KC_WH_L, KC_WH_D, KC_WH_R, _______, _______, _______, _______,
        KC_F1,   KC_F2,   KC_F3,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_CAPS, KC_VOLU, _______,
        KC_F11,  KC_F12, _______, _______,  _______, _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_MPLY
    ),
    [2] = LAYOUT(
        _______, _______, _______, _______,_______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,_______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,_______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,_______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [3] = LAYOUT(
        _______, _______, _______, _______,_______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,_______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,_______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,_______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t saved_mods   = 0;
    uint16_t       temp_keycode = keycode;

    switch (temp_keycode) {
      case FLIPEQL:
            if (record->event.pressed) {
                saved_mods = get_mods() & MOD_MASK_SHIFT;

                if (saved_mods == MOD_MASK_SHIFT) {  // Both shifts pressed
                    register_code16(KC_EQL);
                } else if (saved_mods) {   // One shift pressed
                    del_mods(saved_mods);  // Remove any Shifts present
                    register_code16(KC_EQL);
                    add_mods(saved_mods);  // Add shifts again
                } else {
                    register_code16(KC_PLUS);
                }
            } else {
                unregister_code16(KC_EQL);
                unregister_code16(KC_PLUS);
            } 
            return keycode;   
      case DOTCOMM:
            if (record->event.pressed) {
                saved_mods = get_mods() & MOD_MASK_SHIFT;

                if (saved_mods == MOD_MASK_SHIFT) {  // Both shifts pressed
                    register_code16(KC_COMM);
                } else if (saved_mods) {   // One shift pressed
                    del_mods(saved_mods);  // Remove any Shifts present
                    register_code16(KC_COMM);
                    add_mods(saved_mods);  // Add shifts again
                } else {
                    register_code16(KC_DOT);
                }
            } else {
                unregister_code16(KC_COMM);
                unregister_code16(KC_DOT);
            } 
            return keycode;   
    }
    return keycode;
}
