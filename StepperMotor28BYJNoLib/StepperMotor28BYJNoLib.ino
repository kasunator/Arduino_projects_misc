
/*
 * this motor 28BYJ-48 seems to have 2048 steps per revolution 
 * minimum delay between steps is 2ms 
 * 
 */

#define STEPPER_PIN_1 13
#define STEPPER_PIN_2 12
#define STEPPER_PIN_3 11
#define STEPPER_PIN_4 10

#define ONE_REV 2048

int step_number = 0;
int total_steps= 0;
int rot_direction=0;// o measn stop, 1 means clrockwise, 2 means anti 
/*
 *   constructor for four-pin version
 *   Sets which wires should control the motor
 */

void setup() {
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);
  rot_direction = 1;//
}

void loop() {

  OneStep();
  delay(2);
 
}
void SetDirection(int p_direction){
  if(p_direction != rot_direction){
    rot_direction= p_direction;
  }
}
void OneStep(){
  
    if(rot_direction == 1){
          switch(step_number){
              case 0:
              digitalWrite(STEPPER_PIN_1, HIGH);
              digitalWrite(STEPPER_PIN_2, LOW);
              digitalWrite(STEPPER_PIN_3, LOW);
              digitalWrite(STEPPER_PIN_4, LOW);
              break;
              case 1:
              digitalWrite(STEPPER_PIN_1, LOW);
              digitalWrite(STEPPER_PIN_2, HIGH);
              digitalWrite(STEPPER_PIN_3, LOW);
              digitalWrite(STEPPER_PIN_4, LOW);
              break;
              case 2:
              digitalWrite(STEPPER_PIN_1, LOW);
              digitalWrite(STEPPER_PIN_2, LOW);
              digitalWrite(STEPPER_PIN_3, HIGH);
              digitalWrite(STEPPER_PIN_4, LOW);
              break;
              case 3:
              digitalWrite(STEPPER_PIN_1, LOW);
              digitalWrite(STEPPER_PIN_2, LOW);
              digitalWrite(STEPPER_PIN_3, LOW);
              digitalWrite(STEPPER_PIN_4, HIGH);
              break;
        } 
    }else if(rot_direction ==2){
        switch(step_number){
            case 0:
            digitalWrite(STEPPER_PIN_1, LOW);
            digitalWrite(STEPPER_PIN_2, LOW);
            digitalWrite(STEPPER_PIN_3, LOW);
            digitalWrite(STEPPER_PIN_4, HIGH);
            break;
            case 1:
            digitalWrite(STEPPER_PIN_1, LOW);
            digitalWrite(STEPPER_PIN_2, LOW);
            digitalWrite(STEPPER_PIN_3, HIGH);
            digitalWrite(STEPPER_PIN_4, LOW);
            break;
            case 2:
            digitalWrite(STEPPER_PIN_1, LOW);
            digitalWrite(STEPPER_PIN_2, HIGH);
            digitalWrite(STEPPER_PIN_3, LOW);
            digitalWrite(STEPPER_PIN_4, LOW);
            break;
            case 3:
            digitalWrite(STEPPER_PIN_1, HIGH);
            digitalWrite(STEPPER_PIN_2, LOW);
            digitalWrite(STEPPER_PIN_3, LOW);
            digitalWrite(STEPPER_PIN_4, LOW);   
       } 
    }else{
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
    }
    step_number++;
    if(step_number > 3){
    step_number = 0;
    }
    
    total_steps++;
    if(total_steps == ONE_REV)
    {
      total_steps=0;
      if(rot_direction == 1)
      {
        rot_direction =2;
      }else if( rot_direction ==2){
        rot_direction =1;
      }  
    }
    
}
