#include "config.h"
#include QMK_KEYBOARD_H
#include <stdio.h>

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

enum sofle_layers {
    _DEFAULTS = 0,
    _BASE = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _GAMING,
    _GAMING_R2L,
    _GAMING_FUN
};


//Left Home Row
#define LG_UNDS LGUI_T(KC_UNDS)
#define LA_MINS LALT_T(KC_MINS)
#define LC_PLUS LCTL_T(KC_PLUS)
#define LS_EQL LSFT_T(KC_EQL)

#define LA_CIRC LALT_T(KC_CIRC)
#define LC_AMPR LCTL_T(KC_AMPR)
#define LS_DLR LSFT_T(KC_DLR)

#define LG_LPRN LGUI_T(KC_LPRN)
#define LA_RPRN LALT_T(KC_RPRN)
#define LC_LCBR LCTL_T(KC_LCBR)
#define LS_RCBR LSFT_T(KC_RCBR)

//Right Home Row
#define RS_4 RSFT_T(KC_4)
#define RC_5 RCTL_T(KC_5)
#define LA_6 LALT_T(KC_6)
#define RG_0 LGUI_T(KC_0)

#define RS_DOWN RSFT_T(KC_DOWN)
#define RC_UP RCTL_T(KC_UP)
#define LA_RGHT LALT_T(KC_RGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_APP, KC_1, KC_2, KC_3, KC_4, KC_5,                                                       KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
    KC_TAB, KC_Q, RALT_T(KC_W), KC_E, KC_R, KC_T,                                               KC_Y, KC_U, KC_I, RALT_T(KC_O), KC_P, KC_BSPC,
    KC_ESC, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,                       KC_H, RSFT_T(KC_J), RCTL_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT,
    KC_GRV, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE,                                     KC_PSCR, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_DEL,
    KC_NO, KC_NO, TT(_LOWER), KC_SPC, KC_ENT,                                                   TT(_RAISE), KC_LSFT, KC_RALT, KC_NO, TG(_GAMING)
  ),
  [_LOWER] = LAYOUT(
    TO(0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_PIPE, KC_PERC,                                         KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_TRNS,
    KC_TRNS, LG_UNDS, LA_MINS, LC_PLUS, LS_EQL, KC_COMM,                                        KC_DOT, RS_4, RC_5, LA_6, RG_0, KC_PIPE,
    KC_QUES, KC_COLN, KC_CIRC, KC_AMPR, KC_DLR, KC_ASTR, RM_TOGG,                      RM_TOGG, KC_BSLS, KC_1, KC_2, KC_3, KC_SLSH, KC_TRNS,
    KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS,                                                      TT(_ADJUST), KC_TRNS, TO(0), KC_NO, KC_NO
  ),
  [_RAISE] = LAYOUT(
    TO(0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_LT, KC_GT, KC_LBRC, KC_RBRC, KC_NO,                                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, 
    KC_TRNS, LG_LPRN, LA_RPRN, LC_LCBR, LS_RCBR, KC_NO,                                         KC_LEFT, RS_DOWN, RC_UP, LA_RGHT, KC_RGUI, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RM_TOGG,                                 RM_TOGG, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, KC_TRNS,
    KC_NO, KC_NO, TT(_ADJUST), KC_TRNS, KC_TRNS,                                                KC_NO, KC_TRNS, TO(0), KC_NO, KC_NO
  ),
  [_ADJUST] = LAYOUT(
    TO(0), KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT,                                                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                                 KC_NO, KC_F7, KC_F8, KC_F9, KC_F12, KC_TRNS,
    KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_PSCR,                                       KC_NO, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO,
    KC_NO, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, KC_CAPS, DT_PRNT,                        KC_MUTE, KC_NO, KC_F1, KC_F2, KC_F3, KC_F10, KC_TRNS,
    KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS,                                                      KC_NO, KC_TRNS, TO(0), KC_NO, KC_NO
  ),
  [_GAMING] = LAYOUT(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                                                       KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                                       KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                                                      KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE,                                    KC_MUTE, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
    OSL(_GAMING_R2L), KC_LALT, KC_SPC, KC_ENT, OSL(_GAMING_FUN),                                KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS
  ),
  [_GAMING_R2L] = LAYOUT(
    KC_NO, KC_NO, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC,                                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_Y, KC_U, KC_I, KC_O, KC_P,                                                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_H, KC_J, KC_K, KC_L, KC_SCLN,                                                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_PSCR,                            KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  ),
  [_GAMING_FUN] = LAYOUT(
    KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,                                                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_F11,                                                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_F12, KC_PSCR,                              KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  )
};

bool run_on_tap(uint16_t keycode, keyrecord_t *record) {
  if (record->tap.count && record->event.pressed) {
    tap_code16(keycode);
    return false;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LG_UNDS:
          return run_on_tap(KC_UNDS, record);
        case LA_MINS:
          return run_on_tap(KC_MINS, record);
        case LC_PLUS:
          return run_on_tap(KC_PLUS, record);
        case LS_EQL:
          return run_on_tap(KC_EQL, record);


        case LG_LPRN:
          return run_on_tap(KC_LPRN, record);
        case LA_RPRN:
          return run_on_tap(KC_RPRN, record);
        case LC_LCBR:
          return run_on_tap(KC_LCBR, record);
        case LS_RCBR:
          return run_on_tap(KC_RCBR, record);

        case RS_4:
          return run_on_tap(KC_4, record);
        case RC_5:
          return run_on_tap(KC_5, record);
        case LA_6:
          return run_on_tap(KC_6, record);
        case RG_0:
          return run_on_tap(KC_0, record);

        case RS_DOWN:
          return run_on_tap(KC_DOWN, record);
        case RC_UP:
          return run_on_tap(KC_UP, record);
        case LA_RGHT:
          return run_on_tap(KC_RGHT, record);
    }
    return true;
}

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LS_DLR:
    case LS_RCBR:
    case RS_4:
    case RS_DOWN:
      return TAPPING_TERM - 50;
    case LC_AMPR:
    case LC_LCBR:
    case RC_5:
    case RC_UP:
      return TAPPING_TERM - 30;
    default:
      return TAPPING_TERM;
  }
}
#endif

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_user(void) {
  // Disabling blinding indicator
  rgb_matrix_set_color(0,0,0,0);
  return false;
}
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD), },
    [_LOWER] = { ENCODER_CCW_CW(RM_SPDD, RM_SPDU), ENCODER_CCW_CW(RM_SATU, RM_SATD), },
    [_RAISE] = { ENCODER_CCW_CW(RM_NEXT, RM_PREV), ENCODER_CCW_CW(RM_VALU, RM_VALD), },
    #ifdef DYNAMIC_TAPPING_TERM_ENABLE
    [_ADJUST] = { ENCODER_CCW_CW(RM_HUEU, RM_HUED), ENCODER_CCW_CW(DT_DOWN, DT_UP), },
    #else
    [_ADJUST] = { ENCODER_CCW_CW(RM_HUEU, RM_HUED), ENCODER_CCW_CW(MS_WHLU, MS_WHLD), },
    #endif
    [_GAMING] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD), },
    [_GAMING_R2L] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD), },
    [_GAMING_FUN] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD), },
};
#endif

#ifdef OLED_ENABLE

#include "bongo.h"
char wpm_str[10];

static void print_status_narrow(void) {
    oled_write_ln_P(PSTR("NTr"), false);
    oled_write_ln_P(PSTR(""), false);
    oled_write_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adj"), false);
            break;
        case _GAMING:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        case _GAMING_R2L:
            oled_write_P(PSTR("Game2"), false);
            break;
        case _GAMING_FUN:
            oled_write_P(PSTR("GameF"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    #ifdef DYNAMIC_TAPPING_TERM_ENABLE
    oled_write_ln_P(PSTR(""), false);
    char tapping_term[50];
    snprintf(tapping_term, sizeof(tapping_term), "TT:\n%d", g_tapping_term);
    oled_write_ln_P(PSTR(tapping_term), false);
    #endif
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        draw_bongo();
    }
    return false;
}

#endif
