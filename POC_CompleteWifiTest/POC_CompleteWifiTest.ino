#include <ESP8266WiFi.h>

 
const char* ssid = "Rohan-iphone"; //Enter SSID
const char* password = "tubers2721"; //Enter Password


int LED = 2;   // led connected to GPIO2 (D4)

WiFiServer server(80);

 

void setup()

{

  Serial.begin(9600); //Default Baudrate

  pinMode(LED, OUTPUT);

  digitalWrite(LED, LOW);

 

  Serial.print("Connecting to the Newtork");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)

  {

    delay(500);

    Serial.print(".");

  }

  Serial.println("WiFi connected"); 

  server.begin();  // Starts the Server

  Serial.println("Server started");

 

  Serial.print("IP Address of network: "); // will IP address on Serial Monitor

  Serial.println(WiFi.localIP());

  Serial.print("Copy and paste the following URL: https://"); // Will print IP address in URL format

  Serial.print(WiFi.localIP());

  Serial.println("/");

}

 

void loop()

{

  WiFiClient client = server.available();

  if (!client)

  {

    return;

  }

  Serial.println("Waiting for new client");

  while(!client.available())

  {

    delay(1);

  }

 

  String request = client.readStringUntil('\r');

  Serial.println(request);

  client.flush();

 

  int value = LOW;

  if(request.indexOf("/LED=ON") != -1)

  {
  Serial.println("Request to Switching ON the fridge");

    digitalWrite(LED, HIGH); // Turn LED ON

    value = HIGH;
    return;

  } else {
      Serial.println("Failure to : Request to Switching ON the fridge");

  }

  if(request.indexOf("/LED=OFF") != -1)

  {
  Serial.println("Request to Switching OFF the fridge");

    digitalWrite(LED, LOW); // Turn LED OFF

    value = LOW;
     return;

  } else {
      Serial.println("Failure to : Request to Switching OFF the fridge");

  }
  
}
 
