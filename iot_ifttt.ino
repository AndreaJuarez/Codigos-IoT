#include <ESP8266WiFi.h>

// Replace with your SSID and Password
const char* ssid     = "andy";
const char* password = "andy1406";

// Replace with your unique IFTTT URL resource
const char* resource = "https://maker.ifttt.com/trigger/motion_sensor/with/key/nqoxZS443u-GjkxaMh8P5zVEEdAUxCHX-I3KmMj8lFc";

// How your resource variable should look like, but with your own API KEY (that API KEY below is just an example):
//const char* resource ="/trigger/motion_sensor/with/key/nqoxZS443u-GjkxaMh8P5zVEEdAUxCHX-I3KmMj8lFc";

// Maker Webhooks IFTTT
const char* server = "maker.ifttt.com";

//VARIABLES DEL SENSOR
const int pir=5;
int pir_lectura=0;


void setup() {
  pinMode(pir, INPUT);
  Serial.begin(115200); 
  initWifi();
}
void loop() {
  delay(1000);
  Serial.println(digitalRead(pir));
  pir_lectura=digitalRead(pir);
  if (pir_lectura==HIGH) { 
    Serial.println("Movimiento");
     makeIFTTTRequest();
  }
  else { 
    Serial.println("No hay movimientos");
  }
}

// Establish a Wi-Fi connection with your router
void initWifi() {
  Serial.print("Connecting to: "); 
  Serial.print(ssid);
  WiFi.begin(ssid, password);  

  int timeout = 10 * 4; // 10 seconds
  while(WiFi.status() != WL_CONNECTED  && (timeout-- > 0)) {
    delay(250);
    Serial.print(".");
  }
  Serial.println("");

  if(WiFi.status() != WL_CONNECTED) {
     Serial.println("Failed to connect, going back to sleep");
  }

  Serial.print("WiFi connected in: "); 
  Serial.print(millis());
  Serial.print(", IP address: "); 
  Serial.println(WiFi.localIP());
}

// Make an HTTP request to the IFTTT web service
void makeIFTTTRequest() {
  Serial.print("Connecting to "); 
  Serial.print(server);
  
  WiFiClient client;
  int retries = 5;
  while(!!!client.connect(server, 80) && (retries-- > 0)) {
    Serial.print(".");
  }
  Serial.println();
  if(!!!client.connected()) {
     Serial.println("Failed to connect, going back to sleep");
  }
  
  Serial.print("Request resource: "); 
  Serial.println(resource);
  client.print(String("GET ") + resource + 
                  " HTTP/1.1\r\n" +
                  "Host: " + server + "\r\n" + 
                  "Connection: close\r\n\r\n");
                  
  int timeout = 5 * 10; // 5 seconds             
  while(!!!client.available() && (timeout-- > 0)){
    delay(100);
  }
  if(!!!client.available()) {
     Serial.println("No response, going back to sleep");
  }
  while(client.available()){
    Serial.write(client.read());
  }
  
  Serial.println("\nclosing connection");
  client.stop();
}
