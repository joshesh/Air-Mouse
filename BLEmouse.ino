

#define Name "Mousera1001" //Name of Device
#define Manu "Webloo" // Manufacturer of device
#define Battery 100 // Battery Percentage

#include <BleMouse.h>  // Including BLE Mouse Library
#include <BleKeyboard.h> // Including BLE Keyboad Library
#include <MPU6050.h> // Including MPU6050 Library

BleKeyboard bleKeyboard(Name,Manu,Battery);  
BleMouse bleMouse(Name,Manu,Battery);

//Globals for mouse
unsigned long startTime;
int mov(int x , int y);
int stt();
//Globals for MPU6050
MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy;
int getval();
//

void setup() 
{
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleMouse.begin();
  bleKeyboard.begin();
  mpu.initialize();
  if (!mpu.testConnection()) { while (1); }
  
  
}

void loop() 
{
  if(bleMouse.isConnected() && bleKeyboard.isConnected())
  {
    
  }

}

void mov(x, y)
{
   startTime = millis();
    while(millis()<startTime+2000) 
    {
      bleMouse.move(x,y);
      delay(100);
    }
    return 0;
}

int stt()
{
   bleKeyboard.press(KEY_LEFT_GUI);
   bleKeyboard.press('h');
   return 0;

}

int getval()
{
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  vx = (gx+300)/150;  // change 300 from 0 to 355
  vy = -(gz-100)/150; // same here about "-100"  from -355 to 0
  return vx,vy;
}
