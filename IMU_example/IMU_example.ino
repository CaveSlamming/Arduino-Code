#include <MKRIMU.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);

  if(!IMU.begin()) {
    Serial.println("Failed to initialize IMU.");

    while(1);
  }
  delay(100);
  Serial.print("Sampling rate: ");
  Serial.println(IMU.accelerationSampleRate());
}

void loop() {
  // put your main code here, to run repeatedly:
  float x, y, z;

  if(IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
  }

  Serial.print("X accel: ");
  Serial.print(x);
  Serial.print(" Y accel: ");
  Serial.print(y);
  Serial.print(" Z accel: ");
  Serial.println(z);
  
  delay(500);
}
