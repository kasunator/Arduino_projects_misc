
#include <Stepper.h> 

const int stepsPerRevolution = 2038;
const int motor_pin_1 = 13;
const int motor_pin_2 = 12;
const int motor_pin_3 = 11;
const int motor_pin_4 = 10;
/*
 *   constructor for four-pin version
 *   Sets which wires should control the motor.
 
  Stepper::Stepper(int number_of_steps, int motor_pin_1, int motor_pin_2,
                                      int motor_pin_3, int motor_pin_4)
                                                                       */
Stepper myStepper = Stepper(stepsPerRevolution, motor_pin_1, motor_pin_2, motor_pin_3, motor_pin_4);

void setup() {
  // put your setup code here, to run once:
  myStepper.setSpeed(1);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Rotate CW slowly
  //myStepper.step(stepsPerRevolution);
 // delay(1000);
  
  // Rotate CCW quickly
 // myStepper.setSpeed(700);
 // myStepper.step(-stepsPerRevolution);
 // delay(1000);

  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(4000);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-2038);
  delay(4000);

 
}
