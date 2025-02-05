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
  Serial.println(IMU.gyroscopeSampleRate());
  Serial.println("Degrees/sec: \nx\ty\tz");
}

void loop() {
  // put your main code here, to run repeatedly:
  float x, y, z;

  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(x, y, z);

    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);
  }
  delay(100);
}
