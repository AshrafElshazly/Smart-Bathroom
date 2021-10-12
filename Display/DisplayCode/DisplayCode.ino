#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

LiquidCrystal_I2C lcd(0x24,16,2);
Adafruit_SSD1306 oled(128, 64, &Wire, -1);

void setup() {
 lcdDisplay(lcd, "LCD Obj");
 oledDisplay(oled, "OLED obj");
}

void loop() {
}

void lcdDisplay(LiquidCrystal_I2C obj, String text)
{
  obj.init();
  obj.backlight();
  obj.setCursor(1,0);
  obj.print(text);
}
void oledDisplay(Adafruit_SSD1306 obj, String text)
{
  if (!obj.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }
  obj.clearDisplay();
  obj.setTextSize(1);
  obj.setTextColor(WHITE);
  obj.setCursor(0, 10);
  obj.println(text); 
  obj.display();
}
