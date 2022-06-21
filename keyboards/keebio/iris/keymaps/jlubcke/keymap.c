#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _LOWER,
    _UPPER,
    _ADJUST,
};

#define QWERTY   DF(_QWERTY)
#define LWR_ENT  LT(_LOWER, KC_ENT)
#define LWR_BSPC LT(_LOWER, KC_ENT)
#define UPR_SPC  LT(_UPPER, KC_SPC)
#define UPR_DEL  LT(_UPPER, KC_SPC)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)

// Home row modifiers
#define HRM_A    LSFT_T(KC_A)
#define HRM_S    LCTL_T(KC_S)
#define HRM_D    LALT_T(KC_D)
#define HRM_F    LGUI_T(KC_F)
#define HRM_J    RGUI_T(KC_J)
#define HRM_K    RALT_T(KC_K)
#define HRM_L    RCTL_T(KC_L)
#define HRM_SCLN RSFT_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                |   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------|                |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+------.  ,------+------+------+------+------+------+--------|
 * |  ` ~   |   Z  |   X  |   C  |   V  |   B  |  Del |  | Bksp |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------|  |------+------+------+------+----------------------'
 *                               | LAlt | LGUI |Lower/|  |Raise/| RGUI | AltGr|
 *                               |      |      |Enter |  |Space |      |      |
 *                               `--------------------'  `--------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_NO,          KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU,                    KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_NO,    KC_NO,
     KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,     KC_BSLS,
     CTL_ESC,        HRM_A,   HRM_S,   HRM_D,   HRM_F,   KC_G,                       KC_H,    HRM_J,  HRM_K,   HRM_L,  HRM_SCLN, KC_QUOT,
     LSFT_T(KC_GRV), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    UPR_DEL, LWR_BSPC, KC_N,    KC_M ,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                                                KC_LALT, KC_LGUI, LWR_ENT, UPR_SPC,  KC_RGUI, KC_RALT
    ),

/*
 * Lower layer
 *
 * ,-------------------------------------------.                ,-------------------------------------------.
 * |  Tab   |   !  |   @  |   #  |   $  |   %  |                |   ^  |   7  |   8  |   9  |   &  |   \ |  |
 * |--------+------+------+------+------+------|                |------+------+------+------+------+--------|
 * |Ctrl/Esc|   1  |   2  |   3  |   4  |   5  |                |   6  |   4  |   5  |   6  |   0  |        |
 * |--------+------+------+------+------+------+------.  ,------+------+------+------+------+------+--------|
 * |  ` ~   |   +  |   =  |   _  |   -  |  DEL |      |  |      |   0  |   1  |   2  |   3  |   *  | RShift |
 * `----------------------+------+------+------+------|  |------+------+------+------+----------------------'
 *                               |      |      |      |  |      |      |   0  |
 *                               |      |      |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 */
    [_LOWER] = LAYOUT(
    KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,                     KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,
    KC_TAB,  KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC,                   KC_CIRC, KC_7,         KC_8,         KC_9,         KC_AMPR,      KC_TRNS,
    CTL_ESC, LSFT_T(KC_1), LCTL_T(KC_2), LALT_T(KC_3), LGUI_T(KC_4), KC_5,                      KC_6,    RGUI_T(KC_4), RALT_T(KC_5), RCTL_T(KC_6), RSFT_T(KC_0), KC_TRNS ,
    KC_TRNS, KC_PLUS,      KC_EQL,       KC_UNDS,      KC_MINS,      KC_DEL,  KC_TRNS, KC_TRNS, KC_0,    KC_1,         KC_2,         KC_3,         KC_ASTR,      KC_TRNS ,
                                                       KC_LALT,      KC_LGUI, KC_TRNS, KC_TRNS, KC_RGUI, KC_RALT
    ),

/*
 * Upper layer
 *
 * ,-------------------------------------------.          `      ,-------------------------------------------.
 * |  Tab   |  F1  |  F2  |  F3  |  F4  |  F5  |                | PgUp | Home |  Up  |  End |  Ins |  \ |   |
 * |--------+------+------+------+------+------|                |------+------+------+------+------+--------|
 * |Ctrl/Esc|  F6  |  F7  |  F8  |  F9  |  F10 |                | PgDn | Left | Down | Right|   {  |    }   |
 * |--------+------+------+------+------+------+------.  ,------+------+------+------+------+------+--------|
 * |  ` ~   |  F11 |  F12 |      |      |      |      |  |      | Bksp |   (  |   )  |  [ { | ]  } | RShift |
 * `----------------------+------+------+------+------|  |------+------+------+------+----------------------'
 *                               |      |      |      |  |      |      |      |
 *                               |      |      |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 */
    [_UPPER] = LAYOUT(
     KC_NO,   KC_NO,         KC_NO,         KC_NO,         KC_NO,         KC_NO,                     KC_NO,   KC_NO,           KC_NO,            KC_NO,           KC_NO,           KC_NO,
     KC_TAB,  KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5,                     KC_PGUP, KC_HOME,         KC_UP,            KC_END,          KC_INS,          KC_BSLS,
     CTL_ESC, LSFT_T(KC_F6), LCTL_T(KC_F7), LALT_T(KC_F8), LGUI_T(KC_F9), KC_F10,                    KC_PGDN, RGUI_T(KC_LEFT), RALT_T(KC_DOWN) , RCTL_T(KC_RGHT), RSFT_T(KC_LCBR), KC_RCBR,
     KC_TRNS, KC_F1,         KC_F12,        KC_TRNS,       KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_LPRN,         KC_RPRN,          KC_LBRC,         KC_RBRC,         KC_TRNS,
                                                           KC_LALT,       KC_LGUI, KC_TRNS, KC_TRNS, KC_RGUI, KC_RALT
    ),
};
