#include <MKRIMU.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");

    while (1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  float x, y, z;
  if(IMU.magneticFieldAvailable()) {
    IMU.readMagneticField(x, y, z); //uT
    Serial.print("M ");
    Serial.print(x);
    Serial.print(" ");
    Serial.print(y);
    Serial.print(" ");
    Serial.println(z);
  }
  if(IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z); //g's
    Serial.print("A ");
    Serial.print(x);
    Serial.print(" ");
    Serial.print(y);
    Serial.print(" ");
    Serial.println(z);
  }
  if(IMU.eulerAnglesAvailable()) {
    IMU.readEulerAngles(x, y, z);//heading roll pitch
    Serial.print("E ");
    Serial.print(x);
    Serial.print(" ");
    Serial.print(y);
    Serial.print(" ");
    Serial.println(z);
  }
  if(IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(x, y, z); //deg/sec
    Serial.print("G ");
    Serial.print(x);
    Serial.print(" ");
    Serial.print(y);
    Serial.print(" ");
    Serial.println(z);
  }
  delay(100);
}
