#include <Servo.h> 
 
const int COMMAND_BLINK_ON = 1;
const int COMMAND_EYES_ON = 2;
const int COMMAND_EYES_OFF = 3;
const int COMMAND_MOVE_LH = 4;
const int COMMAND_MOVE_RH = 5;
const int COMMAND_MOVE_HEAD = 6;

Servo HeadServo;
Servo LeftHandServo;
Servo RightHandServo;

int HeadServoPin = 9;
int LeftHandServoPin = 10;
int RightHandServoPin = 11;

int LeftEyePin = 12;
int RightEyePin = 13;

int leftHandCurrent;
int leftHandTarget;

int rightHandCurrent;
int rightHandTarget;

int headCurrent;
int headTarget;

int blinkFlag1;
int blinkFlag2;

void BlinkOn()
{
  if (blinkFlag1 != blinkFlag2)
  {
    digitalWrite(LeftEyePin, HIGH);
    digitalWrite(RightEyePin, HIGH);
    delay(100);
    digitalWrite(LeftEyePin, LOW);
    digitalWrite(RightEyePin, LOW);
  }  
}

void EyesOn()
{
  if (blinkFlag1 == blinkFlag2 && blinkFlag1 == 1 && blinkFlag2 == 1)
  {
    digitalWrite(LeftEyePin, HIGH);
    digitalWrite(RightEyePin, HIGH);    
  }
}

void EyesOff()
{
  if (blinkFlag1 == blinkFlag2 && blinkFlag1 == 0 && blinkFlag2 == 0)
  {
    digitalWrite(LeftEyePin, LOW);
    digitalWrite(RightEyePin, LOW);    
  }
}

void MoveLeftHand()
{
  if (leftHandCurrent == leftHandTarget)
    return;
    
  int dx = 1;
  
  if (leftHandCurrent > leftHandTarget)
    dx *= -1;
    
  leftHandCurrent += dx;
    
  LeftHandServo.write(leftHandCurrent);
}

void MoveRightHand()
{
  if (rightHandCurrent == rightHandTarget)
    return;
    
  int dx = 1;
  
  if (rightHandCurrent > rightHandTarget)
    dx *= -1;
    
  rightHandCurrent += dx;
    
  RightHandServo.write(rightHandCurrent);
}

void MoveHead()
{
  if (headCurrent == headTarget)
    return;
    
  int dx = 1;
  
  if (headCurrent > headTarget)
    dx *= -1;
    
  headCurrent += dx;
    
  HeadServo.write(headCurrent);
}

void Parse()
{
  int command = 0;
  int angle = 0;
  
  if (Serial.available() > 0)
  {
    command = Serial.parseInt();
    //need to read one more parameter
    if (command == COMMAND_MOVE_RH || command == COMMAND_MOVE_LH || command == COMMAND_MOVE_HEAD)
    {
      angle = Serial.parseInt();
    }
  } else
  {
    return;
  }
  
  if (command == COMMAND_MOVE_LH)
  {
    leftHandTarget = angle;
  } else if (command == COMMAND_MOVE_RH)
  {
    rightHandTarget = angle;
  } else if (command == COMMAND_MOVE_HEAD)
  {
    headTarget = angle;
  } else if (command == COMMNAND_BLINK_ON)
  {
    blinkFlag1 = 1;
    blinkFlag2 = 0;
  } else if (command == COMMNAND_EYES_ON)
  {
    blinkFlag1 = 1;
    blinkFlag2 = 1;
  } else if (command == COMMNAND_EYES_OFF)
  {
    blinkFlag1 = 0;
    blinkFlag2 = 0;
  }    
}
 
void setup() 
{ 
  Serial.begin(57600);
  HeadServo.attach(HeadServoPin);
  LeftHandServo.attach(LeftHandServoPin);
  RightHandServo.attach(RightHandServoPin);
  
  pinMode(LeftEyePin, OUTPUT);
  pinMode(RightEyePin, OUTPUT;
  
  leftHandCurrent = leftHandTarget = 0;
  rightHandCurrent = rightHandTarget = 0;
  headCurrent = headTarget = 0;
  LeftHandServo.write(1);
  RightHandServo.write(1);
  HeadServo.write(1);
} 
 
 
void loop() 
{  
  Parse();

  MoveHead();
  MoveLeftHand();
  MoveRightHand();
  BlinkOn();
  EyesOn();
  EyesOff();
  delay(10);  
} 
