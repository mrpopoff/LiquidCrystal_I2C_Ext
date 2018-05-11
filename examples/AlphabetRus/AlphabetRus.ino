// ----------------------------------------------------------------------------
// LiquidCrystal_I2C_Ext - AlphabetRus
// ----------------------------------------------------------------------------
// 
// Sketch prints utf-8 encoded cyrillic test messages on the lcd
// using utf-8 to ascii translation table
//
// Демонстрация использования расширения библиотеки LiquidCrystal_I2C
// с поддержкой таблицы трансляции кодов символов из UTF-8 в байты.
//
// Скетч циклически выводит строки русского алфавита на дисплей.
//

#include <LiquidCrystal_I2C_Ext.h>

// utf-8 to ascii translation table for Russian
#include <Utf8toAscRu.h>

#define SIZEOF_ARRAY(x) (sizeof(x)/sizeof(x[0]))
#define PGMSTR(x) (__FlashStringHelper*)(x)

// The number of the buil-in LED pin
const int ledPin = LED_BUILTIN;

// Variables will change:
boolean ledState = false;       // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

// Interval at which to display test message
const long messageInterval = 3000;
// Blink led interval
const long testBlink = 1000;

// Test messages
const char* const messageTable[] PROGMEM = {
    "Привет, мир!",
    "АБВГДЕЁЖЗИЙКЛМНО",
    "ПРСТУФХЦЧШЩЪЫЬЭЮ",
    "Я",
    "абвгдеёжзийклмно",
    "прстуфхцчшщъыьэю",
    "я"
};

// Test message index
byte messageIndex = 0;

// Russian translation table
Utf8toAscRu russianAlphabet = Utf8toAscRu();

// LCD i2c address
const int LCD_I2C_ADDR = 0x27;

// LCD geometry
const int LCD_COLS = 16;
const int LCD_ROWS = 2;

// Declare lcd object with the 0x27 i2c address 
// for a 16 chars and 2 line display with russian alphabet translation table
LiquidCrystal_I2C_Ext lcd(LCD_I2C_ADDR, LCD_COLS, LCD_ROWS, &russianAlphabet);

// The setup function runs once when you press reset or power the board
void setup() { 
    // initialize digital pin LED_BUILTIN as an output
    pinMode(ledPin, OUTPUT);      

    // init variables
    messageIndex = 0;
    ledState = false;

    // initialize LCD
    lcd.init();
    
    // print a message to the LCD
    lcd.print("init test...");
}

// The loop function runs over and over again forever
void loop() {
    unsigned long currentMillis = millis();

    // check test message display time interval
    if(currentMillis - previousMillis > messageInterval) {
        // remember current time
        previousMillis = currentMillis;

        // clear LCD
        lcd.clear();
        // print a message to the LCD
        lcd.print((const char*)pgm_read_word(&(messageTable[messageIndex])));

        // calculate next test message index
        messageIndex = (messageIndex + 1) % SIZEOF_ARRAY(messageTable);
    }
    
    digitalWrite(ledPin, ledState); // set led state    
    ledState = !ledState;           // invert led state (blink)
    
    delay(testBlink);               // wait for the next loop
}

