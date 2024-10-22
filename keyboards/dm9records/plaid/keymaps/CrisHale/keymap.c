/* Copyright 2019 Takuya Urakawa (dm9records.com)
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

/* Changelog
	
	02/11/2023
	+ Updated coding for leader key following overhaul of implementation
	
	22/06/2022
	+ Added comma to numpad
	
	14/02/2022
	+ Updated leader keys, inc. next song, sleep (removed), multiplication symbol, and work e-mail
	+ Moved colon on _NUM layer for easier use
	
	08/10/2021
	+ Changed main layout around arrows:
		- Changed CAPS, MPLAY, and MNXT to leader combos
		- Removed TT(_ARR) key and arrows layer
		- Added arrows to main layer
	
	10/03/2021
	+ Added Function buttons layer
	+ Updated list of leader sequences
	
	05/12/2020
	+ Added backtick (`) to symbols (1, 11)
	
	28/11/2020
	+ Created leader sets for:
		- END key: END
		- HOME key: HOME

	22/11/2020
	- Edited leader sets for Steam and Chrome to use Run command
	+ Created leader set for Close: CLOSE
	
	23/10/2020
	+ Created leader sets for:
		- Multiplication symbol: *
		- Upper case omega: OHM
		- Lower case omega: RAD
	
	18/09/2020
	+ Created leader sets for:
		- Steam: STEAM
		- Chrome: WEB
		- Task Manager: TM

   16/09/2020
	+ Made (4,12) tap key for Arrows layer
		- Changed (4,12) on Arrows layer to toggle off
	+ Moved menu to (3,7)

   25/08/2020
	+ Added the Leader key where Delete had been
	+ Created leader sets for:
		- F12: SCRN
		- "Best wishes,": BW 
	+ Moved Delete to Symbols layer

	19/08/2020
	- Fixed issue where lack of "SAFE_RANGE" in plaid_keycodes caused muting/refreshing on KC_NO keypresses

	17/08/2020
	+ Moved key for Arrows layer to its own key, to prevent issues
	+ Moved PrintScreen to main layer
	+ Moved Caps Lock, Pause, and Forward to the main layer
	+ Added Menu to the main layer
	+ Moved Calc key to reenable Esc on Numbers layer
	- Changed to inbuilt keycodes for toggling Numbers layer
	- Disabled 'Symbols - supplemental' layer, currently empty
	- Disabled Others layer, which had little purpose

	11/08/2020
	- Added use of the gaming layer, purely to allow screenshots in Steam

	20/07/2020
	- Adjusted NUM to have toggle and hold modes
	- Greatly increased transparency on NUM and ARR layers
	- Attempted to fix LEDMODE_LAYERS using layer_state_is() and failed

	16/07/2020
	- Enabled access to modifiers on NUM and ARR layers
	- Restored Del key
	- Moved AltGr to Tab
	- Moved Win
	- Included mute in NUM

	15/07/2020
	- Swapped O and N keys
	
	13/07/2020
	- Added equals symbol to _NUM and _SYM
	- Moved delete to backspace position on _OTHER
	- Added AltGr to layer 1
	- Added arrows to _GAME
	- Rejigged everything
	
	12/07/2020
	- Added F2 (Rename) to _OTHER
	
	06/07/2020
	- Added F5 to other for refresh
	- Added TRANS to B1 and B12 of _NUM for use of Tab and Enter

 */

#include QMK_KEYBOARD_H
#include "sendstring_uk.h"


//static uint16_t key_timer;
//static uint16_t time_elapsed;
static uint8_t red_mode;
static uint8_t green_mode;
//static uint8_t multi_level;

enum plaid_layers {
	_MN,
	_SYM,
//	_SUP,
	_NUM,
//	_OTH,
//	_GAM,
	_ARR,
	_FUN
};


enum plaid_keycodes {
	MUTE_F5 = SAFE_RANGE
/*
	ENG = SAFE_RANGE,
	SY_AR,
	NUM,
	LED_1,
	LED_2,
	LED_3,
	LED_4
*/
};


// Define shortcuts here
//#define OTH OSL(_OTH)

// Array of layers for use in LEDMODE_LAYERS
const uint16_t layers[] = {
  _MN,
  _SYM,
//  _SUP,
  _NUM,
//  _OTH,
//  _GAM,
  _ARR
};

// array of keys considered modifiers for led purposes
const uint16_t modifiers[] = {
//	SY_AR,
//	OTH,
	KC_LCTL,
	KC_LALT,
	KC_RALT,
	KC_LSFT,
	KC_LGUI
//	KC_RCTL,
//	KC_RSFT,
//	KC_RGUI
};

// Constants for LED modes
#define LEDMODE_ON 0 // Always on
#define LEDMODE_LAYERS 1 // On when not the default layer
#define LEDMODE_MODS 2 // On with modifiers

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
   /* TEMPLATE
	* ,-----------------------------------------------------------------------------------.
	* |      |      |      |      |      |      |      |      |      |      |      |      |
	* |------+------+------+------+------+-------------+------+------+------+------+------|
	* |      |      |      |      |      |      |      |      |      |      |      |      |
	* |------+------+------+------+------+------|------+------+------+------+------+------|
	* |      |      |      |      |      |      |      |      |      |      |      |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |      |      |      |      |      |      |      |      |
	* `-----------------------------------------------------------------------------------'
	*
	[_TEM] = LAYOUT_plaid_grid(
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),*/

   /* Main
	* ,-----------------------------------------------------------------------------------.
	* | Esc  | Mute |   Z  |   M  |   B  |   K  |   V  |  P   |   C  |   J  | Vol- | Vol+ |
	* |------+------+------+------+------+-------------+------+------+------+------+------|
	* | Tab  |  R   |   O  |   N  |   T  |   D  |   H  |  E   |   A  |   I  |  S   |Enter |
	* |------+------+------+------+------+------|------+------+------+------+------+------|
	* |AltGr |  Y   |   Q  |   G  |   U  |MoFUN | Menu |  L   |   W  |   X  |  F   | Win  |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |TapNUM| Ctrl | Alt  |PrtScr|Leader|Shift |Space |MoSYM | Left |  Up  | Down |Right |
	* `-----------------------------------------------------------------------------------'
	*/
	[_MN] = LAYOUT_plaid_grid(
		KC_ESC,		KC_MUTE,	KC_Z,		KC_M,		KC_B,		KC_K,		KC_V,	KC_P,		KC_C,		KC_J,	KC_VOLD,	KC_VOLU,
		KC_TAB,		KC_R,		KC_O,		KC_N,		KC_T,		KC_D,		KC_H,	KC_E,		KC_A,		KC_I,	KC_S,		KC_ENT,
		KC_ALGR,	KC_Y,		KC_Q,		KC_G,		KC_U,		MO(_FUN),	KC_APP,	KC_L,		KC_W,		KC_X,	KC_F,		KC_RGUI,
		TT(_NUM),	KC_LCTL,	KC_LALT,	KC_PSCR,	QK_LEAD,	KC_LSFT,	KC_SPC,	MO(_SYM),	KC_LEFT,	KC_UP,	KC_DOWN,	KC_RIGHT
	),
	
   /* Symbols
	* ,-----------------------------------------------------------------------------------.
	* |      |      |   *  |   =  |   _  |   /  |   @  |   £  |   $  |   "  |   `  |      |
	* |------+------+------+------+------+-------------+------+------+------+------+------|
	* |   |  |   :  |   ;  |   !  |   ?  |   \  |   #  |   ,  |   .  |   '  |   -  |      |
	* |------+------+------+------+------+------|------+------+------+------+------+------|
	* |      |   &  |   [  |   <  |   (  |   {  |   }  |   )  |   >  |   ]  |   ~  |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      | Del  |BSpace|      |______|      |      |      |      |
	* `-----------------------------------------------------------------------------------'
	*/
	[_SYM] = LAYOUT_plaid_grid(
		KC_NO,		KC_NO,		S(KC_8),	KC_EQL,		S(KC_MINS),	KC_SLSH,	S(KC_QUOT),	S(KC_3),	S(KC_4),	S(KC_2),	KC_GRV,		KC_NO,
		S(KC_NUBS),	S(KC_SCLN),	KC_SCLN,	S(KC_1),	S(KC_SLSH),	KC_NUBS,	KC_NUHS,	KC_COMM,	KC_DOT,		KC_QUOT,	KC_MINS,	KC_NO,
		KC_NO,		S(KC_7),	S(KC_LBRC),	S(KC_COMM),	S(KC_9),	KC_LBRC,	KC_RBRC,	S(KC_0),	S(KC_DOT),	S(KC_RBRC),	S(KC_NUHS),	KC_NO,
		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_DEL,		KC_BSPC,	KC_NO,		_______,	KC_NO,		KC_NO,		KC_NO,		KC_NO
	),
	
   /* Numbers
	* ,-----------------------------------------------------------------------------------.
	* |      |______|  %   |  (   |  )   |      |  :   |  7   |  8   |  9   |______|______|
	* |------+------+------+------+------+-------------+------+------+------+------+------|
	* |______|  /   |  *   |  -   |  +   |      |  /   |  4   |  5   |  6   |  0   |______|
	* |------+------+------+------+------+------|------+------+------+------+------+------|
	* |______|      |      |  =   |  ^   |      |  ,   |  1   |  2   |  3   |  .   |______|
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |OffNUM|______|______|______|______|______|______|______|______|______|______|______|
	* `-----------------------------------------------------------------------------------'
	*/
	[_NUM] = LAYOUT_plaid_grid(
		_______,	_______,	S(KC_5),	S(KC_9),	S(KC_0),	KC_NO,		S(KC_SCLN),	KC_7,		KC_8,		KC_9,		_______,	_______,
		_______,	KC_SLSH,	S(KC_8),	KC_MINS,	S(KC_EQL),	KC_NO,		KC_SLSH,	KC_4,		KC_5,		KC_6,		KC_0,		_______,
		_______,	KC_NO,		KC_NO,		KC_EQL,		S(KC_6),	KC_NO,		KC_COMM,		KC_1,		KC_2,		KC_3,		KC_DOT,	_______,
		TG(_NUM),	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),
	
	/* Function buttons
	 * ,-----------------------------------------------------------------------------------.
	 * |      |      |      |      |      |      |      |  F9  | F10  | F11	 | F12  |      |
	 * |------+------+------+------+------+-------------+------+------+------+------+------|
	 * |      |      |      |      |      |      |      |  F5  |  F6  |  F7  |  F8  |      |
	 * |------+------+------+------+------+------|------+------+------+------+------+------|
	 * |      |      |      |      |      |______|      |  F1  |  F2  |  F3  |  F4  |      |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      |      |      |      |      |      |      |      |      |      |      |      |
	 * `-----------------------------------------------------------------------------------'
	 */
	[_FUN] = LAYOUT_plaid_grid(
		KC_NO, KC_NO, KC_NO, KC_NO,	KC_NO,	KC_NO,		KC_NO,	KC_F9,	KC_F10,	KC_F11,	KC_F12,	KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO,	KC_NO,	KC_NO,		KC_NO,	KC_F5,	KC_F6,	KC_F7,	KC_F8,	KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO,	KC_NO,	_______,	KC_NO,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO,	KC_NO,	KC_NO,		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO
	),
};

/*
//Setup config struct for LED
typedef union {
  uint32_t raw;
  struct {
    uint8_t  red_mode :8;
    uint8_t  green_mode :8;
  };
} led_config_t;
led_config_t led_config;
*/

// Runs after the keyboard starts
void keyboard_post_init_user(void) {
	
	// Turn the red LED on
	writePinHigh(LED_RED);
	
	// Set the initial (currently permanent) mode for the green LED
	green_mode = LEDMODE_MODS;
}

void led_keypress_update(uint8_t led, uint8_t led_mode, uint16_t keycode, keyrecord_t *record) {
	switch (led_mode) {
		
		case LEDMODE_MODS:
		for (int i=0; i<sizeof(modifiers) / sizeof(modifiers[0]); i++) {
			if(keycode==modifiers[i]) {
				if (record->event.pressed) {
					writePinHigh(led);
				}
				else {
					writePinLow(led);
				}
			}
		}
		break;
		
		// Currently broken code
/*		case LEDMODE_LAYERS:
		multi_level = 0;
		for (int i=0; i<sizeof(layers)/sizeof(layers[0]); i++) {
			if(layer_state_is(layers[i])) {
				multi_level++;
			}
		}
		if (multi_level == 1) {
			writePinLow(led);
		}
		else {
			writePinHigh(led);
		}
		break;*/
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	
	/* If the either led mode is keypressed based, call the led updater
	   then let it fall through the keypress handlers. Just to keep 
	   the logic out of this procedure */
	   
/*	if (led_config.red_mode >= LEDMODE_MODS && led_config.red_mode <= LEDMODE_ENTER) {
		led_keypress_update(LED_RED, LEDMODE_ON, keycode, record);
	}*/
	
	if (red_mode == LEDMODE_MODS) {
		led_keypress_update(LED_RED, red_mode, keycode, record);
	}
	
	if (green_mode == LEDMODE_MODS) {
		led_keypress_update(LED_GREEN, green_mode, keycode, record);
	}

/*
	switch (keycode) {
		case LED_1:
		  if (record->event.pressed) {
			if (led_config.red_mode==LEDMODE_ON) {
				led_config.red_mode=LEDMODE_OFF;
				writePinLow(LED_RED);
			}
			else {
				led_config.red_mode=LEDMODE_ON;
				writePinHigh(LED_RED);
			}
		  }
		  eeconfig_update_user(led_config.raw);
		  return false;
		  break;
		case LED_2:
		  if (record->event.pressed) {
			if (led_config.green_mode==LEDMODE_ON) {
				led_config.green_mode=LEDMODE_OFF;
				writePinLow(LED_GREEN);
			}
			else {
				led_config.green_mode=LEDMODE_ON;
				writePinHigh(LED_GREEN);
			}
		  }
		  eeconfig_update_user(led_config.raw);
		  return false;
		  break;
		case LED_3:
		  led_config.red_mode=LEDMODE_MODS;
		  eeconfig_update_user(led_config.raw);
		  return false;
		  break;
		case LED_4:
		  led_config.green_mode=LEDMODE_MODS;
		  eeconfig_update_user(led_config.raw);
		  return false;
		  break;
	}
*/
	return true;
}

// Things to run after the keypress has been processed
/*
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
	
	if (red_mode == LEDMODE_LAYERS) {
		led_keypress_update(LED_RED, red_mode, keycode, record);
	}
	
	if (green_mode == LEDMODE_LAYERS) {
		led_keypress_update(LED_GREEN, green_mode, keycode, record);
	}
}
*/

void leader_end_user(void) {
	
	/*
	 * Combinations shared across all keyboards
	 */
	if(leader_sequence_one_key(KC_C)) { // Toggle caps lock
		tap_code(KC_CAPS);
		
	} else if (leader_sequence_two_keys(KC_C, KC_L)) { // Close focussed window
		register_code(KC_LALT);
		tap_code(KC_F4);
		unregister_code(KC_LALT);
		
	} else if (leader_sequence_one_key(KC_H)) { // The home button
		tap_code(KC_HOME);
		
	} else if (leader_sequence_two_keys(KC_J, KC_K)) { // Types out a joke
		SEND_STRING("What do you get if you pour hot water down a rabbit hole? Hot cross bunnies!");
		
	} else if (leader_sequence_two_keys(KC_J, KC_P)) { // Toggle Japanese or alphanumeric input with Google Japanese Input keyboard selected
		register_code(KC_LCTL);
		SEND_STRING("`");
		unregister_code(KC_LCTL);
		
    } else if (leader_sequence_one_key(KC_N)) { // The end button
		tap_code(KC_END);
		
	} else if (leader_sequence_one_key(KC_O)) { // On-screen keyboard
		register_code(KC_LCTL);
		register_code(KC_LGUI);
		tap_code(KC_O);
		unregister_code(KC_LGUI);
		unregister_code(KC_LCTL);
		
	} else if (leader_sequence_three_keys(KC_O, KC_F, KC_F)) { // Power down
		tap_code(KC_PWR);
		
	} else if (leader_sequence_one_key(KC_P)) { // Stop the music! (Or restart it)
		tap_code(KC_MPLY);
		
	} else if (leader_sequence_one_key(KC_RIGHT)) { // Skip to next song
		tap_code(KC_MNXT);
		
	} else if (leader_sequence_two_keys(KC_R, KC_S)) { // Reset to bootloader
		reset_keyboard();
		
	} else if (leader_sequence_one_key(KC_S)) { // Sleep
		tap_code(KC_SLEP);
		
	} else if (leader_sequence_one_key(KC_T)) { // Task manager shortcut
		register_code(KC_LCTL);
		register_code(KC_LALT);
		tap_code(KC_DEL);
		unregister_code(KC_LALT);
		unregister_code(KC_LCTL);
		
	}
	
	/*
	 * Combinations on this keymap only
	 */
	else if (leader_sequence_one_key(KC_E)) { // Output e-mail address
		SEND_STRING("cris.hale@outlook.com");
		
	} else if (leader_sequence_two_keys(KC_S, KC_T)) { // Stop playback
		tap_code(KC_MSTP);
		
	} else if (leader_sequence_two_keys(KC_W, KC_E)) { // Output work e-mail address
		SEND_STRING("chale@oka.com");
		
	}
}
