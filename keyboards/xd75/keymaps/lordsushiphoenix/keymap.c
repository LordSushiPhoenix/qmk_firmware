/* Copyright 2017 Wunder
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
#include "xd75.h"

// Layer shorthand
#define _QW 0
#define _FN 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | NUM LK | -      | =      | 6      | 7      | 8      | 9      | 0      | HOME   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | P7     | P8     | P9     | Y      | U      | I      | O      | P      | END    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | FUNC   | A      | S      | D      | F      | G      | P4     | P5     | P6     | H      | J      | K      | L      | ;      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | P1     | P2     | P3     | N      | M      | ,      | .      | UP     | /      |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | SUPER  | LALT   | FN     | DEL    | SPACE  | P0     | P00    | P.     | BKSPC  | ENTER  | FN     | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = { /* QWERTY, */
  { KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_BSLS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_HOME  },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_P7,   KC_P8,   KC_P9,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_END   },
  { MO(_FN), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_P4,   KC_P5,   KC_P6,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOTE },
  { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_P1,   KC_P2,   KC_P3,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLASH },
  { KC_LCTL, KC_LGUI, KC_LALT, KC_DEL,  KC_SPC,  KC_SPC,  KC_NLCK, KC_P0,   KC_PDOT, KC_BSPC, KC_ENT,  MO(_FN), KC_LEFT, KC_DOWN, KC_RIGHT },
 },

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | [      | ]      | PGUP   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CAPSLK | ESC    | UP     |        | RGB HD | RGB HI |        |        |        | -      | /      |        | PRNT   | SCRLK  | PGDN   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | LEFT   | DOWN   | RIGHT  | RGB SD | RGB SI |        |        |        | +      | *      | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | MUTE   | VOL+   | APP    | RGB VD | RGB VI |        |        |        | PENT   |        |        | MUTE   | VOL+   | PLAY   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        | RGB RMD| RGB MD |        |        |        |        |        | FN     | PREV   | VOL-   | NEXT   |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = { /* FUNCTION */
  { KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LBRC, KC_RBRC, KC_PGUP },
  { KC_CAPS, KC_ESC,  KC_UP,   KC_TRNS,  RGB_HUD, RGB_HUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_PMNS, KC_PSLS, _______, KC_PSCR, KC_SLCK, KC_PGDN },
  { KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, RGB_SAD, RGB_SAI, KC_TRNS, KC_TRNS, KC_TRNS, KC_PPLS, KC_PAST, RESET,   _______, _______, _______ },
  { KC_TRNS, KC_MUTE, KC_VOLU, KC_APP,   RGB_VAD, RGB_VAI, KC_TRNS, KC_TRNS, KC_TRNS, KC_PENT, _______, _______, KC_MUTE, KC_VOLU, KC_MPLY },
  { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  RGB_RMOD,RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_VOLD, KC_MNXT },
 }

 //add quick navigation and meme layers, will need macros
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
