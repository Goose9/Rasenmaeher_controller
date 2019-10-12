#ifndef SENSOR_H
#define SENSOR_H

#include "Arduino.h"

class Sonar{
  private:
    int trig_pin;
    int echo_pin;
    int duration;
    int distance;
    int sense_reach;

  public:
    Sonar(int trig_pin, int echo_pin, int sense_reach);
    void senseObstacles();
    
    int obstacleFound();

    void setDuration(int duration){this->duration = duration;}
    int getDuration(){return this->duration;}

    void setDistance(int distance){this->distance = distance;}
    int getDistance(){return distance;}

    void setSenseReach(int sense_reach){this->sense_reach = sense_reach;}
    int getSenseReach(){return this->sense_reach;}
};

#endif
