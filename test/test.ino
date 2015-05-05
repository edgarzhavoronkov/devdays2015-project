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

int leftHandCurrent;
int leftHandTarget;

int rightHandCurrent;
int rightHandTarget;

int headCurrent;
int headTarget;

void MoveLeftHand()
{
  if (leftHandCurrent == leftHandTarget)
    break;
    
  int dx = 1;
  
  if (leftHandCurrent > leftHandTarget)
    dx *= -1;
    
  leftHandCurrent += dx;
    
  LeftHandServo.write(leftHandCurrent);
}

void MoveRightHand()
{
  if (rightHandCurrent == rightHandTarget)
    break;
    
  int dx = 1;
  
  if (rightHandCurrent > rightHandTarget)
    dx *= -1;
    
  rightHandCurrent += dx;
    
  RightHandServo.write(rightHandCurrent);
}

void MoveHead()
{
  if (headCurrent == headTarget)
    break;
    
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
  
  if (Serial.avaliable() > 0)
  {
    command = Serial.read()
  } else
  {
    break;
  }
  
  //need to read one more parameter
  if (command == COMMAND_MOVE_LH || command == COMMAND_MOVE_RH || command == COMMAND_MOVE_HEAD)
  {
    angle = Serial.read();
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
  }
      
}
 
void setup() 
{ 
  HeadServo.attach(HeadServoPin);
  LeftHandServo.attach(LeftHandServoPin);
  RightHandServo.attach(RightHandServoPin);
  
  leftHandCurrent = leftHandTarget = 0;
  rightHandCurrent = rightHandTarget = 0;
  headCurrent = headHandTarget = 0;
} 
 
 
void loop() 
{ 
  Serial.begin(9600); 

  Parse();

  MoveHead();
  MoveLeftHand();
  MoveRightHand();  
} 
