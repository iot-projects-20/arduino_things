int sensor = 13;  // Digital pin D7
int light = 12;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(light, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  long state = digitalRead(sensor);
  if (state == HIGH) {
    Serial.println("Motion detected!");
    digitalWrite(light, HIGH);

    delay(10000);
     digitalWrite(light, LOW);

  }
  else {
    //Serial.println("No motion detected.");
    digitalWrite(light, LOW);
    delay(500);
  }
}
