#include "Arduino.h"
#include "Sensor.h";

Sonar::Sonar(int trig_pin, int echo_pin, int sense_reach)
{
  this->trig_pin = trig_pin;
  this->echo_pin = echo_pin;
  setDuration(0);
  setDistance(0);
  setSenseReach(sense_reach);

  pinMode(trig_pin    , OUTPUT); // Sets the trigPin as an Output
  pinMode(echo_pin    , INPUT); // Sets the echoPin as an Input
}

void Sonar::senseObstacles() {      
  // Clears the trig_pin
  digitalWrite(this->trig_pin, LOW);
  delayMicroseconds(2);
  
  // Sets the trig_pin on HIGH state for 10 micro seconds
  digitalWrite(this->trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(this->trig_pin, LOW);
  
  // Reads the echo_pin, returns the sound wave travel time in microseconds
  int duration = pulseIn(this->echo_pin, HIGH);
  
  // Calculating the distance
  setDistance(duration*0.034/2);
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(duration);
}

int Sonar::obstacleFound()
{
  int ret = -1;
  if(getDistance() < getSenseReach())
  {
    ret = HIGH;
  }
  else
  {
    ret = LOW;
  }

  return ret;
}
