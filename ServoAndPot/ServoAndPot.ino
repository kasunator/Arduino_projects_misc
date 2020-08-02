
/* 
 *  we read a potentionmetr and adjust the servo postion accordingly 
 */
#include<Servo.h>
int pot_pin = A0;
int servo_pin = 9; 
Servo myServo;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);           // set up Serial library at 9600 bps
 myServo.attach(servo_pin);
}
/*
temperatur in celsius  = ADC_raw x 0.48875
*/
void loop() {
  // put your main code here, to run repeatedly:
 int ADC_raw = analogRead(pot_pin);
 /* we are going to map the pot range from 0 to 1023 to 0 to 180 servo andgle*/ 
 int servo_angle = map(ADC_raw, 0, 1023, 0, 180);
 Serial.print("servo angle:");
 Serial.println(servo_angle);
 myServo.write(servo_angle);
 delay(15);
}
