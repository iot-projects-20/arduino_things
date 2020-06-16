const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
const int redLight = 2;
const int yellowLight = 4;
const int buzzer = 8;

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(redLight, OUTPUT);
   pinMode(yellowLight, OUTPUT);
   pinMode(buzzer, OUTPUT);
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);

   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.println(cm);
   if (cm < 20) {
    digitalWrite(yellowLight, LOW);
    digitalWrite(redLight, HIGH);
    tone(buzzer, 1000);
    delay(1000);        // ...for 1 sec
          Serial.println("Kavi you are close to 10 cm");

   } else {
    noTone(buzzer);     // Stop sound...
    digitalWrite(redLight, LOW);
    digitalWrite(yellowLight, HIGH);
         Serial.println("Kavi you are away from 10 cm");
         delay(1000);  

   }
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
