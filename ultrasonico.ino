#include <NewPing.h>
#define TRIGGER_PIN  11
#define ECHO_PIN 12
#define MAX_DISTANCE  200

NewPing sonar (TRIGGER_PIN,ECHO_PIN,MAX_DISTANCE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  int uS = sonar.ping_median();
  Serial.println("Distancia");
  int distancia = (uS/US_ROUNDTRIP_CM);
  Serial.print(distancia);
  Serial.println("cm");
}
