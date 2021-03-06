#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


enum layer
{
  LAYER_BASE,  // default layer
  LAYER_SYMB,  // symbols
  LAYER_MDIA,  // media keys
  LAYER_PLAIN
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,
  EPRM,
  VRSN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[LAYER_BASE] = KEYMAP(  // layer 0 : default
  // left hand
  KC_UP  ,               KC_1,                   KC_2,          KC_3,    KC_4,    KC_5,   KC_LEFT,
  KC_DELT,               KC_Q,                   KC_W,          KC_E,    KC_R,    KC_T,   TG(LAYER_SYMB),
  LT(LAYER_SYMB,KC_ESC), LT(LAYER_MDIA,KC_A),    KC_S,          KC_D,    KC_F,    KC_G,
  KC_LSFT,               LCTL_T(KC_Z),           LALT_T(KC_X),  KC_C,    KC_V,    KC_B,   ALL_T(KC_NO),
  MO(LAYER_SYMB),        LT(LAYER_SYMB,KC_QUOT), LALT(KC_LSFT), KC_LEFT, KC_EQL,

                                                               LALT_T(KC_APP), KC_LGUI,
                                                                               KC_HOME,
                                                      KC_SPC,  KC_BSPC,        KC_END,


  // right hand
  KC_RIGHT,        KC_6,    KC_7,     KC_8,     KC_9,           KC_0,                   KC_DOWN,
  TG(LAYER_SYMB),  KC_Y,    KC_U,     KC_I,     KC_O,           KC_P,                   KC_BSLS,
                   KC_H,    KC_J,     KC_K,     KC_L,           LT(LAYER_MDIA,KC_SCLN), LT(LAYER_SYMB,KC_QUOT),
  MEH_T(KC_NO),    KC_N,    KC_M,     KC_COMM,  RALT_T(KC_DOT), RCTL_T(KC_SLSH),        KC_RSFT,
                            KC_MINS,  KC_RIGHT, KC_LBRC,        LT(LAYER_SYMB,KC_RBRC), MO(LAYER_SYMB),

  KC_RALT, KC_ESC,
  KC_PGUP,
  KC_PGDN, KC_TAB,        KC_ENT

),

[LAYER_SYMB] = KEYMAP(
       // left hand
       VRSN   , KC_F1  , KC_F2    , KC_F3  , KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS, KC_EXLM, KC_AT    , KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
       KC_TRNS, KC_HASH, KC_DOLLAR, KC_LPRN, KC_RPRN, KC_GRV ,
       KC_TRNS, KC_PERC, KC_CIRC  , KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
       KC_NO  , KC_TRNS, KC_TRNS  , KC_TRNS, KC_TRNS,

                                                      KC_TRNS, KC_TRNS,
                                                               KC_TRNS,
                                             KC_TRNS, KC_TRNS, KC_TRNS,

       // right hand
       TG(LAYER_PLAIN), KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS,         KC_NO,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                        KC_NO,   KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS,         KC_NO,   KC_1,   KC_2,    KC_3,    KC_TILD, KC_TRNS,
                                 KC_0,   KC_DOT,  KC_NO,   KC_EQL,  KC_TRNS,

       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown| MsUp |MsRght|------|           |------| Left | Down |  Up  | Right|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 | Lclk | Rclk |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[LAYER_MDIA] = KEYMAP(
       RESET  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN2, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS , KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS , KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT , KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE , KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),

[LAYER_PLAIN] = KEYMAP(
  KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_PGUP,
  KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_PGDOWN,
  KC_LCTRL, KC_LGUI, KC_LALT, KC_LEFT, KC_RGHT,

                                           KC_INSERT,   KC_DELETE,
                                                        KC_F1,
                                  KC_SPC,  KC_KP_ENTER, KC_F2,


  KC_7,    KC_8, KC_9,  KC_0,     KC_MINUS, KC_EQUAL,  KC_BSPC,
  KC_HOME, KC_Y, KC_U,  KC_I,     KC_O,     KC_P,      KC_BSLASH,
           KC_H, KC_J,  KC_K,     KC_L,     KC_SCOLON, KC_ENTER,
  KC_END,  KC_N, KC_M,  KC_COMMA, KC_DOT,   KC_SLASH,  KC_RSHIFT,
                 KC_UP, KC_DOWN,  KC_RGUI,  KC_APP,    KC_RCTRL,

  KC_LBRACKET, KC_RBRACKET,
  KC_F3,
  KC_F4,       KC_KP_MINUS, KC_KP_PLUS
)
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(LAYER_SYMB)  // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};


#define ARRAY_COUNT(ARRAY) (sizeof(ARRAY) / sizeof(ARRAY[0]))

static PROGMEM const keypos_t emulation_exit_combo_keys[] = {
  {.col=1, .row=6}, {3,6}, {1,7}, {3,7}
};

static int8_t emulation_exit_combo_counter = 0;

static void exit_emulation(void) {
  layer_state = default_layer_state;
  clear_keyboard();
  emulation_exit_combo_counter = 0;
}

static bool is_emulation_exit_combo_key(keypos_t* pos) {
  for(uint8_t i = 0; i < ARRAY_COUNT(emulation_exit_combo_keys); ++i) {
    const keypos_t* cmp = emulation_exit_combo_keys + i;
    if(   pgm_read_byte(&cmp->col) == pos->col
       && pgm_read_byte(&cmp->row) == pos->row)
      return true;
  }
  return false;
}

static bool process_emulation_exit_combo(keyevent_t* event) {
  if(is_emulation_exit_combo_key(&event->key)) {
    if(event->pressed) {
      ++emulation_exit_combo_counter;
      if(emulation_exit_combo_counter == ARRAY_COUNT(emulation_exit_combo_keys)) {
        exit_emulation();
        return false;
      }
    }
    else
      --emulation_exit_combo_counter;
  }

  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if(biton32(layer_state) == LAYER_PLAIN) {
    // the return value is ignored because the plain layer must deliver each key press
    // immediately to the host
    process_emulation_exit_combo(&record->event);
  }else {
    switch (keycode) {
      // dynamically generate these.
      case EPRM:
        if (record->event.pressed) {
          eeconfig_init();
        }
        return false;
        break;
      case VRSN:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        return false;
        break;
    }
  }

  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
// TODO: doesn't look like a good idea to do it here...
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case LAYER_SYMB:
            ergodox_right_led_1_on();
            break;
        case LAYER_MDIA:
            ergodox_right_led_2_on();
            break;
        case LAYER_PLAIN:
            ergodox_right_led_3_on();
            if(emulation_exit_combo_counter % 2)
              ergodox_right_led_1_on();
            if(emulation_exit_combo_counter / 2)
              ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
};
