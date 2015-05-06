#include <Servo.h> 
 
const int COMMAND_BLINK_ON = 1;
const int COMMAND_EYES_ON = 2;
const int COMMAND_EYES_OFF = 3;
const int COMMAND_MOVE_LH = 4;
const int COMMAND_MOVE_RH = 5;
const int COMMAND_MOVE_HEAD = 6;
const int COMMAND_GO = 7;
const int COMMAND_STOP = 8;

Servo HeadServo;
Servo LeftHandServo;
Servo RightHandServo;

int HeadServoPin = 9;
int LeftHandServoPin = 10;
int RightHandServoPin = 11;

int LeftEyePin = 12;
int RightEyePin = 13;

int LeftWheelPlus = 3;
int LeftWheelMinus = 4;
int RightWheelPlus = 5;
int RightWheelMinus = 6;

int leftHandCurrent;
int leftHandTarget;

int rightHandCurrent;
int rightHandTarget;

int headCurrent;
int headTarget;

int blinkFlag1;
int blinkFlag2;

int goCurrent;
int goTarget;

int counter = 0;
int state = 1;

const int MAX_VALUE = 20;

void BlinkOn()
{
  if (blinkFlag1 != blinkFlag2)
  {
    if (counter <= MAX_VALUE)
    {
      digitalWrite(LeftEyePin, state);
      digitalWrite(RightEyePin, state);
      counter += 1;
    }
    else
    {
      state = !state;
      counter = 0;  
    }
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

void goOn()
{
  if (goCurrent == goTarget)
  {
   goOff();
   return;
  }
 
  if (goCurrent > goTarget)
  {
    goCurrent -= 1;
    
    digitalWrite(LeftWheelPlus, LOW);
    digitalWrite(LeftWheelMinus, HIGH);
  
    digitalWrite(RightWheelPlus, LOW);
    digitalWrite(RightWheelMinus, HIGH);
    
  } else
  {
    goCurrent += 1;
    
    digitalWrite(LeftWheelPlus, HIGH);
    digitalWrite(LeftWheelMinus, LOW);
  
    digitalWrite(RightWheelPlus, HIGH);
    digitalWrite(RightWheelMinus, LOW);
  }
}

void goOff()
{
  digitalWrite(LeftWheelPlus, LOW);
  digitalWrite(LeftWheelMinus, LOW);
  
  digitalWrite(RightWheelPlus, LOW);
  digitalWrite(RightWheelMinus, LOW);
}

void Parse()
{
  int command = 0;
  int angle = 0;
  int distance = 0;
  
  String curStr;
  
  if (Serial.available() > 0)
  {
    curStr = (String)Serial.readStringUntil('\n');
    command = curStr[0] - '0';

    if (command == COMMAND_MOVE_RH || command == COMMAND_MOVE_LH || command == COMMAND_MOVE_HEAD)
    {
      String newStr;
      int i = 2;
      while (curStr[i] != 0)
        newStr += curStr[i++];
        
      newStr[i] = 0;
      
      angle = newStr.toInt();
    } else if (command == COMMAND_GO)
    {
      String newStr;
      int i = 2;
      while (curStr[i] != 0)
        newStr += curStr[i++];
        
      newStr[i] = 0;
      
      distance = newStr.toInt();
    }
    
  } else
  {
    return;
  }
  
  if (angle <= 0)
  {
    angle = 1;
  } else if (angle > 160)
  {
    angle = 160;
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
  } else if (command == COMMAND_BLINK_ON)
  {
    state = 1;
    blinkFlag1 = 1;
    blinkFlag2 = 0;
  } else if (command == COMMAND_EYES_ON)
  {
    blinkFlag1 = 1;
    blinkFlag2 = 1;
  } else if (command == COMMAND_EYES_OFF)
  {
    blinkFlag1 = 0;
    blinkFlag2 = 0;
  } else if (command == COMMAND_GO)
  {
    goTarget = distance;
  }
}
 
void setup() 
{ 
  Serial.begin(57600);
  HeadServo.attach(HeadServoPin);
  LeftHandServo.attach(LeftHandServoPin);
  RightHandServo.attach(RightHandServoPin);
  
  pinMode(LeftEyePin, OUTPUT);
  pinMode(RightEyePin, OUTPUT);
  
  leftHandCurrent = leftHandTarget = 0;
  rightHandCurrent = rightHandTarget = 0;
  headCurrent = headTarget = 0;
  goTarget = goCurrent = 0;
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
  goOn();
  
  delay(10);  
} 
