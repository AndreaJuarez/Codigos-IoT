#include <SoftwareSerial.h>
SoftwareSerial esp8266(2, 3); //Pin 2 & 3 of Arduino as RX and TX. Connect TX and RX of ESP8266 respectively.
#define DEBUG true
int pin_red = 11;
int pin_green = 10;
int pin_blue = 9;

void rgb_color(int red, int green, int blue)
{
  analogWrite(pin_red, red);
  analogWrite(pin_green, green);
  analogWrite(pin_blue, blue);
}

void setup()
{
  pinMode(pin_red, OUTPUT);
  pinMode(pin_green, OUTPUT);
  pinMode(pin_blue, OUTPUT);
  digitalWrite(pin_red, LOW);
  digitalWrite(pin_green, LOW);
  digitalWrite(pin_blue, LOW);
  Serial.begin(9600);
  esp8266.begin(115200);                                                         //Baud rate for communicating with ESP8266. Your's might be different.
  esp8266Serial("AT+RST\r\n", 5000, DEBUG);                                      // Reset the ESP8266
  esp8266Serial("AT+CWMODE=1\r\n", 5000, DEBUG);                                 //Set station mode Operation
  esp8266Serial("AT+CWJAP=\"joel\",\"123456789\"\r\n", 5000, DEBUG); //Enter your WiFi network's SSID and Password.

  while (!esp8266.find("OK"))
  {
  }
  esp8266Serial("AT+CIFSR\r\n", 5000, DEBUG);                                   //You will get the IP Address of the ESP8266 from this command.
  esp8266Serial("AT+CIPMUX=1\r\n", 5000, DEBUG);
  esp8266Serial("AT+CIPSERVER=1,80\r\n", 5000, DEBUG);
}

void loop()
{
  if (esp8266.available())
  {
    if (esp8266.find("+IPD,"))
    {
      String msg;
      esp8266.find("?");
      msg = esp8266.readStringUntil(' ');
      String command1 = msg.substring(0, 3);
      String command2 = msg.substring(4);
      if (DEBUG)
      {
        Serial.println(command1);    //Must print "led"
        Serial.println(command2);    //Must print "ON" or "OFF"
      }
      delay(100);
      if (command2 == "ONR")
      {
        rgb_color(255, 0, 0);
        Serial.println("Turn ON");
      }
      else if (command2 == "ONG")
      {
        rgb_color(0, 255, 0);
        Serial.println("Turn ON");
      }
      else if (command2 == "ONB")
      {
        rgb_color(0, 0, 255);
        Serial.println("Turn ON");
      }
      else
      {
        rgb_color(0, 0, 0);
        Serial.println("Turn OFF");
      }
    }
  }
}

String esp8266Serial(String command, const int timeout, boolean debug)
{
  String response = "";
  esp8266.print(command);
  long int time = millis();
  while ((time + timeout) > millis())
  {
    while (esp8266.available())
    {
      char c = esp8266.read();
      response += c;
    }
  }
  if (debug)
  {
    Serial.print(response);
  }
  return response;
}
