int pin_red=11;
int pin_green=10;
int pin_blue=9;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_red,OUTPUT);
  pinMode(pin_green,OUTPUT);
  pinMode(pin_blue,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  rgb_color(255,0,0);//rojo
  delay(1000);
  rgb_color(0,255,0);//verde
  delay(1000);
  rgb_color(0,0,255);//azul
  delay(1000);
  rgb_color(255,255,0);//amarillo
  delay(1000);
  rgb_color(255,255,255);//blanco
  delay(1000);
  rgb_color(0,255,255);//cyan
  delay(1000);
}

void rgb_color(int red, int green, int blue){
  analogWrite(pin_red,red);
  analogWrite(pin_green,green);
  analogWrite(pin_blue,blue);
}
