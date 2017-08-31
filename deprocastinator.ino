/*
This is a very simple sketch to build the DEPROCASTINATOR. This
dvice will help you to concentrate in getting things done by
reminding you every time to keep you focused in the task at hand.

A relay should be hooked up to LED_BUILTIN (usually pin 13).

Alfredo Rius
alfredo.rius@gmail.com
*/


#include "TimerOne.h"

#define TIMEOUT 30 // minutes
#define WARNING 5  // minutes

long timeout = TIMEOUT*60;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
  Timer1.initialize(1000000);         // initialize timer1, and set a 1/2 second period
  Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
}

void callback()
{
  if(!timeout)
    digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN)^1);
  else{
    timeout--;
    if(timeout<WARNING*60){
      digitalWrite(LED_BUILTIN,HIGH);
    }
  }
}

void loop()
{

}

