
#define STEPS_PER_REV  2000 /* I actually dont know this value*/ /*Not when starting from mid 2000 goes over the edge*/
#define DIRECTION_PIN 12 /*A4988 Driver's direction pin */
#define STEP_PIN 13 /*A4988 Driver's step pin*/
 
void setup() {
  // put your setup code here, to run once:
    pinMode(DIRECTION_PIN,OUTPUT);
    pinMode(STEP_PIN,OUTPUT);
    
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(DIRECTION_PIN,LOW);
    for (int i = 0 ; i < STEPS_PER_REV ; i++){
          digitalWrite(STEP_PIN, HIGH);
          delayMicroseconds(1000);
          digitalWrite(STEP_PIN, LOW);
          delayMicroseconds(1000);
    }
    delayMicroseconds(5000);//give some delay before changing direction
    digitalWrite(DIRECTION_PIN,HIGH);
    for (int i = 0 ; i < STEPS_PER_REV ; i++){
          digitalWrite(STEP_PIN, HIGH);
          delayMicroseconds(1000);
          digitalWrite(STEP_PIN, LOW);
          delayMicroseconds(1000);
    }
}
