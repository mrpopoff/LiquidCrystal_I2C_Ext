#include "LiquidCrystal_I2C_Ext.h"

#include <inttypes.h>
#include <Arduino.h>
#include <Wire.h>

LiquidCrystal_I2C_Ext::LiquidCrystal_I2C_Ext(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows, Utf8toAsc* translator):
	LiquidCrystal_I2C(lcd_addr, lcd_cols, lcd_rows)
{
	_translator = translator;

	if (!_translator)
		_translator = Utf8toAscDefault::getInstance();
}

inline size_t LiquidCrystal_I2C_Ext::write(uint8_t value) {

	uint8_t decoded = _translator->translate(value);

	if (decoded > 0) {
		LiquidCrystal_I2C::write(decoded);
	}

	return 1;
}


