#include "ESP8266WiFi.h"

const char* ssid = "RohPri"; //Enter SSID
const char* password = "FNA4N7YG"; //Enter Password
// 78983
// 7105

void setup(void)
{ 
  Serial.begin(9600);
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
     delay(500);
     Serial.print("*");
  }
  
  Serial.println("");
  Serial.println("WiFi connection Successful");
  Serial.print("The IP Address of ESP8266 Module is: ");
  Serial.print(WiFi.localIP());// Print the IP address
    Serial.println("");

}

void loop() 
{
  if (WiFi.status() != WL_CONNECTED)  {
        Serial.println("WIFI not connected  ");

  } else {
        Serial.println("WIFI  connected  ");
    
  }

  // EMPTY
}
