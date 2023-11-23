//Constants:
#include <SoftwareSerial.h>
SoftwareSerial BTserial(0, 1); // RX | TX



// For BNO055 Adafruit
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#define BNO055_SAMPLERATE_DELAY_MS (100)

Adafruit_BNO055 bno = Adafruit_BNO055(55);

const int flexPin = 34; //pin A0 to read analog input
int value; //save analog value

void setup(){
  
  Serial.begin(115200);
  Serial.println("Arduino is ready");

  BTserial.begin(9600);  // HC-05 default serial speed for commincation mode is 9600
    
    if(!bno.begin())
    {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
    }

  delay(1000);

  bno.setExtCrystalUse(true);
}

void loop(){
  
  value = analogRead(flexPin);   // Read and save analog value from potentiometer

    if(value>950)
    {
     delay(1000);
     
     Serial.print("Flex Sensor : "); 
     Serial.println("Drink water\n");
     BTserial.write("Drink water");
     
     delay(1000);
    }
    
  sensors_event_t event;
  bno.getEvent(&event);
  
  //event.orientation.y = -10;
  //Serial.print("y: ");
  Serial.println(event.orientation.y, 4);
 
  delay(1000);

    if(event.orientation.y < -10)
    {
     delay(1000);
  
     Serial.print("Accelerometer : "); 
     Serial.print("Help Me!!\n ");
     BTserial.write("Help Me!!");
  
     delay(1000);
    }
  
  value = map(value, 700, 900, 0, 255);  //Map value 0-1023 to 0-255 (PWM)
  
  delay(BNO055_SAMPLERATE_DELAY_MS);
  
}
