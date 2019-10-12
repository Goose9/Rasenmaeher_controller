#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"

class Motor{
  private:
    int dir_pin;
    int step_pin;
    int spin_dir;
    int timer;

  public:
    Motor(int dir_pin, int step_pin,int spin_dir, int timer);
    void moveStraight();
    void setSpinDir(int spin_dir){this->spin_dir = spin_dir;}
    int getSpinDir(){return this->spin_dir;}
    void setTimer(int timer){this->timer = timer;}
    int getTimer(){return this->timer;}
};

#endif
