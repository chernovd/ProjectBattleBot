#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define motorRightBackwardPin 4
#define motorRightForwardPin 9
#define motorLeftBackwardPin 2
#define motorLeftForwardPin 3

#define ultrasonicPin 12
#define ultrasonicTriggerPin 13

#define infraredLeftPin 10
#define infraredRightPin 11

#define bluetoothReceivePin A0
#define bluetoothTransmitPin A1

#define lcdColumns 16
#define lcdRows 2
void loop() 
{
    bool LeftSees = InfraredLeftDetect();
    bool RightSees = InfraredRightDetect();
    
    if((!LeftSees) && (!RightSees))
      {
        MoveForward(150, 150);
      }
    else if((LeftSees) && (RightSees))
      {
        StopMoving();
      }
    else if((!LeftSees) && (RightSees))
      {

        RotateLeft(150, 150);
      }
    else if((LeftSees) && (!RightSees))
      {
        RotateRight(150, 150);
      }
}
