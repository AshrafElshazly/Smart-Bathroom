#include <smartBath.h>

LiquidCrystal_I2C lcd(0x24,16,2);
Adafruit_SSD1306 oled(128, 64, &Wire, -1);
Servo motor1;

void setup() {
 lcdDisplay(lcd,"Welcome LCD");
 oledDisplay(oled,"Welcome OLED");
 servoAngle(motor1, 22, 180 , "open");
}

void loop() {

}
