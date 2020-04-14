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
#define _NV 2
#define _SM 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | PRNT   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | |      | ]      | Y      | U      | I      | O      | P      | ENT    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | FUNC   | A      | S      | D      | F      | G      | HOME   | DEL    | PGUP   | H      | J      | K      | L      | ;      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PGDN   | N      | M      | ,      | .      | /      | RSHFT  |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | SUPER  | LALT   | DEL    | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | BKSPC  | ENT    | FN     | RALT   | SUPER  | RCTRL  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = { /* QWERTY, */
  { KC_ESC,           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,    KC_6,    KC_7,   KC_8,          KC_9,          KC_0,    KC_PSCR   },
  { KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_BSLS, KC_RBRC,   KC_Y,    KC_U,   KC_I,          KC_O,          KC_P,    KC_ENT    },
  { LT(_FN, KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_DEL,  KC_PGUP,   KC_H,    KC_J,   LT(_NV, KC_K), LT(_SM, KC_L), KC_SCLN, KC_QUOTE  },
  { KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_UP,   KC_PGDN,   KC_N,    KC_M,   KC_COMM,       KC_DOT,        KC_SLASH,KC_RSHIFT },
  { KC_LCTL,          KC_LGUI, KC_LALT, MO(_FN), KC_SPC,  KC_SPC,  KC_LEFT, KC_DOWN, KC_RIGHT,  KC_BSPC, KC_ENT, MO(_FN),       KC_RALT,       KC_RGUI, KC_RCTL   },
 },

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     |        |        |        | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | GRV    | ESC    | UP     |        | RGB HD | RGB HI |        |        |        | -      | /      | INS    | PRNT   | SCRLK  | PGDN   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | LEFT   | DOWN   | RIGHT  | RGB SD | RGB SI |        |        |        | +      | *      | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | APP    | RGB VD | RGB VI | MUTE   | VOL+   | PLAY   | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | VLK    | RGB RMD| RGB MD | PREV   | VOL-   | NEXT   |        |        | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = { /* FUNCTION */
  { KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_TRNS, KC_TRNS, KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12  },
  { KC_GRV,  KC_ESC,  KC_UP,   KC_TRNS,  RGB_HUD, RGB_HUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_PMNS, KC_PSLS, KC_INS,  KC_PSCR, KC_SLCK, KC_PGDN },
  { KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, RGB_SAD, RGB_SAI, KC_TRNS, KC_TRNS, KC_TRNS, KC_PPLS, KC_PAST, RESET,   _______, _______, _______ },
  { KC_TRNS, KC_TRNS, KC_TRNS, KC_APP,   RGB_VAD, RGB_VAI, KC_MUTE, KC_VOLU, KC_MPLY, KC_PENT, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS, KC_TRNS, KC_TRNS, VLK_TOG,  RGB_RMOD,RGB_MOD, KC_MPRV, KC_VOLD, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
 },

 /* NAVIGATION (this seems like a waste, maybe i'll get rid of it)
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | UP     |        | PGUP   |        |        |        | HOME   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | LEFT   | DOWN   | RIGHT  | PGDN   |        |        |        | END    | LALT   |        | LGUI   |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_NV] = { /* NAVIGATION */
  { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  { KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,  KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  { KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS, KC_END,  KC_LALT, KC_TRNS, KC_LGUI, KC_TRNS, KC_TRNS},
  { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
 },

 /* SYMBOLS
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | \      | !      | <      | >      |        |        |        |        | _      | $      | ?      |        | %      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | @      | &      | (      | )      |        |        |        |        | \      | |      | '      |        | ~      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | #      | =      | {      | }      | /      |        |        |        | -      | `      | "      |        | ^      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | [      | ]      |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_SM] = { /* SYMBOLS */
  { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  { KC_TRNS, KC_BSLS, KC_EXLM, KC_LABK, KC_RABK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_DLR,  KC_QUES, KC_TRNS, KC_PERC, KC_TRNS},
  { KC_TRNS, KC_AT,   KC_AMPR, KC_LPRN, KC_RPRN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, KC_PIPE, KC_QUOT, KC_TRNS, KC_TILD, KC_TRNS},
  { KC_TRNS, KC_HASH, KC_EQL, KC_LCBR, KC_RCBR, KC_SLSH, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_GRV,  KC_DQT,  KC_TRNS, KC_CIRC, KC_TRNS},
  { KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
 }

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
