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

int doUltraConfig (int trigPin ,int echopin)
{
  pinMode (trigPin,OUTPUT);
  pinMode (echopin ,INPUT);
}

bool ultraResult(int trigPin,int echoPin,int destance)
{
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin,LOW);
 return (destance==(pulseIn(echoPin,HIGH)*0.017))? true : false;
}

void servoAngle(Servo obj, int pin, int angle, String mode)
{
  obj.attach(pin);

  if(mode == "open"){
    for(int i = 0; i <= angle;i++){
      obj.write(i);
    }
  }else if(mode == "close"){
    for(int j = angle; j == 0; j--){
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
