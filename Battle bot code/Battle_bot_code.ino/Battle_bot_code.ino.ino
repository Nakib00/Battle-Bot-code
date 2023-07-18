#include <Servo.h>

Servo esc; // Create a servo object

// Set pin number to the variable
int L_EN_FOR_ONE = 3;
int R_EN_FOR_ONE = 4;
int L_PWM_FOR_ONE = 5;
int R_PWM_FOR_ONE = 6;
int L_EN_FOR_TWO = 8;
int R_EN_FOR_TWO = 12;
int L_PWM_FOR_TWO = 10;
int R_PWM_FOR_TWO = 11;
char incomingByte;   // for incoming serial data
int speed_min = 155; // the minimum "speed" the motors will turn - take it lower and motors don't turn
int speed_max = 180; //

int speed_left = speed_max; // set both motors to maximum speed
int speed_right = speed_max;

void left();
void right();
void forward();
void backward();
void forward_left();
void forward_right();
void back_left();
void back_right();
void setup()
{
  //Define PinMode
  Serial.begin(9600);
  esc.attach(9); // Attach the ESC signal pin to digital pin 9
  pinMode(L_EN_FOR_ONE, OUTPUT);
  pinMode(R_EN_FOR_ONE, OUTPUT);
  pinMode(L_PWM_FOR_ONE, OUTPUT);
  pinMode(R_PWM_FOR_ONE, OUTPUT);
  pinMode(L_EN_FOR_TWO, OUTPUT);
  pinMode(R_EN_FOR_TWO, OUTPUT);
  pinMode(L_PWM_FOR_TWO, OUTPUT);
  pinMode(R_PWM_FOR_TWO, OUTPUT);

  digitalWrite(L_EN_FOR_ONE, HIGH);
  digitalWrite(R_EN_FOR_ONE, HIGH);
  digitalWrite(L_EN_FOR_TWO, HIGH);
  digitalWrite(R_EN_FOR_TWO, HIGH);
}

void loop()
{

  if (Serial.available() > 0)
  {
    incomingByte = Serial.read();
  }
  switch (incomingByte)
  {
  case 'W':
  {
    esc.writeMicroseconds(0);
    stopo();
    // Serial.println("Stop\n");
    incomingByte = '*';
  }
  break;

  case 'R':

  {
    left();

    // Serial.println("Forward\n");
    incomingByte = '*';
  }
  break;

  case 'L':

  {
    right();
    // Serial.println("Backward\n");
    incomingByte = '*';
  }
  break;

  case 'B':
    // turn right
    {
      forward();
      // Serial.println("Rotate Right\n");
      incomingByte = '*';
    }
    break;
  case 'F':
  {
    backward();
    // Serial.println("Rotate Left\n");
    incomingByte = '*';
  }
  break;
  case '1':

  {
    esc.writeMicroseconds(1000);
    // Serial.println("Speed 1\n");
    incomingByte = '*';
  }
  break;
  case '2':
  {
    esc.writeMicroseconds(1100);
    // Serial.println("Speed 2 \n");
    incomingByte = '*';
  }
  break;
  case '3':
  {
    esc.writeMicroseconds(1200);
    // Serial.println("Speed 3 \n");
    incomingByte = '*';
  }
  break;
  case '4':
  {
    esc.writeMicroseconds(1300);
    // Serial.println("Speed 4 \n");
    incomingByte = '*';
  }
  break;
  case '5':
  {
    esc.writeMicroseconds(1400);
    // Serial.println("Speed 5 \n");
    incomingByte = '*';
  }
  break;
  case '6':
  {
    esc.writeMicroseconds(1500);
    // Serial.println("Speed 6 \n");
    incomingByte = '*';
  }
  break;
  case '7':
  {
    esc.writeMicroseconds(1600);
    // Serial.println("Speed 7 \n");
    incomingByte = '*';
  }
  break;
  case '8':
  {
    esc.writeMicroseconds(1700);
    // Serial.println("Speed 8 \n");
    incomingByte = '*';
  }
  break;
  case '9':
  {
    esc.writeMicroseconds(1800);
    // Serial.println("Speed 9 \n");
    incomingByte = '*';
  }
  break;
  case 'q':
  {
    speed_left = 255;
    speed_right = 255;
    Serial.println("Speed full \n");
    incomingByte = '*';
  }
  break;
  case 'H':
  {
    back_left();
    Serial.println("Speed full \n");
    incomingByte = '*';
  }
  break;
  case 'I':
  {
    forward_right();
    Serial.println("Speed full \n");
    incomingByte = '*';
  }
  break;
  case 'G':
  {
    back_left();
    Serial.println("Speed full \n");
    incomingByte = '*';
  }
  break;
  case 'J':
  {
    back_right();
    Serial.println("Speed full \n");
    incomingByte = '*';
  }
  break;
  }
}

//  All Function

// Forward
void forward()
{

  analogWrite(R_PWM_FOR_ONE, speed_max);
  analogWrite(L_PWM_FOR_ONE, 0);
  analogWrite(R_PWM_FOR_TWO, 0);
  analogWrite(L_PWM_FOR_TWO, speed_max);
};

// Backward
void backward()
{
  analogWrite(R_PWM_FOR_ONE, 0);
  analogWrite(L_PWM_FOR_ONE, speed_max);
  analogWrite(R_PWM_FOR_TWO, speed_max);
  analogWrite(L_PWM_FOR_TWO, 0);
};

// Right
void right()
{
  analogWrite(R_PWM_FOR_ONE, 0);
  analogWrite(L_PWM_FOR_ONE, speed_max);
  analogWrite(R_PWM_FOR_TWO, 0);
  analogWrite(L_PWM_FOR_TWO, speed_max);
};

// Left
void left()
{
  analogWrite(R_PWM_FOR_ONE, speed_max);
  analogWrite(L_PWM_FOR_ONE, 0);
  analogWrite(R_PWM_FOR_TWO, speed_max);
  analogWrite(L_PWM_FOR_TWO, 0);
};

// Stop
void stopo()
{

  analogWrite(R_PWM_FOR_ONE, 0);
  analogWrite(L_PWM_FOR_ONE, 0);
  analogWrite(R_PWM_FOR_TWO, 0);
  analogWrite(L_PWM_FOR_TWO, 0);
};

// Forward  left
void forward_left()
{
  analogWrite(R_PWM_FOR_ONE, 0);
  analogWrite(L_PWM_FOR_ONE, 0);
  analogWrite(R_PWM_FOR_TWO, speed_max);
  analogWrite(L_PWM_FOR_TWO, 0);
};

// Forward right
void forward_right()
{
  analogWrite(R_PWM_FOR_ONE, 0);
  analogWrite(L_PWM_FOR_ONE, speed_max);
  analogWrite(R_PWM_FOR_TWO, 0);
  analogWrite(L_PWM_FOR_TWO, 0);
};

// Back left
void back_left()
{
  analogWrite(R_PWM_FOR_ONE, 0);
  analogWrite(L_PWM_FOR_ONE, 0);
  analogWrite(R_PWM_FOR_TWO, 0);
  analogWrite(L_PWM_FOR_TWO, speed_max);
};

// Back right
void back_right()
{
  analogWrite(R_PWM_FOR_ONE, speed_max);
  analogWrite(L_PWM_FOR_ONE, 0);
  analogWrite(R_PWM_FOR_TWO, 0);
  analogWrite(L_PWM_FOR_TWO, 0);
};
