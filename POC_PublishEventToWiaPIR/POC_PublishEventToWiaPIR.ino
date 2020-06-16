#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ArduinoHttpClient.h>

const char ssid[] = "TALKTALKCDA754"; // WiFI ssid
const char password[] = "TFDU9NVQ"; //WiFI password

// get this from the wia dashboard. it should start with `d_sk`
const char* device_secret_key = "d_sk_EXrptfkjcU5M3YOllFGgdCcg";

char server[] = "api.wia.io";
char path[] = "/v1/events";
int port = 80;
int sensor = 13;  // Digital pin D7
int light = 12;

WiFiClient client;
int status = WL_IDLE_STATUS;
HttpClient httpClient = HttpClient(client, server, port);

StaticJsonDocument<200> jsonBuffer;
JsonObject root = jsonBuffer.to<JsonObject>();

void setup() {
  // initialize serial communications and wait for port to open:
  Serial.begin(115200);
  pinMode(sensor, INPUT);
  pinMode(light, OUTPUT);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  WiFi.begin(ssid, password);
  Serial.print("Attempting to connect to SSID: ");
  Serial.print(ssid);
  // attempt to connect to WiFi network:
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    // Connect to WPA/WPA2 network. Change this line if using open or WEP  network:
    // wait 5 seconds for connection:
    delay(5000);
  }
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Connected");
}

void loop() {
  root["name"] = "hello-wia";

  long state = digitalRead(sensor);
  if (state == HIGH) {
    Serial.println("Motion detected!");
    digitalWrite(light, HIGH);

    delay(10000);
    digitalWrite(light, LOW);

  }

  postToWia(root);
  delay(10000);
}

// Adds the correct headers for HTTP and sends Data to Wia
void postToWia(JsonObject& data) {
  //String dataStr = "{name=LED, data=ON}";
  String dataStr = "";
  serializeJson(data, dataStr);
  httpClient.beginRequest();
  httpClient.post(path);
  httpClient.sendHeader("Content-Type", "application/json");
  httpClient.sendHeader("Content-Length", dataStr.length());
  httpClient.sendHeader("Authorization", "Bearer "  + String(device_secret_key));
  httpClient.beginBody();
  httpClient.print(dataStr);
  httpClient.endRequest();
}
