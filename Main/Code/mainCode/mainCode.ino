#include <SmartBath.h>

LiquidCrystal_I2C lcd(0x24,16,2);
Adafruit_SSD1306 oled(128, 64, &Wire, -1);
Servo door;
Servo toilet;
SoftwareSerial sim(TX0,RX0);

boolean coinCheck = true;
boolean water = false;
boolean soap = false;

boolean pirCheck = false;
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
   
  //Check PIR Sensor
  if(digitalRead(PIR) == 0 && pirCheck == false){
      lcdDisplay(lcd,"Enter Coin");
      delay(20);
      //Check coin Machine
      if(digitalRead(COIN_MACHINE) == 1 && coinCheck == true){
        pirCheck = true;
        //Open door
        servoControlle(door,DOOR,"open");
        delay(100);
        lcdDisplay(lcd,"Busy");
        delay(20);
        //Turn on the interior light
        digitalWrite(INTERIOR_LIGHT,HIGH);
        delay(20);
        if(ultraResult(TRIG3,ECHO3,20)){
          //Timer Will Start
          lcdTimer(lcd);
          oledTimer(oled);
          //Close door
          servoControlle(door,DOOR,"close");
        }else{
          delay(5000);
          //Turn on buzzer
          digitalWrite(BUZZER,HIGH);
          delay(5000);
          servoControlle(door,DOOR,"close");
          }
       //Start Check MQ Sensor
        if (digitalRead(GAS) == 1){
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
      
      //Start water tap 
        if(ultraResult(TRIG2,ECHO2,5)&& water == false){
          //open tap
          digitalWrite(TAP,HIGH);
          water = true;
          }else if(!ultraResult(TRIG2,ECHO2,5)&& water == true){
            digitalWrite(TAP,LOW);
            water = false;
            }
      //end water tap

      //Start soap
        if(ultraResult(TRIG1,ECHO1,5)&& soap == false){
          //open tap
          digitalWrite(TAP,HIGH);
          soap = true;
          }else if(!ultraResult(TRIG1,ECHO1,5)&& soap == true){
            digitalWrite(TAP,LOW);
            soap = false;
            }
      //end soap
          if(ultraResult(TRIG3,ECHO3,20)){
          //Close door
          servoControlle(door,DOOR,"open");
          delay(9000);
          servoControlle(door,DOOR,"close");
          pirCheck = false;
        }
//Start Cleaning
    if(digitalRead(PIR) == 0 && pirCheck == false){
        servoControlle(toilet,SERVO_MOTOR_TOILET,"open");
        delay(50);
        servoControlle(toilet,SERVO_MOTOR_TOILET,"close");
        delay(50);
        digitalWrite(PERFUMED,HIGH);
        delay(50);
        digitalWrite(PERFUMED,LOW);
        delay(50);
        digitalWrite(PUMPER_ANTISEPTIC,HIGH);
        delay(50);
        digitalWrite(PUMPER_ANTISEPTIC,LOW);
        delay(50);
      }
//End Cleaning 
      }else if (digitalRead(COIN_MACHINE) == 0 && coinCheck == false){
        lcdDisplay(lcd,"Valid Coin!?");
        }
    }else{
    lcdDisplay(lcd,"Busy");
  }
}
