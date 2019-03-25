#include <util/delay.h>
#include "action_layer.h"
#include "action_util.h"
#include "bootloader.h"
#include "keymap_common.h"
#include "keymap_andri_macros.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Default Layer(Layer 0): Querty...ish
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   ~    |   1  |   2  |   3  |   4  |   5  |   \  |           |   -  |   6  |   7  |   8  |   9  |   0  |   =    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   E  |   R  |   T  |   [  |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   \    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | ESC    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
     * |--------+------+------+------+------+------|   (  |           |  )   |------+------+------+------+------+--------|
     * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |  NO  | LCtrl| CAPS | LGui | LAlt |                                       |  Lft |  Dn  |  Up  | Rght | RAlt |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | Home |  End |       |  NO  | MENU |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |  End |       | PgUp |      |      |
     *                                 | BkSp |  Del |------|       |------| Enter| Space|
     *                                 |      |      |  ESC |       | PgDn |      |      |
     *                                 `--------------------'       `--------------------'
     *
     * Layer 1: Function Keys
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  TRNS  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  | F10  | F11  | F12  |  TRNS  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |           | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |  TRNS  |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS |------|           |------| TRNS | TRNS | TRNS | TRNS | TRNS |  TRNS  |
     * |--------+------+------+------+------+------| TRNS |           | TRNS |------+------+------+------+------+--------|
     * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS |      |           |      | TRNS | TRNS | TRNS | TRNS | TRNS |  TRNS  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | TRNS | TRNS | TRNS | TRNS | TRNS |                                       | TRNS | TRNS | TRNS | TRNS | TRNS |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | TRNS | TRNS |       | TRNS | TRNS |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 | TRNS | TRNS |------|       |------| TRNS | TRNS |
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 `--------------------'       `--------------------'
     *
     * Layer 2: Just a simple numpad on the right hand
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |           |  NO  |  NO  | NLCK | PSLS | PAST | PMNS |  NO    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |           |  NO  |  NO  |   7  |   8  |   9  | PPLS |  PSCR  |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS |------|           |------|  NO  |   4  |   5  |   6  | PPLS |  SLCK  |
     * |--------+------+------+------+------+------| TRNS |           |  NO  |------+------+------+------+------+--------|
     * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS |      |           |      |  NO  |   1  |   2  |   3  | PENT |  PAUS  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | TRNS | TRNS | TRNS | TRNS | TRNS |                                       |   0  |   0  | PDOT | PEND |  NO  |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | TRNS | TRNS |       | TRNS | TRNS |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 | TRNS | TRNS |------|       |------| TRNS | TRNS |
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 `--------------------'       `--------------------'
     *
     * Layer 3: Visual Studio Debugging Hotkeys
     *      FN6: Ctrl + Pause/Break
     *      FN7: Shift + F10
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |           | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |  TRNS  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |           | TRNS | TRNS |  F6  | TRNS | TRNS |  FN6 |  TRNS  |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS |------|           |------| TRNS |  F5  |  F10 |  F11 |  FN7 |  TRNS  |
     * |--------+------+------+------+------+------| TRNS |           | TRNS |------+------+------+------+------+--------|
     * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS |      |           |      | TRNS | TRNS | TRNS | TRNS | TRNS |  TRNS  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | TRNS | TRNS | TRNS | TRNS | TRNS |                                       | TRNS | TRNS | TRNS | TRNS | TRNS |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | TRNS | TRNS |       | TRNS | TRNS |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 | TRNS | TRNS |------|       |------| TRNS | TRNS |
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 `--------------------'       `--------------------'
     *
     * Transparent template
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |           | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |  TRNS  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |           | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |  TRNS  |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS |------|           |------| TRNS | TRNS | TRNS | TRNS | TRNS |  TRNS  |
     * |--------+------+------+------+------+------| TRNS |           | TRNS |------+------+------+------+------+--------|
     * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS |      |           |      | TRNS | TRNS | TRNS | TRNS | TRNS |  TRNS  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | TRNS | TRNS | TRNS | TRNS | TRNS |                                       | TRNS | TRNS | TRNS | TRNS | TRNS |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | TRNS | TRNS |       | TRNS | TRNS |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 | TRNS | TRNS |------|       |------| TRNS | TRNS |
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 `--------------------'       `--------------------'
     *
     ****************************************************************************************************
     */

    KEYMAP(  // Layer0: default qwerty
        // left hand
         GRV,    1,   2,   3,   4,   5,   BSLS,
         TAB,    Q,   W,   E, FN3,   T,   LBRC,
         ESC,    A,   S,   D, FN4,   G,
         LSFT,   Z,   X,   C, FN5,   B,    FN1,
         NO, LCTRL,CAPS,LGUI,LALT,
                                      HOME, END,
                                            END,
                                 BSPC, DEL, ESC,
        // right hand
             MINS,6,   7,   8,   9,   0,    EQL,
             RBRC,Y,   U,   I,   O,   P,   BSLS,
                  H,   J,   K,   L,   SCLN,QUOT,
             FN2, N,   M,   COMM,DOT, SLSH,RSFT,
                       LEFT,DOWN,  UP,RGHT,RALT,
          NO,MENU,
        PGUP,
        PGDN, ENT, SPC
    ),
    KEYMAP(  // Layer1: function keys
        // left hand
        TRNS,  F1,  F2,  F3,  F4,  F5,  F6,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
               F7,  F8,  F9, F10, F11, F12,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
    KEYMAP(  // Layer2: right hand numpad
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
               NO,  NO,NLCK,PSLS,PAST,PMNS,  NO,
               NO,  NO,  P7,  P8,  P9,PPLS,PSCR,
                    NO,  P4,  P5,  P6,PPLS,SLCK,
               NO,  NO,  P1,  P2,  P3,PENT,PAUS,
                         P0,  P0,PDOT,PENT,  NO,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,P0
    ),
    KEYMAP(  // Layer3: Visual Studio layer
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,  F6,TRNS,TRNS, FN6,TRNS,
                  TRNS,  F5, F10, F11, FN7,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
};

/*
    // templates to copy from

    KEYMAP(  // LayerN: transparent on edges + hard-defined thumb keys, all others are empty
        // left hand
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,TRNS,TRNS,LALT,LGUI,
                                      TRNS,TRNS,
                                           TRNS,
                                 LCTL,LSFT,TRNS,
        // right hand
             NO,  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                       RGUI,RALT,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,RSFT,RCTL
    ),
    KEYMAP(  // LayerN: fully transparent
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
*/

/* id for user defined functions */
enum function_id 
{
    TEENSY_KEY,
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = 
{
//  [n] =   ACTION_*,                                       // FNn  - Purpose

    [0] =   ACTION_FUNCTION(TEENSY_KEY),                    // FN0  - Teensy key

    [1] =   ACTION_MODS_KEY(MOD_LSFT, KC_9),                // FN1  - Shift + 9
    [2] =   ACTION_MODS_KEY(MOD_LSFT, KC_0),                // FN2  - Shift + 10

    [3] =   ACTION_LAYER_TAP_KEY(1, KC_R),                  // FN3  - hold: layer1, tap: r
    [4] =   ACTION_LAYER_TAP_KEY(2, KC_F),                  // FN4  - hold: layer2, tap: f
    [5] =   ACTION_LAYER_TAP_KEY(3, KC_V),                  // FN5  - hold: layer3, tap: v
    
    [6] =   ACTION_MODS_KEY(MOD_LCTL, KC_PAUSE),            // FN6  - CTRL + Pause/Break
    [7] =   ACTION_MODS_KEY(MOD_LSFT, KC_F11),              // FN7  - Shift + F11

};

/*
const uint16_t PROGMEM fn_actions[] = 
{
    [0] =   ACTION_FUNCTION(TEENSY_KEY),                    // FN0  - Teensy key

    [1] =   ACTION_MODS_KEY(MOD_LSFT, KC_BSLS),             // FN1  = Shifted BackSlash // " in Workman
    [2] =   ACTION_MODS_KEY(MOD_LSFT, KC_MINS),             // FN2  = Shifted Minus     // \ in Workman
    [3] =   ACTION_MODS_KEY(MOD_LSFT, KC_COMM),             // FN3  = Shifted comma     // < in Workman
    [4] =   ACTION_MODS_KEY(MOD_LSFT, KC_DOT),              // FN4  = Shifted dot       // > in Workman

    [5] =   ACTION_MODS_TAP_KEY(MOD_LCTL, KC_BSPC),         // FN5  = LShift with tap BackSpace
    [6] =   ACTION_MODS_TAP_KEY(MOD_LSFT, KC_DEL),          // FN6  = LCtrl  with tap Delete
    [7] =   ACTION_MODS_TAP_KEY(MOD_LALT, KC_ESC),          // FN7  = LAlt   with tap Escape
    [8] =   ACTION_MODS_TAP_KEY(MOD_RALT, KC_INS),          // FN8  = RAlt   with tap Ins
    [9] =   ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT),          // FN9  = RShift with tap Enter
    [10] =  ACTION_MODS_TAP_KEY(MOD_RCTL, KC_SPC),          // FN10 = RCtrl  with tap Space

    [11] =  ACTION_MODS_TAP_KEY(MOD_LSFT, KC_TAB),          // FN11 = LShift with tap Tab
    [12] =  ACTION_MODS_TAP_KEY(MOD_LCTL, KC_GRV),          // FN12 = LCtrl  with tap Tilda
    [13] =  ACTION_MODS_TAP_KEY(MOD_LALT, KC_SPC),          // FN13 = LAlt   with tap Space
    [14] =  ACTION_MODS_TAP_KEY(MOD_LGUI, KC_ESC),          // FN14 = LGui   with tap Escape
    [15] =  ACTION_MODS_TAP_KEY(MOD_RSFT, KC_QUOT),         // FN15 = RShift with tap quotes
    [16] =  ACTION_MODS_TAP_KEY(MOD_RCTL, KC_RBRC),         // FN16 = RCtrl  with tap ]

    [17] =  ACTION_LAYER_SET(0, ON_BOTH),                   // FN17 - set Layer0
    [18] =  ACTION_LAYER_SET(1, ON_BOTH),                   // FN18 - set Layer1, to use Workman layout at firmware level
    [19] =  ACTION_LAYER_SET(2, ON_BOTH),                   // FN19 - set Layer2, to use with Numpad keys
    // i'd like to remove this - will try to get used to live without this and convert them to usual keys
    //[20] =  ACTION_LAYER_MOMENTARY(2),                      // FN20 - momentary Layer2, to use with Numpad keys
    // or
    //[20] =  ACTION_FUNCTION_TAP(CUSTOM_KEY),                // FN20 - use custom key, with tapping support

    [21] =  ACTION_FUNCTION_TAP(L_CTRL_ALT_ENT),            // FN21 - momentary Layer5+CTRL+ALT on Enter, to use with F* keys on top row
    [22] =  ACTION_FUNCTION_TAP(R_CTRL_ALT_ENT),            // FN22 - momentary Layer6+CTRL+ALT on Enter, to use with F* keys on top row + utils
    
    [23] =  ACTION_LAYER_TAP_KEY(7, KC_BSLS),               // FN23 - momentary Layer7 on ' , to use with F* keys (F1-F24)

    [24] =  ACTION_LAYER_TAP_KEY(4, KC_Z),                  // FN24 = momentary Layer4 on Z key, to use with unconvenient keys
    [25] =  ACTION_LAYER_TAP_KEY(3, KC_X),                  // FN25 = momentary Layer3 on X key, to use with F* keys
    [26] =  ACTION_LAYER_TAP_KEY(8, KC_C),                  // FN26 = momentary Layer8 on C key, to use with mouse and navigation keys
    [27] =  ACTION_LAYER_TAP_KEY(9, KC_V),                  // FN27 = momentary Layer9 on V key, to use with application-specific shortcuts

    [28] =  ACTION_LAYER_TAP_KEY(4, KC_A),                  // FN28 = momentary Layer4 on A key, to use with unconvenient keys
    [29] =  ACTION_LAYER_TAP_KEY(3, KC_S),                  // FN29 = momentary Layer3 on S key, to use with F* keys
    [30] =  ACTION_LAYER_TAP_KEY(8, KC_D),                  // FN30 = momentary Layer8 on D key, to use with mouse and navigation keys
    [31] =  ACTION_LAYER_TAP_KEY(2, KC_F),                  // FN31 = momentary Layer2 on F key, to use with Numpad keys
};
*/

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // print("action_function called\n");
    // print("id  = "); phex(id); print("\n");
    // print("opt = "); phex(opt); print("\n");

    if (id == TEENSY_KEY)
    {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(50);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }


/*
    // Example of custom function key
    if (id == L_CTRL_ALT_ENT || id == R_CTRL_ALT_ENT)
    {
        if (record->tap.count == 0 || record->tap.interrupted)
        {
            uint8_t weak_mods;
            uint8_t layer;

            if (id == L_CTRL_ALT_ENT)
            {
                weak_mods = MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT);
                layer     = 5;
            }
            else 
            {
                weak_mods = MOD_BIT(KC_RCTL) | MOD_BIT(KC_RALT);
                layer     = 6;
            }

            if (record->event.pressed)
            {
                layer_on(layer);
                add_weak_mods(weak_mods);
            }
            else
            {
                del_weak_mods(weak_mods);
                layer_off(layer);
            }
        }
        else
        {
            if (record->event.pressed)
            {
                add_key(KC_ENT);
                send_keyboard_report();
            }
            else
            {
                del_key(KC_ENT);
                send_keyboard_report();
            }
        }
    }
*/

}


/* id for user defined macros */
enum macro_id
{
    EXAMPLE,
};

#include "keymap_andri_macros.h"
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    if (record->event.pressed)
    {
        switch (id) 
        {
            case EXAMPLE:   return MACRO_EXAMPLE;
            default:        return MACRO_NONE;
        }
    }
    return MACRO_NONE;
}


/* FN action sizes */
#define FN_ACTIONS_SIZE     (sizeof(fn_actions) / sizeof(fn_actions[0]))
//#define FN_ACTIONS_<name>_SIZE   (sizeof(fn_actions_<name>) / sizeof(fn_actions_<name>[0]))

/*
 * Custom FN keycode to action function.
 * Can use special lookup table for each layer.
 */
#define CUSTOM_FN_TO_ACTION_FUNCTION 1
action_t keymap_fn_to_action(uint8_t keycode)
{
    uint8_t layer = biton32(layer_state);
    (void)layer;

    action_t action;
    action.code = ACTION_NO;

    // Special layer handling
    /*
    if (layer == <number> && FN_INDEX(keycode) < FN_ACTIONS_<number>_SIZE)
    {
        action.code = pgm_read_word(&fn_actions_<number>[FN_INDEX(keycode)]);
    }
    */

    // By default, use fn_actions from default layer.
    // this is needed to get mapping for same key, that was used switch to some layer,
    // to have possibility to switch layers back
    if (action.code == ACTION_NO && FN_INDEX(keycode) < FN_ACTIONS_SIZE) 
    {
        action.code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
    }

    return action;
}

