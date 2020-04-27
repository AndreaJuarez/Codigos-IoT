const int EchoPin = 12;
const int TriggerPin = 11;
const int LedPinVerde = 7;
const int LedPinAmarillo = 6;
const int LedPinRojo = 5;
float distancia;
long tiempo;
 
void setup() {
   Serial.begin(9600);
   pinMode(LedPinVerde, OUTPUT);
   pinMode(LedPinAmarillo, OUTPUT);
   pinMode(LedPinRojo, OUTPUT);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
}
 
void loop() {

  digitalWrite(TriggerPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);

  tiempo = (pulseIn(EchoPin, HIGH)/2); 

  distancia = float(tiempo * 0.0343);

   Serial.print("Distancia: "); 
   Serial.println(distancia);
   

if (distancia >= 70) {
        digitalWrite(LedPinVerde , HIGH);
        digitalWrite(LedPinAmarillo , LOW);
        digitalWrite(LedPinRojo , LOW);
                      }
else if((distancia >=40 ) && (distancia <= 70)){
        digitalWrite(LedPinVerde , LOW);
        digitalWrite(LedPinRojo , LOW);
        digitalWrite(LedPinAmarillo , HIGH);
        
}  
else if ((distancia >=10 )&& (distancia <= 40)) {
        digitalWrite(LedPinVerde , LOW);
        digitalWrite(LedPinAmarillo , LOW);
        digitalWrite(LedPinRojo , HIGH);
}  
else if (distancia <=10 ) {
        digitalWrite(LedPinVerde , LOW);
        digitalWrite(LedPinAmarillo , LOW);
        digitalWrite(LedPinRojo , LOW);
}  

delay(1000);

}
