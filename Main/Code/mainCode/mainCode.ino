#include <SmartBath.h>

LiquidCrystal_I2C lcd(0x24,16,2);
Adafruit_SSD1306 oled(128, 64, &Wire, -1);
Servo door;
SoftwareSerial sim(TX0,RX0);

boolean flag      = true;
boolean lcdFlag   = false;
boolean oldFlag   = false;
boolean flameFlag = false;

void setup() {
  Serial.begin(9600);
  pinConfig("OUTPUT",outputPins);
  pinConfig("INPUT",inputPins);
  doUltraConfig(TRIG3,ECHO3);
  doUltraConfig(TRIG2,ECHO2);
  doUltraConfig(TRIG1,ECHO1);
}

void loop() {

  //Start Check Flam Sensor
  if(digitalRead(FLAME) == 1){
    //Turn on extinguishing fire pump
    digitalWrite(EXTINGUISHING_FIRES,LOW);
    //Turn on buzzer
    tone(BUZZER, 1000, 200);
    //Send an emergency message 
    sendSMS(sim,"There is a fire ");
    lcdDisplay(lcd,"Fire inside");
    }
   //End Check Flam Sensor

  //Start Check MQ Sensor
  if (digitalRead(FLAME) == 0){
    //Open Door
    servoControlle(door,DOOR,"open");
    //Open Air hood
    digitalWrite(AIR_HOOD,HIGH);
    //Turn on buzzer
    tone(BUZZER, 1000, 200);
    //Send an emergency message 
    sendSMS(sim,"There is a Somke ");
    lcdDisplay(lcd,"Somke inside");
    }
   //End Check MQ Sensor
   
  //Check PIR Sensor
  if(digitalRead(PIR) == 0){
      lcdDisplay(lcd,"Empty,Enter Coin");
      delay(20);
      //Check coin Machine
      if(digitalRead(COIN_MACHINE) == 1 && flag == true){
        //Open door
        servoControlle(door,DOOR,"open");
        delay(100);
        lcdDisplay(lcd,"Busy");
        delay(20);
        //Turn on the interior light
        digitalWrite(INTERIOR_LIGHT,HIGH);
        delay(20);
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
      }else if (digitalRead(COIN_MACHINE) == 1 && flag == false){
        lcdDisplay(lcd,"Enter Coin");
        }
    }else{
    lcdDisplay(lcd,"Busy");
  }
}
