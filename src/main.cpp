#include "QuarkTS.h"
#include <Arduino.h>
#define TIMER_TICK 0.001 // 1ms tick
void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  qOS_Setup((qGetTickFcn_t)millis, TIMER_TICK, (qTaskFcn_t)loop);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}