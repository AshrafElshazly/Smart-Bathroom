#ifndef SMARTBATH_H
#define SMARTBATH_H


#include <Arduino.h>
#include <Wire.h>
#include <TimeLib.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>
#include <SoftwareSerial.h>

#define INTERIOR_LIGHT 26
#define EXTERNAL_LIGHT 27
#define PUMPER_ANTISEPTIC 34
#define AIR_HOOD 35
#define PERFUMED 36
#define FLOOR 43
#define TRIG3 24
#define ECHO3 25
#define DOOR 23
#define COIN_MACHINE 22
#define RX0 0
#define TX0 1
#define BUZZER 44
#define PIR 38
#define FLAME 39
#define EXTINGUISHING_FIRES 40
#define GAS A0
#define TAP 30
#define LIQUID 33
#define SERVO_MOTOR_TOILET 37
#define TX1 18
#define RX1 19
#define TRIG1 31
#define ECHO1 32
#define TRIG2 28
#define ECHO2 29

const int inputPins[]  = {COIN_MACHINE,PIR,FLAME,GAS}; 
const int outputPins[] = {INTERIOR_LIGHT,EXTERNAL_LIGHT,PUMPER_ANTISEPTIC,AIR_HOOD,PERFUMED,FLOOR,DOOR,BUZZER,EXTINGUISHING_FIRES,TAP,LIQUID,SERVO_MOTOR_TOILET};

void oledDisplay(Adafruit_SSD1306 obj, String text);
void lcdDisplay(LiquidCrystal_I2C obj, String text);
void oledTimer(Adafruit_SSD1306 obj);
void lcdTimer(LiquidCrystal_I2C obj);
void doUltraConfig (int trigPin ,int echoPin);
bool ultraResult(int trigPin,int echoPin,int destance);
void servoControlle(Servo obj, int pin, String mode);
void sendSMS(SoftwareSerial obj, String text);
void pinConfig(String mode,int pins[]);

#endif
