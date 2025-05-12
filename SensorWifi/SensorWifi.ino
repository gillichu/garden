/*
  Complete details at https://RandomNerdTutorials.com/esp32-useful-wi-fi-functions-arduino/
*/

#include <WiFi.h>
#include <HTTPClient.h>

// Replace with your network credentials (STATION)
const char* ssid = "servicenet";
const char* password = "";

const char* serverName = "https://d356-140-180-240-55.ngrok-free.app/sensor-data";

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastTime = 0;
// Timer set to 10 minutes (600000)
//unsigned long timerDelay = 600000;
// Set timer to 5 seconds (5000)
unsigned long timerDelay = 5000;


void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  initWiFi();
  Serial.print("RRSI: ");
  Serial.println(WiFi.RSSI());

  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");

}

void loop() {
  // put your main code here, to run repeatedly:

  // if ((millis() - lastTime) > timerDelay) {
  //   //Check WiFi connection status
  //   if(WiFi.status()== WL_CONNECTED){
  //     WiFiClient client;
  //     HTTPClient http;
    
  //     // Your Domain name with URL path or IP address with path
  //     http.begin(client, serverName);
      
  //     // If you need Node-RED/server authentication, insert user and password below
  //     //http.setAuthorization("REPLACE_WITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");
      
  //     // Specify content-type header
  //     // Data to send with HTTP POST
  //     http.addHeader("Content-Type", "application/json");

  //     int httpResponseCode = http.POST("{\"sensor\":\"BME280\",\"humidity\":\"24.25\",\"value2\":\"49.54\",\"value3\":\"1005.14\"}");      // Send HTTP POST request
      
  //     // If you need an HTTP request with a content type: application/json, use the following:
  //     //http.addHeader("Content-Type", "application/json");
  //     //int httpResponseCode = http.POST("{\"api_key\":\"tPmAT5Ab3j7F9\",\"sensor\":\"BME280\",\"value1\":\"24.25\",\"value2\":\"49.54\",\"value3\":\"1005.14\"}");

  //     // If you need an HTTP request with a content type: text/plain
  //     //http.addHeader("Content-Type", "text/plain");
  //     //int httpResponseCode = http.POST("Hello, World!");
     
  //     Serial.print("HTTP Response code: ");
  //     Serial.println(httpResponseCode);
        
  //     // Free resources
  //     http.end();
  //   }
  //   else {
  //     Serial.println("WiFi Disconnected");
  //   }
  //   lastTime = millis();
  // }

  if ((millis() - lastTime) > timerDelay) { 
    HTTPClient http;
    http.begin(serverName); 
    http.addHeader("Content-Type", "application/json");
    int httpResponseCode = http.POST("{\"temperature\": 25, \"humidity\": 60}");
    Serial.println(httpResponseCode);
    lastTime = millis();
  }

}
