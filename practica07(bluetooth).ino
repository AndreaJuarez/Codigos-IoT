char valor_entrada =0;
void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);

}

void loop() {
  if(Serial.available()>0){
    valor_entrada = Serial.read();
    Serial.print("valor de entrada:");
    Serial.print(valor_entrada);

    if (valor_entrada == '1'){
      digitalWrite(13,HIGH);
    }
    else if (valor_entrada == '0'){
      digitalWrite(13,LOW);
    }
  }
}
