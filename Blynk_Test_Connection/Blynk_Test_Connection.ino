/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "iBqTrA9W41BxmMl-bXcwV2JUbcOu5Pbm";

// Your WiFi credentials.
//// Set password to "" for open networks.
//char ssid[] = "YourNetworkName";
//char pass[] = "YourPassword";

const char* ssid = "RohPri"; //Enter SSID
const char* password = "FNA4N7YG"; //Enter Password
// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin 1
int D7 = 1;


BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  Serial.print("V1 Slider value is: ");
  Serial.println(pinValue);


  if(pinValue == 1)
      digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH


  if(pinValue == 0)
      digitalWrite(LED_BUILTIN, LOW);  // Turn the LED off by making the voltage HIGH

  
}

void setup()
{
  // Debug console
  Serial.begin(9600);
pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
Blynk.begin(auth, ssid, password);
}

void loop()
{
  Blynk.run();
}
