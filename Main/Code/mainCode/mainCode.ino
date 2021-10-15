#include <SmartBath.h>

LiquidCrystal_I2C lcd(0x24,16,2);
Adafruit_SSD1306 oled(128, 64, &Wire, -1);
Servo door;
SoftwareSerial sim(TX0,RX0);

void setup() {
  pinMode(inputPins,INPUT);
  pinMode(outputPins,OUTPUT);
}

void loop() {
  //Check Flam Sensor
  if(digitalRead(FLAME) == 1){
    //Turn on extinguishing fire pump
    digitalWrite(EXTINGUISHING_FIRES,HIGH);
    //Turn on buzzer
    digitalWrite(BUZZER,HIGH);
    //Send an emergency message 
    sendSMS(sim,"There is a fire ");
    }
  //Check PIR Sensor
  if(digitalRead(PIR) == 0){
      lcdDisplay(lcd,"Empty,Enter Coin");
      //Check coin Machine
      if(digitalRead(COIN_MACHINE) == 1){
        //Open door
        servoControlle(door,DOOR,"open");
        lcdDisplay(lcd,"Busy");
        //Turn on the interior light
        digitalWrite(INTERIOR_LIGHT,HIGH);
        if(ultraResult(TRIG3,ECHO3,20)){
          //Close door
          servoControlle(door,DOOR,"close");
        }else{
          delay(5000);
          //Turn on buzzer
          digitalWrite(BUZZER,HIGH);
          delay(5000);
          servoControlle(door,DOOR,"close");
          }
      }else{
        lcdDisplay(lcd,"Enter Valid Coin");
        }
  }else{
    lcdDisplay(lcd,"Busy");
  }  
}
