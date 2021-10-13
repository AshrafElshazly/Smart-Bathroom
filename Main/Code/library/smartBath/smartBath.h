#ifndef SMARTBATH_H
#define SMARTBATH_H


#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

void oledDisplay(Adafruit_SSD1306 obj, String text);
void lcdDisplay(LiquidCrystal_I2C obj, String text);
bool ultraResult(int trigPin,int echoPin,int destance);
int doUltraConfig (int trigPin ,int echopin);
void servoAngle(Servo obj, int pin, int angle, String mode);

#endif
