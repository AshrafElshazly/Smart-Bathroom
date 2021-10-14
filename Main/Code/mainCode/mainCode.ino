#include <smartBath.h>

LiquidCrystal_I2C lcd(0x24,16,2);
Adafruit_SSD1306 oled(128, 64, &Wire, -1);
Servo motor1;
SoftwareSerial sim(2, 3); //(RX,TX)

void setup() {
  
}

void loop() {

}
