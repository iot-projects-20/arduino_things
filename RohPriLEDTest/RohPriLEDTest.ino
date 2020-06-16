int rohPriPin = 5;  // pin 2 is built in LED on ESP 8266

void setup() {
  Serial.begin(9600);

  pinMode(rohPriPin, OUTPUT);

}

void loop() {
  Serial.println("WiFi connection Successful");

  digitalWrite(rohPriPin, HIGH);

  delay(500);
  digitalWrite(rohPriPin, LOW);

  delay(500);
}
