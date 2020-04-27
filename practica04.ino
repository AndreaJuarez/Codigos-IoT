int var=0;
const int buttonPin = 2;
const int ledPin = 13;
int buttonState = 0;
int flag = 0;

void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
  Serial.begin(9600);
}

void loop() {  // put your main code here, to run repeatedly:
buttonState = digitalRead(buttonPin);
  if(var != buttonState){
    if(var == 1){
      flag+=1;
      Serial.println(flag);
    }
    if(flag%11==0){
      digitalWrite(ledPin, HIGH);
    }else{
      digitalWrite(ledPin, LOW);
    }
  }
  delay(100);
  var=buttonState;
}
