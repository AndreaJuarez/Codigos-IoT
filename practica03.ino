// put your setup code here, to run once:
const int buttonPin = 2;
const int ledPin = 13;
int buttonState = 0;

void setup() {
   pinMode(ledPin,OUTPUT);
   pinMode(buttonPin,INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH){
    digitalWrite(ledPin,HIGH); 
  }
  else {
     digitalWrite(ledPin,LOW); 
   }
}
