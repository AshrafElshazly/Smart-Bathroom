#include <SmartBath.h>

//Objects
LiquidCrystal_I2C lcd(0x24,16,2);
Adafruit_SSD1306 oled(128, 64, &Wire, -1);
Servo door;
SoftwareSerial sim(2, 3); //(RX,TX)

void setup()
{
  for()
}
 
void loop()
{
  
}

void outputPinConfig(int pin)
{
  pinMode(pin,OUTPUT);
}

void inputPinConfig(int pin)
{
  pinMode(pin,INPUT);
}
