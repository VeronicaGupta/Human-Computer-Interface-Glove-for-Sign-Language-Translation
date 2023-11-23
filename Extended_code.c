String sp = " ";

String fingerDegrees = "FingerDegrees: ";
String knuckleDegrees = "KnuckleDegrees: ";
 
 void setup()
{
  Serial.begin(9600);
  
}
void loop()
{
  int flexRaw[9];
  int flexDegrees[9];
  int flexDegCal[9][2];
  int flexPinMap[9];
  /* Mapping to Analog pins on teensy
    from flexPinMap[0] to flexPinMap[8]
    Index, IndexKnuckle, Middle, MiddleKnuckle
    Ring, Ring Knuckle, Pinky, Thumb, Thumb Knuckle
  */
  flexPinMap[0] = 28; flexPinMap[1] = 27; flexPinMap[2] = 26; flexPinMap[3] = 31;
  flexPinMap[4] = 30; flexPinMap[5] = 29; flexPinMap[6] = 35; flexPinMap[7] = 34;
  flexPinMap[8] = 36;

  // Calibrated mapping from analog values to degrees for each joint
  flexDegCal[0][0] = 490; flexDegCal[0][1] = 662; // Middle Knuckle
  flexDegCal[1][0] = 578; flexDegCal[1][1] = 720; // Pinky
  flexDegCal[2][0] = 500; flexDegCal[2][1] = 697; // Ring Knuckle
  flexDegCal[3][0] = 488; flexDegCal[3][1] = 600; // Thumb Knuckle
  flexDegCal[4][0] = 590; flexDegCal[4][1] = 662; // Thumb
  flexDegCal[5][0] = 542; flexDegCal[5][1] = 705; // Index Knuckle
  flexDegCal[6][0] = 539; flexDegCal[6][1] = 680; // Middle
  flexDegCal[7][0] = 503; flexDegCal[7][1] = 708; // Index
  flexDegCal[8][0] = 503; flexDegCal[8][1] = 752; // Ring
  
  for (int i = 0; i < 9; i++){
    flexRaw[i] = analogRead(flexPinMap[i]);
    flexDegrees[i] = map(flexRaw[i], flexDegCal[i][0], flexDegCal[i][1], 0, 90);
  }

  // print the finger and knuckle bending degrees to serial output
  Serial.println(fingerDegrees + flexDegrees[7] + sp + flexDegrees[6] + sp + flexDegrees[8] + sp + flexDegrees[1] + sp + flexDegrees[4]);
  Serial.println(knuckleDegrees + flexDegrees[5] + sp + flexDegrees[0] + sp + flexDegrees[2] + sp + flexDegrees[3]);

Serial.println("FlexSensorBending(raw)");
Serial.print("Index: ");
Serial.println(flexRaw[7],DEC);
//Serial.print(F(" "));
Serial.print("Middle: ");
Serial.println(flexRaw[6],DEC);
//Serial.print(F(" "));
Serial.print("Ring: ");
Serial.println(flexRaw[8],DEC);
//Serial.print(F(" "));
Serial.print("Pinky: ");
Serial.println(flexRaw[1],DEC);
//Serial.print(F(""));
Serial.print("Thumb: ");
Serial.println(flexRaw[4],DEC);

delay(1000);
}
