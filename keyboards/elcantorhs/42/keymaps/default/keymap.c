// Copyright 2021 azhizhinov (@azhizhinov)
// SPDX-License-Identifier: GPL-2.0-or-late
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _GAMING,
    _GM_LWR,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define NBS_LGU MT(MOD_LGUI, KC_NUBS)
#define ENT_LCT MT(MOD_LCTL, KC_ENT)
#define SPC_LSH MT(MOD_LSFT, KC_SPC)
#define J_LAL   MT(MOD_LALT, KC_J)
#define TAB_RAL MT(MOD_RALT, KC_TAB)
#define DEL_RSH MT(MOD_RSFT, KC_DEL)
#define TAB_LWR LT(_LOWER, KC_TAB)
#define BSP_LWR LT(_LOWER, KC_BSPC)
#define ESC_RSE LT(_RAISE, KC_ESC)
#define GM_LWR  MO(_GM_LWR)

#define OSM_SFT OSM(MOD_LSFT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_MEH OSM(MOD_MEH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
    KC_G,       KC_Q,   KC_W,    KC_L,    KC_T,    KC_H,         KC_Y,    KC_P,    KC_U,    KC_LBRC, KC_RBRC, RCTL_T(KC_GRV),
    J_LAL,      KC_R,   KC_N,    KC_A,    KC_S,    KC_D,         KC_K,    KC_E,    KC_O,    KC_I,    KC_M,    LALT_T(KC_SCLN),
                KC_X,   KC_Z,    KC_C,    KC_V,    KC_F,         KC_B,    KC_QUOT, KC_COMM, KC_DOT,  KC_SLSH,
                        NBS_LGU, TAB_LWR, SPC_LSH, ENT_LCT,      ESC_RSE, BSP_LWR, DEL_RSH, RALT_T(KC_BSLS)
    ),
[_GAMING] = LAYOUT(
    KC_G,   KC_I,      KC_Q,    KC_W,    KC_E,    KC_R,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	KC_T,   KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	          KC_X,    KC_Z,    KC_C,    KC_V,    KC_M,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        _______, _______, KC_SPC, _______,       _______, _______, _______, _______
),
[_GM_LWR] = LAYOUT(
    KC_COMM,   KC_RBRC, KC_LBRC, KC_G,    KC_O,    KC_H,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_DOT,    KC_0,    KC_9,    KC_8,    KC_7,    KC_6,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
               OSM_ALT, OSM_CTL, OSM_SFT, OSM_MEH, KC_N,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        _______, _______, _______, _______,      _______, _______, _______, _______
    ),
[_LOWER] = LAYOUT(
    KC_F1,      KC_F2,   KC_F3,  KC_F4,    KC_F5,    KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,
    KC_EQL,     KC_1,    KC_2,    KC_3,    KC_4,     KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,
                KC_WBAK, KC_WFWD, KC_CALC, KC_MAIL,  TG(1),      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        _______, TAB_RAL, _______, _______,      _______, _______, _______, _______
    ),
[_RAISE] = LAYOUT(
    KC_NUM,     KC_PSLS, KC_P7,   KC_P8,   KC_P9,  KC_PMNS,      KC_VOLU, KC_HOME, KC_PSCR, KC_PGUP,  KC_SLEP, KC_CAPS,
    KC_PEQL,    KC_PAST, KC_P1,   KC_P2,   KC_P3,  KC_PPLS,      KC_MUTE, KC_LEFT, KC_UP,   KC_RGHT,  KC_MPRV, KC_MNXT,
                KC_P0,   KC_P4,   KC_P5,   KC_P6,  KC_PCMM,      KC_VOLD, KC_END,  KC_DOWN, KC_PGDN,  KC_MPLY,
                        _______, _______, _______, _______,      _______, _______, _______, _______
    ),
[_ADJUST] = LAYOUT(
    XXXXXXX,   MS_ACL2, XXXXXXX, XXXXXXX, XXXXXXX, MS_WHLU,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,   MS_ACL1, MS_LEFT, MS_UP,   MS_RGHT, MS_WHLD,      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
               MS_ACL0, MS_WHLL, MS_DOWN, MS_WHLR, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        _______, MS_BTN2, MS_BTN3, MS_BTN1,      _______, _______, _______, _______
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

const uint16_t PROGMEM def_MOrse[] = {TAB_LWR, SPC_LSH, COMBO_END};
const uint16_t PROGMEM lwr_MOrse[] = {TAB_RAL, SPC_LSH, COMBO_END};
const uint16_t PROGMEM gm_MOgml[] = {TAB_LWR, KC_SPC, COMBO_END};
const uint16_t PROGMEM gj_esc[] = {KC_G, J_LAL, COMBO_END};
const uint16_t PROGMEM gt_esc[] = {KC_G, KC_T, COMBO_END};
const uint16_t PROGMEM rx_gui[] = {KC_R, KC_X, COMBO_END};
const uint16_t PROGMEM COMB_F7[] = {KC_F1, KC_EQL, COMBO_END};
const uint16_t PROGMEM COMB_F8[] = {KC_F2, KC_1, COMBO_END};
const uint16_t PROGMEM COMB_F9[] = {KC_F3, KC_2, COMBO_END};
const uint16_t PROGMEM COMB_F10[] = {KC_F4, KC_3, COMBO_END};
const uint16_t PROGMEM COMB_F11[] = {KC_F5, KC_4, COMBO_END};
const uint16_t PROGMEM COMB_F12[] = {KC_F6, KC_5, COMBO_END};
const uint16_t PROGMEM COMB_6[] = {KC_WBAK, KC_1, COMBO_END};
const uint16_t PROGMEM COMB_7[] = {KC_WFWD, KC_2, COMBO_END};
const uint16_t PROGMEM COMB_8[] = {KC_CALC, KC_3, COMBO_END};
const uint16_t PROGMEM COMB_9[] = {KC_MAIL, KC_4, COMBO_END};
const uint16_t PROGMEM COMB_0[] = {TG(1), KC_5, COMBO_END};

combo_t key_combos[] = {
    COMBO(def_MOrse, MO(_RAISE)),
    COMBO(lwr_MOrse, MO(_RAISE)),
    COMBO(gm_MOgml, MO(_GM_LWR)),
    COMBO(gj_esc, KC_ESC),
    COMBO(gt_esc, KC_ESC),
    COMBO(rx_gui, MOD_LGUI),
    COMBO(COMB_F7, KC_F7),
    COMBO(COMB_F8, KC_F8),
    COMBO(COMB_F9, KC_F9),
    COMBO(COMB_F10, KC_F10),
    COMBO(COMB_F11, KC_F11),
    COMBO(COMB_F12, KC_F12),
    COMBO(COMB_6, KC_6),
    COMBO(COMB_7, KC_7),
    COMBO(COMB_8, KC_8),
    COMBO(COMB_9, KC_9),
    COMBO(COMB_0, KC_0),
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     static uint16_t key_timer;

//     switch (keycode) {
//         // Тут может быть прописано дополнительное или нестандартное действие
//         return false; // Не обрабатывать стандартное действие
//     }
//     return true; // Обрабатывать остальные кейкоды как обычно
// }

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NBS_LGU:
            // Immediately select the hold action when another key is pressed.
            return false;
        case TAB_LWR:
            return false;
        case SPC_LSH:
            return false;
        case ENT_LCT:
            return false;
        case ESC_RSE:
            return false;
        case BSP_LWR:
            return false;
        case DEL_RSH:
            return false;
        case RALT_T(KC_BSLS):
            return false;
        default:
            // Do not select the hold action when another key is pressed.
            return true;
    }
}
