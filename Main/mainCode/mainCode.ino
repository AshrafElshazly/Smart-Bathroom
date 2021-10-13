#include <smartBath.h>

LiquidCrystal_I2C lcd(0x24,16,2);
Adafruit_SSD1306 oled(128, 64, &Wire, -1);

void setup() {
 lcdDisplay(lcd, "LCD Obj");
 oledDisplay(oled, "OLED obj");
}

void loop() {

}
