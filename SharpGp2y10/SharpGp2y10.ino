#define SCALE 5.0/1024

int measurePin = A0;
int ledPin = 2;

int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;

float v0Measured = 0;
float calcVoltage = 0;
float dustDensity = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, LOW);
  delayMicroseconds(samplingTime);
  v0Measured = analogRead(measurePin);
  delayMicroseconds(deltaTime);
  digitalWrite(ledPin, HIGH);
  delayMicroseconds(sleepTime);

  calcVoltage = v0Measured * SCALE;
  dustDensity = 0.17 * calcVoltage - 0.1;

  Serial.print("Raw signal value (0 - 1023): ");
  Serial.print(v0Measured);
  Serial.print(" - Voltage: ");
  Serial.print(calcVoltage);
  Serial.print(" - Dust Density: ");
  Serial.print(dustDensity);
  Serial.println();
  delay(1000);
}
