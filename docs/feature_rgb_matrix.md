# RGB Matrix Lighting

There is basic support for addressable RGB matrix lighting with the I2C IS31FL3731 RGB controller. To enable it, add this to your `rules.mk`:

    RGB_MATRIX_ENABLE = yes

Configure the hardware via your `config.h`:

	// This is a 7-bit address, that gets left-shifted and bit 0
	// set to 0 for write, 1 for read (as per I2C protocol)
	// The address will vary depending on your wiring:
	// 0b1110100 AD <-> GND
	// 0b1110111 AD <-> VCC
	// 0b1110101 AD <-> SCL
	// 0b1110110 AD <-> SDA
	#define DRIVER_ADDR_1 0b1110100
	#define DRIVER_ADDR_2 0b1110110

	#define DRIVER_COUNT 2
	#define DRIVER_1_LED_TOTAL 25
	#define DRIVER_2_LED_TOTAL 24
	#define DRIVER_LED_TOTAL DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL

Currently only 2 drivers are supported, but it would be trivial to support all 4 combinations.

Define these arrays:

	const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
	/* Refer to IS31 manual for these locations
	 *   driver
	 *   |  R location
	 *   |  |      G location
	 *   |  |      |      B location
	 *   |  |      |      | */
	    {0, C1_3,  C2_3,  C3_3},
	    ....
	}

Where `Cx_y` is the location of the LED in the matrix defined by [the datasheet](http://www.issi.com/WW/pdf/31FL3731.pdf). The `driver` is the index of the driver you defined in your `config.h`.

	const rgb_led g_rgb_leds[DRIVER_LED_TOTAL] = {
	/* {row | col << 4}
	 *    |           {x=0..224, y=0..64}
	 *    |              |               modifier
	 *    |              |                 | */
	    {{0|(0<<4)},   {20.36*0, 21.33*0}, 1},
	    {{0|(1<<4)},   {20.36*1, 21.33*0}, 1},
	    ....
	}

The format for the matrix position used in this array is `{row | (col << 4)}`. The `x` is between (inclusive) 0-224, and `y` is between (inclusive) 0-64. The easiest way to calculate these positions is:

    x = 224 / ( NUMBER_OF_ROWS - 1 ) * ROW_POSITION
    y = 64 / (NUMBER_OF_COLS - 1 ) * COL_POSITION

Where all variables are decimels/floats.

## Keycodes

Many RGB keycodes are currently shared with the RGBLIGHT system:

	* `RGB_TOG` - toggle
	* `RGB_MOD` - cycle through modes
	* `RGB_HUI` - increase hue
	* `RGB_HUD` - decrease hue
	* `RGB_SAI` - increase saturation
	* `RGB_SAD` - decrease saturation
	* `RGB_VAI` - increase value
	* `RGB_VAD` - decrease value


	* `RGB_MODE_*` keycodes will generally work, but are not currently mapped to the correct effects for the RGB Matrix system

## Custom layer effects

Customised effects can be defined with 

## Additional `config.h` Options

	#define RGB_MATRIX_KEYPRESSES // reacts to keypresses (will slow down matrix scan by a lot)
	#define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (not recommened)
	#define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
	#define RGB_DISABLE_WHEN_USB_SUSPENDED false // turn off effects when suspended

## EEPROM storage

The EEPROM for it is currently shared with the RGBLIGHT system (it's generally assumed only one RGB would be used at a time), but could be configured to use its own 32bit address with:

    #define EECONFIG_RGB_MATRIX (uint32_t *)16

