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
   if (cm < 10) {
    digitalWrite(yellowLight, LOW);
    digitalWrite(redLight, HIGH);
    //tone(buzzer, 1000);
    //playMelody();
    delay(1000);        // ...for 1 sec
          Serial.println("Kavi you are close to 10 cm");

   } else {
   // noTone(buzzer);     // Stop sound...
    digitalWrite(redLight, LOW);
    digitalWrite(yellowLight, HIGH);
         Serial.println("Kavi you are away from 10 cm");

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

void playMelody() {
  
  int melody[] = {"NOTE_C4", "NOTE_G3", "NOTE_G3", "NOTE_A3", "NOTE_G3", "0", "NOTE_B3", "NOTE_C4" };
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);  // where 8 is pin
    // tone(pin, frequency, duration)


    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}
