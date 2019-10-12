#include "Motor.h";
#include "Sensor.h";

const int enable_pin = 8;

const int right_dir_pin = 5;
const int right_step_pin = 2;

const int left_dir_pin = 6;
const int left_step_pin = 3;

const int sonar_trig_pin = 12;
const int sonar_echo_pin = 13;
const int sonar_sense_reach = 20;

const int rotor_pin = -1;

int emergency_stop;
Motor right_wheel = Motor(right_dir_pin, right_step_pin, LOW, 750);      //(dir_pin, step_pin, spin_dir, timer)
Motor left_wheel = Motor(left_dir_pin, left_step_pin, HIGH, 750);        //(dir_pin, step_pin, spin_dir, timer)
Sonar sonar = Sonar(sonar_trig_pin, sonar_echo_pin, sonar_sense_reach);   //(trig_pin, echo_pin, sense_reach)

  
void setup() 
{
  // put your setup code here, to run once:  
  pinMode(enable_pin  , OUTPUT);  
  pinMode(rotor_pin, OUTPUT););
  Serial.begin(9600); // Starts the serial communication
  emergency_stop = LOW;
  
}


void loop() 
{
  if(!emergency_stop)
  {
    emergency_stop = Move();
    emergency_stop = setRotor();

    emergency_stop = senseSurrounding();
  }
}

void emergencyStop()
{
  emergency_stop = HIGH;
}

void Move()
{
  right_wheel.moveStraight();
  left_wheel.moveStraight();
}

void setRotor()
{
  
}

int senseSurrounding()
{
  int obstacle_found;
  sonar.senseObstacles();
  if(-1 == (obstacle_found = sonar.obstacleFound()))
    emergencyStop();
  right_wheel.setSpinDir(obstacle_found);

  return obstacle_found;
}
