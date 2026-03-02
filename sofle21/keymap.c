#include "config.h"
#include QMK_KEYBOARD_H
#include <stdio.h>

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, hsv}
#define SET_UNDERGLOW(hsv) \
	{1, 6, hsv}, \
    {35+1, 6,hsv}
#define SET_GAMING(hsv)     \
	{35+15, 5, hsv},\
	  {35+22, 3, hsv},\
	  {35+27, 3, hsv}
#define SET_NUMROW(hsv) \
	{10, 2, hsv}, \
		{20, 2, hsv}, \
		{30, 2, hsv}, \
	  {35+ 10, 2, hsv}, \
	  {35+ 20, 2, hsv}, \
	  {35+ 30, 2, hsv}
#define SET_INNER_COL(hsv)	\
	{33, 4, hsv}, \
	  {35+ 33, 4, hsv}

#define SET_OUTER_COL(hsv) \
	{7, 4, hsv}, \
	  {35+ 7, 4, hsv}
#define SET_THUMB_CLUSTER(hsv) 	\
	{25, 2, hsv}, \
	  {35+ 25, 2, hsv}
#define SET_LAYER_ID(hsv) 	\
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
		{1, 6, hsv}, \
    {35+1, 6, hsv}, \
		{7, 4, hsv}, \
	  {35+ 7, 4, hsv}, \
		{25, 2, hsv}, \
	  {35+ 25, 2, hsv}

enum sofle_layers {
    _DEFAULTS = 0,
    _BASE = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _GAMING,
    _GAMING_R2L
};

enum custom_keycodes {
    KC_BASE = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_D_MUTE
};

//Left Bottom Row
#define LG_COLN LGUI_T(KC_SCLN)
#define LA_PLUS LALT_T(KC_PLUS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_APP, KC_1, KC_2, KC_3, KC_4, KC_5,                                                       KC_6, KC_7, KC_8, KC_9, KC_0, KC_PSCR,
    KC_TAB, KC_Q, RALT_T(KC_W), KC_E, KC_R, KC_T,                                               KC_Y, KC_U, KC_I, RALT_T(KC_O), KC_P, KC_BSPC,
    KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G,                                                       KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_GRV, LGUI_T(KC_Z), KC_X, LALT_T(KC_C), LCTL_T(KC_V), KC_B, KC_MUTE,             KC_MUTE, KC_N, RCTL_T(KC_M), LALT_T(KC_COMM), KC_DOT, RGUI_T(KC_SLSH), KC_DEL,
    TO(_ADJUST), KC_NO, TO(_RAISE), KC_SPC, KC_ENT,                                             TO(_LOWER), KC_LSFT, KC_RALT, KC_NO, TG(_GAMING)
  ),
  [_LOWER] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5,                                                      KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
    TO(_BASE), KC_LT, KC_LBRC, KC_LPRN, KC_LCBR, KC_NO,                                       KC_NO, KC_RCBR, KC_RPRN, KC_RBRC, KC_GT, KC_PIPE,
    KC_TRNS, LG_COLN, KC_MINS, LA_PLUS, LCTL_T(KC_EQL), KC_ASTR, KC_MUTE,              KC_MUTE, KC_UNDS, RCTL_T(KC_BSLS), LALT_T(KC_COMM), KC_DOT, RGUI_T(KC_SLSH), KC_TRNS,
    KC_NO, KC_NO, TO(_RAISE), KC_TRNS, KC_TRNS,                                                 KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO
  ),
  [_RAISE] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                                 KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
    TO(_BASE), KC_PGDN, KC_PGUP, KC_HOME, KC_END, KC_PSCR,                                    KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_INS, KC_F12,
    KC_TRNS, KC_LGUI, KC_NO, KC_LALT, KC_LCTL, KC_NO, KC_MUTE,                         KC_MUTE, KC_NO, KC_LCTL, KC_LALT, KC_NO, KC_LGUI, KC_TRNS,
    KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS,                                                    TO(_LOWER), KC_TRNS, KC_NO, KC_NO, KC_NO
  ),
  [_ADJUST] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    TO(_BASE), KC_NO, KC_NO, KC_NO, KC_NO, KC_CAPS,                                           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, KC_NO, DT_PRNT,                          KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS,                                                    KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO
  ),
  [_GAMING] = LAYOUT(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                                                       KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                                       KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                                                      KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE,                                    KC_MUTE, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
    KC_NO, MO(_GAMING_R2L), KC_LALT, KC_SPC, KC_ENT,                                            KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS
  ),
  [_GAMING_R2L] = LAYOUT(
    KC_NO, KC_NO, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC,                                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_Y, KC_U, KC_I, KC_O, KC_P,                                                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_H, KC_J, KC_K, KC_L, KC_SCLN,                                                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MUTE,                            KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RALT(KC_W):
    case RALT(KC_O):
    case LGUI(KC_Z):
    case LALT(KC_C):
    case LCTL(KC_V):
    case RCTL(KC_M):
    case LG_COLN:
    case LA_PLUS:
    case LCTL(KC_EQL):
    case RCTL(KC_BSLS):
    case LALT(KC_COMM):
    case RGUI(KC_SLSH):
    //   return TAPPING_TERM - 30;
    default:
      return TAPPING_TERM;
  }
}

bool run_on_tap(uint16_t keycode, keyrecord_t *record) {
  if (record->tap.count && record->event.pressed) {
    tap_code16(keycode);
    return false;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LG_COLN:
            return run_on_tap(KC_COLN, record);
        case LA_PLUS:
            return run_on_tap(KC_PLUS, record);
    }
    return true;
}

// #define RGBLIGHT_ENABLE
#ifdef RGBLIGHT_ENABLE
char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERTY,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_RED)

);
const rgblight_segment_t PROGMEM layer_colemakdh_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PINK)
);

// _NUM,
// Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_TEAL)

);
// _SYMBOL,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_BLUE)

    );
// _COMMAND,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PURPLE)
);

//_GAMING
const rgblight_segment_t PROGMEM layer_gaming_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_INDICATORS(HSV_ORANGE),
    SET_UNDERGLOW(HSV_ORANGE),
	SET_GAMING(HSV_BLUE),
    {7, 4, HSV_ORANGE},
    {25, 2, HSV_ORANGE},
    {35+6, 4, HSV_ORANGE},
    {35+25, 2, HSV_ORANGE}
    );

// _GAMING_R2L

// _SWITCHER   // light up top row
const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_GREEN),
	SET_NUMROW(HSV_GREEN)
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_qwerty_lights,
	layer_num_lights,// overrides layer 1
	layer_symbol_lights,
    layer_command_lights,
	layer_gaming_lights,
	layer_switcher_lights,  // Overrides other layers
	layer_colemakdh_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_BASE));
	// rgblight_set_layer_state(7, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_COLEMAKDH));
	rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
	rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
	rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
	rgblight_set_layer_state(4, layer_state_cmp(state, _GAMING));
	rgblight_set_layer_state(5, layer_state_cmp(state, _GAMING_R2L));
    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

	rgblight_mode(10);// haven't found a way to set this in a more useful way

}
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD), },
    [_LOWER] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD), },
    [_RAISE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD), },
    #ifdef DYNAMIC_TAPPING_TERM_ENABLE
    [_ADJUST] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(DT_DOWN, DT_UP), },
    #else
    [_ADJUST] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD), },
    #endif
    [_GAMING] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD), },
    [_GAMING_R2L] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD), },
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
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adj"), false);
            break;
        case _GAMING:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        case _GAMING_R2L:
            oled_write_ln_P(PSTR("Game2"), false);
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
