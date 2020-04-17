/*
   RemoteXY example. 
   Smartphone connect over BLE to ESP32

   In this example you can control a LED on pin 2 using the button in 
   the RemoteXY app on the smartphone. 
   
   Use the website http://remotexy.com/ to create your own user
   interface on your smartphone or tablet.
   You can create different user interfaces. Use buttons, 
   switches, sliders, joysticks (g-sensor) all colors and sizes 
   in its interface. Next, you will be able to get the sample 
   code for arduino to use your interface for control from a 
   smartphone or tablet. You will not need to re-install the 
   android app, as it will determine which interface you have 
   downloaded the arduino.
   
   To compile this code using RemoteXY library 2.4.4 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.5.1 or later version;
     - for iOS 1.4.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// #define REMOTEXY__DEBUGLOGS Serial

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP32CORE_BLE

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_BLUETOOTH_NAME "RemoteXY"


// RemoteXY configurate  
#pragma pack(push, 1)
/* RemoteXY configurate  */ 
unsigned char RemoteXY_CONF[] = 
  { 1,0,11,0,1,5,1,0,21,2
  ,59,59,2,88,0 }; 
   
/* this structure defines all the variables of your control interface */ 
struct { 

    /* input variable */
  unsigned char button_1; /* =1 if button pressed, else =0 */

    /* other variable */
  unsigned char connect_flag;  /* =1 if wire connected, else =0 */

} RemoteXY; 
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define LED_PIN 2

void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (LED_PIN, OUTPUT);
  
  // TODO your setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(LED_PIN, (RemoteXY.button_1==0)?LOW:HIGH);
  
  // TODO your loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}
