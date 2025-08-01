
/* A QWERTY 4 Layer layout for the Dactyl Manuform 6x6 Keyboard */ 

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QW 0
#define _FN 1
#define _NV 2
#define _SM 3
#define _GM 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Keymap 0: Basic layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | `    |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | home |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   q  |   w  |   e  |   r  |   t  |                    |   y  |   u  |   i  |   o  |   p  | end  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  FNC |   a  |   s  |   d  |   f  |   g  |                    |   h  |   j  |   k  |   l  |   ;  |   '  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   z  |   x  |   c  |   v  |   b  |                    |   n  |   m  |   ,  |   .  |   /  |   \  |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * | Lctl | lGUI | lalt | down | del  |                                  | left | Down |  up  | right|  fn  |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      | Lalt | esc  |  | pscr | lalt |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      | lgui |  | rgui |      |      |
 *                               | tab  | spce |------|  |------| bspc | ENT  |
 *                               |      |      | Lsft |  | Rsft |      |      |
 *                               `--------------------'  `--------------------'
 */
  [_QW] = LAYOUT_6x6(
     KC_GRV,           KC_1  ,  KC_2  ,  KC_3  ,  KC_4  , KC_5  ,      KC_6  ,  KC_7   , KC_8   ,       KC_9   ,       KC_0  ,  KC_HOME,
     KC_TAB,           KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  , KC_T  ,      KC_Y  ,  KC_U   , KC_I   ,       KC_O   ,       KC_P  ,  KC_END,
     LT(_FN, KC_CAPS), KC_A  ,  KC_S  ,  KC_D  ,  KC_F  , KC_G  ,      KC_H  ,  KC_J   , LT(_NV, KC_K), LT(_SM, KC_L), KC_SCLN, KC_QUOT,
     KC_LSFT,          KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  , KC_B  ,      KC_N  ,  KC_M   , KC_COMM,       KC_DOT ,       KC_SLSH, KC_BSLASH,
     KC_LCTL,          KC_LGUI, KC_LALT, KC_DOWN, KC_DEL,                       KC_LEFT, KC_DOWN,       KC_UP,         KC_RIGHT,MO(_FN),
                                                 KC_LALT, KC_ESC,      KC_PSCR, KC_LALT, 
                                         KC_TAB, KC_SPC, KC_LGUI,      KC_RGUI, KC_BSPC, KC_ENT,
                                                         KC_LSFT,      KC_RSFT
                                                             
  ),


  [_FN] = LAYOUT_6x6(
     KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12, 
     KC_GRV , RESET,   KC_UP,   _______,  _______, _______,    _______, _______, _______, KC_PSCR,  _______, _______, 
     _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,    KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, _______, _______,
     _______, _______, _______, _______,  _______, _______,    _______, _______, KC_MUTE, KC_MPLY,  _______, _______, 
     _______, _______, _______, _______,  _______,                      KC_MPRV, KC_VOLD, KC_VOLU,  KC_MNXT, _______,
                                          _______, _______,    _______, _______, 
                                 _______, _______, _______,    _______, _______, _______,
                                                  _______,    _______
                                                             
  ),


  [_NV] = LAYOUT_6x6(
     _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,  
     _______, _______, _______, KC_UP  , _______, KC_PGUP,    KC_HOME, _______, _______, _______, _______, _______, 
     _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT,KC_PGDN,    KC_END , KC_LALT, _______, KC_LGUI, _______, _______,
     _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, 
     _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
                                         _______, _______,    _______, _______, 
                                _______, _______, _______,    _______, _______, _______, 
                                                  _______,    _______ 
                                                             
  ),

  [_SM] = LAYOUT_6x6(
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  
     _______, KC_PLUS, KC_EXLM, KC_LABK, KC_RABK, _______, KC_UNDS, KC_DLR , KC_QUES, _______, KC_PERC, _______, 
     _______, KC_AT  , KC_AMPR, KC_LPRN, KC_RPRN, _______, KC_BSLS, KC_PIPE, KC_QUOT, _______, KC_TILD, _______,
     _______, KC_HASH, KC_EQL , KC_LCBR, KC_RCBR, KC_SLSH, KC_MINS, KC_GRV , KC_DQT , _______, KC_CIRC, _______, 
     _______, _______, _______, KC_LBRC, KC_RBRC,                   _______, _______, _______, _______, _______,
                                         _______, _______, _______, _______, 
                                _______, _______, _______, _______, _______, _______, 
                                                  _______, _______
                                                             
  ),
//START OF A GAME LAYOUT TO SHIFT WASD TO A MORE COMFORTABLE POSITION
//  [_GM] = LAYOUT_6x6(
//     _______, _______, KC_1   , KC_2   , _______, _______, _______, _______, _______, _______, _______, _______,  
//     _______, KC_PLUS, KC_Q   , KC_W   , KC_RABK, _______, KC_UNDS, KC_DLR , KC_QUES, _______, KC_PERC, _______, 
//     _______, KC_AT  , KC_A   , KC_S   , KC_RPRN, _______, KC_BSLS, KC_PIPE, KC_QUOT, _______, KC_TILD, _______,
//     _______, KC_HASH, KC_EQL , KC_S   , KC_RCBR, _______, KC_MINS, KC_GRV , KC_DQT , _______, KC_CIRC, _______, 
//     _______, _______, _______, KC_D   , KC_RBRC,                   _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
                                                             
//  ),

  };
