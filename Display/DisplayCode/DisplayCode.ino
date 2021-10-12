#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

LiquidCrystal_I2C lcd(0x24,16,2);
Adafruit_SSD1306 oled(128, 64, &Wire, -1);

void setup() {
 lcdDisplay("Welcome LCD");
 oledDisplay("Welcome OLED");
}

void loop() {
}

void lcdDisplay(String text)
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print(text);
}
void oledDisplay(String text)
{
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(0, 10);
  oled.println(text); 
  oled.display();
}
