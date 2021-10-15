#include "SmartBath.h"

void oledDisplay(Adafruit_SSD1306 obj, String text)
{
  if (!obj.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
  Serial.println(F("SSD1306 allocation failed"));
  while (true);
  obj.clearDisplay();
  obj.setTextSize(1);
  obj.setTextColor(WHITE);
  obj.setCursor(0, 10);
  obj.print(text); 
  obj.display();
}

void lcdDisplay(LiquidCrystal_I2C obj, String text)
{
  obj.init();
  obj.backlight();
  obj.setCursor(1,0);
  obj.print(text);
}

void lcdTimer(LiquidCrystal_I2C obj){
  obj.init();
  obj.backlight();
  obj.setCursor(1,0);
  obj.print(hour());
  obj.print(":");
  if(minute() < 10)
  obj.print('0');
  obj.print(minute());
  obj.print(":");
  if(second() < 10)
  obj.print('0');
  obj.print(second());
  obj.println();
}

void oledTimer(Adafruit_SSD1306 obj){
  if (!obj.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
  Serial.println(F("SSD1306 allocation failed"));
  while (true);
  obj.clearDisplay();
  obj.setTextSize(1);
  obj.setTextColor(WHITE);
  obj.setCursor(0, 10);
  obj.print(hour());
  obj.print(":");
  if(minute() < 10)
  obj.print('0');
  obj.print(minute());
  obj.print(":");
  if(second() < 10)
  obj.print('0');
  obj.print(second());
  obj.println();
  obj.display();
}

void doUltraConfig (int trigPin ,int echoPin)
{
  pinMode (trigPin , OUTPUT);
  pinMode (echoPin , INPUT);
}

bool ultraResult(int trigPin,int echoPin,int destance)
{
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin,LOW);
 return (destance==(pulseIn(echoPin,HIGH)*0.017))? true : false;
}

void servoControlle(Servo obj, int pin, String mode)
{
  obj.attach(pin);

  if(mode == "open"){
      obj.write(180);
  }else if(mode == "close"){
    for(int j = 180; j > 1; j--){
      obj.write(j);
    }
  }
}

void sendSMS(SoftwareSerial obj, String text)
{
  obj.begin(9600);
  delay(100);
  obj.print("AT+CMGF=1\r");
  delay(100);
  obj.print("AT+CMGS=\"+201015178920\"\r");
  delay(500);
  obj.print(text);
  delay(500);
  obj.print((char)26);
  delay(500);
  obj.println();
  delay(500);
}

void pinConfig(String mode,int pins[])
{
  if(mode == "INPUT"){
    for(int i = 0 ; i < sizeof(pins) / sizeof(int) ; i++){
      pinMode(pins[i],INPUT);
    }
  }
  if(mode == "OUTPUT")
  {
    for(int j = 0 ; j < sizeof(pins) / sizeof(int) ; j++){
      pinMode(pins[j],OUTPUT);
    }
  }
}