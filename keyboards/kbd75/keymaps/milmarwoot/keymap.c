#include QMK_KEYBOARD_H

#define LOCK TG(L_LOCK)
#define COM  TG(L_COM)
#define FN   MO(L_FN)

#define LCTLL  LCTL(KC_L)
#define LCTLC  LCTL(KC_C)
#define LGUILE LGUI(KC_LEFT)
#define LGUIRI LGUI(KC_RIGHT)
#define LGUIUP LGUI(KC_UP)
#define LGUIDO LGUI(KC_DOWN)

#define CAPS_BIT (1 << 2)

enum layers {
  L_BASE,
  L_COM,
  L_LOCK,
  L_FN,
};

enum custom_keycodes {
  M_GIT = SAFE_RANGE,
  M_GREP,
  M_AWK,
  M_XARGS,
  M_4SPC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT( \
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME, KC_END,  KC_INS,  \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, KC_DEL,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,  KC_PGDN, \
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   LCTLC,   \
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,  M_4SPC,  LCTLL,                     KC_RALT, FN,      KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  [L_COM] = LAYOUT( \
    _______, M_GIT,   M_GREP,  M_AWK,   M_XARGS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
    _______, _______, _______,                   _______, _______, _______,                   _______, FN,      _______, _______, _______, _______  \
  ),

  [L_LOCK] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, FN,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  ),

  [L_FN] = LAYOUT( \
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LOCK,    \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, COM,     \
    _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,          _______, \
    _______, RGB_M_P, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, \
    _______, RGB_M_G, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, _______, _______, _______, _______, _______,          LGUIUP,  _______, \
    _______, _______, _______,                   _______, _______, _______,                   _______, _______, _______, LGUILE,  LGUIDO,  LGUIRI   \
  ),
};

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case L_BASE:
        rgblight_setrgb (0x00,  0x80, 0x80);
        break;
    case L_COM:
        rgblight_setrgb (0x00,  0x7F, 0x00);
        break;
    case L_LOCK:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    case L_FN:
        rgblight_setrgb (0x7A,  0x05, 0xD1);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
  case M_GIT:
    if (record->event.pressed) {
      SEND_STRING("git shorty" SS_TAP(X_ENTER));
    }
    return false;

  case M_GREP:
    if (record->event.pressed) {
      SEND_STRING("| grep");
    }
    return false;
  case M_AWK:
    if (record->event.pressed) {
      SEND_STRING("| awk '{print ");
    }
    return false;
  case M_XARGS:
    if (record->event.pressed) {
      SEND_STRING("| xargs -I{} ");
    }
    return false;
  case M_4SPC:
    if (record->event.pressed) {
      SEND_STRING("    ");
    }
    return false;
  default:
    return true;
  }
};

void led_set_user(uint8_t usb_led) {
  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    DDRB  |=  CAPS_BIT;
    PORTB &= ~CAPS_BIT;
  } else {
    DDRB  &= ~CAPS_BIT;
    PORTB &= ~CAPS_BIT;
  }
};
