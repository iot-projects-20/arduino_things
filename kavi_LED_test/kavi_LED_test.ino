int suryaPin = 2;  // pin 2 is built in LED on ESP 8266
int configPin = 'D4';  // mapping to D4 Pin on board

void setup() {
  Serial.begin(9600);

  pinMode(suryaPin, OUTPUT);
  pinMode(configPin, OUTPUT);

}

void loop() {
    Serial.println(" connection Successful");

  digitalWrite(suryaPin, HIGH);
  pinMode(configPin, LOW);

  delay(500);
  digitalWrite(suryaPin, LOW);
    pinMode(configPin, HIGH);

  delay(500);
}
