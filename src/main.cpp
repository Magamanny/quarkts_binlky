#include "QuarkTS.h"
#include <Arduino.h>
#define TIMER_TICK 0.001 // 1ms tick

// task handler
qTask_t task1, loopTask;
//
void task1_Callback(qEvent_t e)
{
  Serial5.println("I am Back.");
}
void setup() {
  Serial5.begin(230400);
  pinMode(PA10,OUTPUT);
  pinMode(PC8,OUTPUT);
  digitalWrite(PA10,HIGH);
  Serial5.println("Hello PlatformIO, Serial5");
  qOS_Setup((qGetTickFcn_t)millis, TIMER_TICK, NULL);
  // add task
  qOS_Add_Task(&task1,task1_Callback,qLowest_Priority,0.1,qPeriodic,qEnabled,NULL);
  qOS_Add_Task(&loopTask,(qTaskFcn_t)loop,qLowest_Priority,0.5,qPeriodic,qEnabled,NULL);
  // put your setup code here, to run once:
  qOS_Run();
}
// idle task
void loop() {
  // put your main code here, to run repeatedly:
  // this does not run
  // arduino way of toggling
  digitalWrite(PA10,!digitalRead(PA10));
  digitalWrite(PC8,!digitalRead(PC8));
}