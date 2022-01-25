#include "QuarkTS.h"
#include <Arduino.h>
#define TIMER_TICK 0.001 // 1ms tick
void setup() {
  Serial5.begin(230400);
  pinMode(PA10,OUTPUT);
  pinMode(PC8,OUTPUT);
  Serial5.println("Hello PlatformIO, Serial5");
  qOS_Setup((qGetTickFcn_t)millis, TIMER_TICK, (qTaskFcn_t)loop);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PA10,HIGH);
  digitalWrite(PC8,HIGH);
  delay(500);
  digitalWrite(PA10,LOW);
  digitalWrite(PC8,LOW);
  delay(500);
}