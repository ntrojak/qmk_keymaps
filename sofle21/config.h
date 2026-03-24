#pragma once

#define MASTER_LEFT

// #define CUSTOM_FONT
//Why does only Sofle configs have this? It's not even in QMK's docs
// #define CUSTOM_LAYER_READ //if you remove this it causes issues - needs better guarding

#define TAPPING_TERM 180
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 100
#define TAPPING_TOGGLE 2
#define ONESHOT_TAP_TOGGLE 2

#define ENCODER_DIRECTION_FLIP
#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4



#define RGBLIGHT_SLEEP
//
// #define RGBLIGHT_LAYERS

/* ws2812 RGB LED */
#define WS2812_DI_PIN D3



#ifdef RGBLIGHT_ENABLE
    #undef RGBLIGHT_LED_COUNT

	#define RGBLIGHT_EFFECT_BREATHING
	#define RGBLIGHT_EFFECT_RAINBOW_MOOD
	#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
	//#define RGBLIGHT_EFFECT_SNAKE
	#define RGBLIGHT_EFFECT_KNIGHT
	//#define RGBLIGHT_EFFECT_CHRISTMAS
	//#define RGBLIGHT_EFFECT_STATIC_GRADIENT
	//#define RGBLIGHT_EFFECT_RGB_TEST
	//#define RGBLIGHT_EFFECT_ALTERNATING
	#define RGBLIGHT_EFFECT_TWINKLE

    #define RGBLIGHT_LED_COUNT 70

    #undef RGBLED_SPLIT
	//#define RGBLED_SPLIT
	#define RGBLED_SPLIT { 35, 35 } // haven't figured out how to use this yet

	//#define RGBLIGHT_LED_COUNT 30
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
    #define RGBLIGHT_LIMIT_VAL 120
#endif

// #define RGB_MATRIX_ENABLE
#ifdef RGB_MATRIX_ENABLE
// #define RGBLIGHT_LED_COUNT 35    // Number of LEDs
// #define RGB_MATRIX_LED_COUNT RGBLIGHT_LED_COUNT
#endif

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
#   define RGB_MATRIX_SLEEP // turn off effects when suspended
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #   define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.

#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT

#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10

/* Disable the animations you don't want/need.  You will need to disable a good number of these    *
 * because they take up a lot of space.  Disable until you can successfully compile your firmware. */
 #   define ENABLE_RGB_MATRIX_ALPHAS_MODS
 #   define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
 #   define ENABLE_RGB_MATRIX_BREATHING
 #   define ENABLE_RGB_MATRIX_CYCLE_ALL
 #   define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
 #   define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
 #   define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
 #   define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
 #   define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
 #   define ENABLE_RGB_MATRIX_DUAL_BEACON
 #   define ENABLE_RGB_MATRIX_RAINBOW_BEACON
 #   define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
 #   define ENABLE_RGB_MATRIX_RAINDROPS
 #   define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
 #   define ENABLE_RGB_MATRIX_TYPING_HEATMAP
 #   define ENABLE_RGB_MATRIX_DIGITAL_RAIN
 #   define ENABLE_RGB_MATRIX_SOLID_REACTIVE
 #   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
 #   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
 #   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
 #   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
 #   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
 #   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
 #   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
 #   define ENABLE_RGB_MATRIX_SPLASH
 #   define ENABLE_RGB_MATRIX_MULTISPLASH
 #   define ENABLE_RGB_MATRIX_SOLID_SPLASH
 #   define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif
