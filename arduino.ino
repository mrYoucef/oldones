
#include "Arduino.h"

#define pin1 8  // pins configuration
#define pin2 9
#define pin3 10
#define pin4 11
#define stepper_speed 6 // numbers of turns per minute 
#define steps_per_turn 200 // steps number in one turn

//to calculate the wide of the pulse in micro seconds
long step_delay = 60L * 1000L * 1000L / steps_per_turn / stepper_speed ;
int actual_step = 0 ;
int step_number = actual_step ;



void setup() {

    // setup the pins 
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);

}

void loop() {
turn(260); 
turn(50);
}




void turn(int angle) // function used to trun the stepper
{ int next_step = angle * steps_per_turn /360;
  int steps_to_move = next_step-actual_step ;
  int steps_left = abs(steps_to_move);  // how many steps to take
  int last_step_time = micros();




  while (steps_left > 0)
  {
    unsigned long now = micros();
    // move only if the appropriate delay has passed
    if (now -last_step_time >= step_delay)
    {
      // get the timeStamp of when you stepped:
      last_step_time = now;
      // increment or decrement the step number,
      // depending on direction:
      if (steps_to_move > 0)
        step_number++;
      else
        step_number--;
     
      // decrement the steps left:
      steps_left--;
   
    switch ( step_number % 4) {
      case 0:  
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
      break;
      case 1: 
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
      break;
      case 2: 
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
      break;
      case 3:
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
      break;
    }
        
    }
  }
  actual_step = next_step ;
}

