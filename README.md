# LiquidCrystal_I2C_Ext #
LiquidCrystal Arduino library for the PCF8574 based serial DFRobot (YwRobot) LCD I2C displays extension.
Based on LiquidCrystal_I2C Arduino library [https://github.com/marcoschwartz/LiquidCrystal_I2C](https://github.com/marcoschwartz/LiquidCrystal_I2C).
Adds support for character codes translation tables when printing utf-8 strings to the LCD.

## PCF8574

PCF8574 is Remote 8-bit I/O expander for I2C-bus.

![](https://os.mbed.com/media/uploads/wim/backpacks.jpg)

### PCF8574 Datasheet

[PCF8574 Datasheet](http://www.nxp.com/documents/data_sheet/PCF8574_PCF8574A.pdf)

### MT-16S2H

![](http://www.melt.com.ru/components/com_virtuemart/shop_image/product/MT_16S2H_2YLG_4da47fde499cb.jpg)

[Description](http://www.melt.com.ru/en/shop/mt-16s2h-2ylg.html)

### MT-16S2H Datasheet

[MT-16S2H Datasheet]http://www.melt.com.ru/docs/MT-16S2H.pdf

## How to install

Create a new folder called "LiquidCrystal_I2C_Ext" under the folder named "libraries" in your Arduino sketchbook folder.
Create the folder "libraries" in case it does not exist yet. Place all the files in the "LiquidCrystal_I2C_Ext" folder.

[Installing Additional Arduino Libraries](https://www.arduino.cc/en/Guide/Libraries)

## Usage
To use the library in your own sketch, select it from *Sketch > Import Library*.

## Releases

- 1.0.0 Initial release.

# License #
Copyright &copy; 2017 Nikita A. Popov. All rights reserved.
```
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
```