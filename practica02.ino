int var=0;
void setup() {
   pinMode(LED_BUILTIN,OUTPUT);
   Serial.begin(9600);
}
void loop() {
    digitalWrite(LED_BUILTIN, HIGH); 
    var+=1;
    Serial.print("The led is on");
    Serial.println(var);
    delay(3000);
    digitalWrite(LED_BUILTIN, LOW); 
    Serial.println("The led is oFF");
    delay(3000);
}
