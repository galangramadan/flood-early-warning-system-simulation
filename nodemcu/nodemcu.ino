#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include "secrets.h"

int sensor_pin = A0;
int relay1 = 5;
const char* ssid = WIFI_SSID;
const char* password = WIFI_PASSWORD;
const char* serverName = API_ENDPOINT;

void setup(){
Serial.begin(9600);
pinMode(relay1, OUTPUT);

WiFi.begin(ssid, password);
Serial.println("Connecting");
while(WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
}
Serial.println("");
Serial.print("Connected to WiFi network with IP Address: ");
Serial.println(WiFi.localIP());
 
Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}

void loop(){
int s1=analogRead(sensor_pin);
Serial.println(s1);

if(WiFi.status()== WL_CONNECTED){
  WiFiClientSecure client;
  client.setInsecure();
  HTTPClient https;
  https.begin(client, serverName);
  https.addHeader("Content-Type", "application/json");
  
  if(s1>400){
    digitalWrite(relay1, LOW);
    Serial.println("hidup");
    https.PUT("{\"status\":\"bahaya\"}");       
    delay(1000);
    } else {
    digitalWrite(relay1, HIGH);
    Serial.println("mati");         
    delay(1000);
    }
  } else {
      Serial.println("WiFi Disconnected");
  }
}
