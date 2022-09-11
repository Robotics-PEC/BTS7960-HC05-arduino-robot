
#define RPWM_1 3                                                                  // pin for RPWM
#define R_EN_1 4                                                                  // pin for R_EN

#define LPWM_1 6                                                                  // pin for LPWM
#define L_EN_1 7                                                                  // pin for L_EN

// pins for motor 2
#define RPWM_2 9                                                                  // pin for RPWM
#define R_EN_2 10                                                                 // pin for R_EN

#define LPWM_2 11                                                                 // pin for LPWM
#define L_EN_2 A0                                                                 // pin for L_EN

#define CW 1                                                                       // don't change
#define CCW 0                                                                      // don't change

#define STOP_HARD_MODE 1
#define STOP_SOFT_MODE 0


#define rx 0
#define tx 1


char t;
bool stop_mode = STOP_SOFT_MODE;
unsigned long time_since_last_command = 0;

#include <SoftwareSerial.h>
SoftwareSerial HC05(rx, tx);

byte speed = 255;

void setup(){
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(RPWM_1, OUTPUT);
  pinMode(R_EN_1, OUTPUT);
  pinMode(LPWM_1, OUTPUT);
  pinMode(L_EN_1, OUTPUT);
  pinMode(RPWM_2, OUTPUT);
  pinMode(R_EN_2, OUTPUT);
  pinMode(LPWM_2, OUTPUT);
  pinMode(L_EN_2, OUTPUT);



  digitalWrite(13, HIGH);
  digitalWrite(2, HIGH);

  HC05.begin(9600);
}

void forward(){
  digitalWrite(R_EN_1, HIGH);
  digitalWrite(R_EN_2, HIGH);
  digitalWrite(L_EN_1, HIGH);
  digitalWrite(L_EN_2, HIGH);
  digitalWrite(LPWM_1, LOW);
  digitalWrite(LPWM_2, LOW);
  analogWrite(RPWM_1, speed);
  analogWrite(RPWM_2, speed);
}

void back(){
  digitalWrite(R_EN_1, HIGH);
  digitalWrite(R_EN_2, HIGH);
  digitalWrite(L_EN_1, HIGH);
  digitalWrite(L_EN_2, HIGH);
  digitalWrite(RPWM_1, LOW);
  digitalWrite(RPWM_2, LOW);
  analogWrite(LPWM_1, speed);
  analogWrite(LPWM_2, speed);
}

void left(){
  digitalWrite(R_EN_1, HIGH);
  digitalWrite(R_EN_2, HIGH);
  digitalWrite(L_EN_1, HIGH);
  digitalWrite(L_EN_2, HIGH);
  digitalWrite(LPWM_2, LOW);
  digitalWrite(RPWM_1, LOW);
  analogWrite(LPWM_1, speed/2);
  analogWrite(RPWM_2, speed/2);
}

void right(){
  digitalWrite(R_EN_1, HIGH);
  digitalWrite(R_EN_2, HIGH);
  digitalWrite(L_EN_1, HIGH);
  digitalWrite(L_EN_2, HIGH);
  digitalWrite(LPWM_1, LOW);
  digitalWrite(RPWM_2, LOW);
  analogWrite(RPWM_1, speed/2);
  analogWrite(LPWM_2, speed/2);
}

void forwardleft(){
  digitalWrite(R_EN_1, LOW);
  digitalWrite(R_EN_2, HIGH);
  digitalWrite(L_EN_1, LOW);
  digitalWrite(L_EN_2, HIGH);
  digitalWrite(LPWM_1, LOW);
  digitalWrite(RPWM_1, LOW);
  digitalWrite(LPWM_2, LOW);
  analogWrite(RPWM_2, speed);
}

void forwardright(){
  digitalWrite(R_EN_1, HIGH);
  digitalWrite(R_EN_2, LOW);
  digitalWrite(L_EN_1, HIGH);
  digitalWrite(L_EN_2, LOW);
  digitalWrite(LPWM_2, LOW);
  digitalWrite(RPWM_2, LOW);
  digitalWrite(LPWM_1, LOW);
  analogWrite(RPWM_1, speed);
}

void backleft(){
  digitalWrite(R_EN_1, LOW);
  digitalWrite(R_EN_2, HIGH);
  digitalWrite(L_EN_1, LOW);
  digitalWrite(L_EN_2, HIGH);
  digitalWrite(LPWM_1, LOW);
  digitalWrite(RPWM_1, LOW);
  digitalWrite(RPWM_2, LOW);
  analogWrite(LPWM_2, speed);
}

void backright(){
  digitalWrite(R_EN_1, HIGH);
  digitalWrite(R_EN_2, LOW);
  digitalWrite(L_EN_1, HIGH);
  digitalWrite(L_EN_2, LOW);
  digitalWrite(LPWM_2, LOW);
  digitalWrite(RPWM_2, LOW);
  digitalWrite(RPWM_1, LOW);
  analogWrite(LPWM_1, speed);
}

void stop(){
  if(stop_mode == STOP_SOFT_MODE){
  digitalWrite(L_EN_1, LOW);
  digitalWrite(R_EN_1, LOW);
  digitalWrite(R_EN_2, LOW);
  digitalWrite(L_EN_2, LOW);
  }else
  {
    digitalWrite(L_EN_1, HIGH);
    digitalWrite(R_EN_1, HIGH);
    digitalWrite(R_EN_2, HIGH);
    digitalWrite(L_EN_2, HIGH);
  }
  digitalWrite(LPWM_1, LOW);
  digitalWrite(LPWM_2, LOW);
  digitalWrite(RPWM_1, LOW);
  digitalWrite(RPWM_2, LOW);
}

void loop()
{
   
  if (HC05.available())
  { time_since_last_command = millis();
    t = HC05.read();

    switch (t)
    {
      case 'F':
        forward();
        break;

      case 'B':
        back();
        break;

      case 'L':
        left();
        break;

      case 'R':
        right();
        break;
        
      case 'G':
        forwardleft();
        break;

      case 'I':
        forwardright();
        break;

      case 'H':
        backleft();
        break;

      case 'J':
        backright();
        break;

      case 'S':
        stop();
        break;
      
      case 'X':
        stop_mode = STOP_HARD_MODE;
        break;

      case 'x':
        stop_mode = STOP_SOFT_MODE;
        break;

      case '0':
        speed = (0.0 / 10) * 255;
        break;
      case '1':
        speed = (1.0 / 10) * 255;
        break;
      case '2':
        speed = (2.0 / 10) * 255;
        break;
      case '3':
        speed = (3.0 / 10) * 255;
        break;
      case '4':
        speed = (4.0 / 10) * 255;
        break;
      case '5':
        speed = (5.0 / 10) * 255;
        break;
      case '6':
        speed = (6.0 / 10) * 255;
        break;
      case '7':
        speed = (7.0 / 10) * 255;
        break;
      case '8':
        speed = (8.0 / 10) * 255;
        break;
      case '9':
        speed = (9.0 / 10) * 255;
        break;
      case 'q':
        speed = (10.0 / 10) * 255;
        break;
    }
  }

  if(millis() - time_since_last_command > 500)
  {
    // if no msg recived in last 200 ms then stop motors
    stop();
  }

}
