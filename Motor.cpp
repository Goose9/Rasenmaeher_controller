#include "Arduino.h"
#include "Motor.h";

Motor::Motor(int dir_pin, int step_pin,int spin_dir, int timer)
{
  this->dir_pin = dir_pin;
  this->step_pin = step_pin;
  setSpinDir(spin_dir);
  setTimer(timer);

  pinMode(dir_pin, OUTPUT);
  pinMode(step_pin, OUTPUT);
}

void Motor::moveStraight()
{
  digitalWrite(this->dir_pin, getSpinDir()); // Enables the motor to move in a particular direction

  digitalWrite(this->step_pin,HIGH); 
  delayMicroseconds(getTimer()); 
  digitalWrite(this->step_pin,LOW); 
  delayMicroseconds(getTimer()); 
}
