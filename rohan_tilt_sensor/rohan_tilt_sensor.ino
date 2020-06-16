#define SENSOR_PIN 2
#define LED_PIN 13

void setup()
{

  pinMode(SENSOR_PIN, INPUT_PULLUP);


  pinMode(LED_PIN, OUTPUT);
}

void loop()
{

  if (digitalRead(SENSOR_PIN) == LOW)
  {
  
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
  
    digitalWrite(LED_PIN, LOW);
  }
}
