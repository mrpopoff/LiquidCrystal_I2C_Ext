#ifndef LIQUID_CRYSTAL_I2C_EXT_INCLUDED
#define LIQUID_CRYSTAL_I2C_EXT_INCLUDED

#include <inttypes.h>
#include <Print.h>

#include <LiquidCrystal_I2C.h>
#include <Utf8toAsc.h>

/**
 * This is the driver for the Liquid Crystal LCD displays that use the I2C bus.
 * Based on LiquidCrystal_I2C library (https://github.com/marcoschwartz/LiquidCrystal_I2C)
 * with UTF-8 codes translation support added.
 *
 * After creating an instance of this class, first call init() before anything else.
 * The backlight is on by default, since that is the most likely operating mode in
 * most cases.
 */
class LiquidCrystal_I2C_Ext : public LiquidCrystal_I2C {
public:
	/**
	 * Constructor
	 *
	 * @param lcd_addr	I2C slave address of the LCD display. Most likely printed on the
	 *	LCD circuit board, or look in the supplied LCD documentation.
	 * @param lcd_cols	Number of columns your LCD display has.
	 * @param lcd_rows	Number of rows your LCD display has.
	 * @param translator	UTF-8 to LCD character codes translation table interface
	 */
	LiquidCrystal_I2C_Ext(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows, Utf8toAsc* translator = 0);

	virtual size_t write(uint8_t data);

private:
	/* Character codes translation interface */
	Utf8toAsc* _translator;
};

#endif // LIQUID_CRYSTAL_I2C_EXT_INCLUDED
