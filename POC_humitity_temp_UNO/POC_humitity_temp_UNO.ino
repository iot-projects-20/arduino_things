/* Arduino DHT11 and DHT22 Oled Display

  Created by Yvan / https://Brainy-Bits.com

  This code is in the public domain...

  You can: copy it, use it, modify it, share it or just plain ignore it!
  Thx!
*/


#include "U8glib.h"   // Library for OlED display https://github.com/olikraus/u8glib/
#include "dht.h"      // DHT sensors library https://github.com/RobTillaart/Arduino/tree/master/libraries/DHTstable

#define DHT11PIN 4  // DHT11 Data pin connected to digital pin 4 on Arduino
#define DHT22PIN 5  // DHT22 Data pin connected to digital pin 5 on Arduino

// OLED SDA and SCL  pins connected to A4 and A5 of Arduino
U8GLIB_SSD1306_128X32 u8gDHT(U8G_I2C_OPT_FAST);  // Init of the OLED

dht DHT11;  // library link for the DHT11
dht DHT22;  // library link for the DHT22

void setup() {

  // Use PullUp resistors for both DHT Data pins
  pinMode(DHT11PIN, INPUT_PULLUP);
  pinMode(DHT22PIN, INPUT_PULLUP);

  // Rotate screen 180 degrees on OLED, uncomment if required
  //u8gDHT.setRot180();

  // Select font to use
  u8gDHT.setFont(u8g_font_unifont);
}

void loop() {
  int DHT11Check = DHT11.read11(DHT11PIN);  // get data from DHT11
  int DHT22Check = DHT22.read22(DHT22PIN);  // get data from DHT22

  // Check if read data checksum is valid
  if ((DHT11Check == 0) && (DHT22Check == 0)) { // valid when equal to zero

    // Display information on the OLED display
    u8gDHT.firstPage();
    do {
      u8gDHT.drawStr( 0, 10, "DTH11:");
      u8gDHT.setPrintPos(65, 10);
      u8gDHT.print(DHT11.temperature, 0);  // Display no decimal
      u8gDHT.drawStr( 88, 10, "|");
      u8gDHT.setPrintPos(104, 10);
      u8gDHT.print(DHT11.humidity, 0);
      u8gDHT.drawStr( 0, 32, "DTH22:");
      u8gDHT.setPrintPos(57, 32);
      u8gDHT.print(DHT22.temperature, 1);  // Display one decimal
      u8gDHT.drawStr( 88, 32, "|");
      u8gDHT.setPrintPos(97, 32);
      u8gDHT.print(DHT22.humidity, 1);
    } while ( u8gDHT.nextPage() );

    delay(3000); // delay before reading sensors again (min. 2 seconds)
  }
}
