#include "SmartBath.h"

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

void lcdDisplay(LiquidCrystal_I2C obj, String text)
{
  obj.init();
  obj.backlight();
  obj.setCursor(1,0);
  obj.print(text);
}

bool ultraResult(int trigPin,int echoPin,int destance)
{
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin,LOW);
 return (destance==(pulseIn(echoPin,HIGH)*0.017))? true : false;
}

int doUltraConfig (int trigPin ,int echopin)
{
  pinMode (trigPin,OUTPUT);
  pinMode (echopin ,INPUT);
}
