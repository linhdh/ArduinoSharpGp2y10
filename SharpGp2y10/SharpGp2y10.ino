#include <GP2YDustSensor.h>

int measurePin = A0;
int ledPin = 2;

GP2YDustSensor dustSensor(GP2YDustSensorType::GP2Y1014AU0F, ledPin, measurePin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dustSensor.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Dust density: ");
  Serial.print(dustSensor.getDustDensity());
  Serial.print(" ug/m3; Running average: ");
  Serial.print(dustSensor.getRunningAverage());
  Serial.println(" ug/m3");  
  delay(1000);
}
