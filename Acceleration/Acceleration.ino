#include "MPU9250.h"

// an MPU9250 object with the MPU-9250 sensor on I2C bus 0 with address 0x68
MPU9250 IMU(Wire,0x68);
int status;
float AccelX,AccelY,AccelZ;

void setup() {
  // serial to display data
  Serial.begin(9600);
  while(!Serial) {}

  // start communication with IMU 
  status = IMU.begin();
  if (status < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while(1) {}
  }
}

void loop() {
  while(1){
  // read the sensor
  IMU.readSensor();
  // display the data
  AccelX = IMU.getAccelX_mss();
  AccelX = AccelX*1000;
  AccelY = IMU.getAccelY_mss();
  AccelY = AccelY*1000;
  AccelZ = IMU.getAccelZ_mss();
  AccelZ = AccelZ*1000;

  Serial.println((String)"A"+AccelX+"B"+AccelY+"C"+AccelZ); 
  delay(10);
  }
}
