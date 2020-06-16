#include <Servo.h>

Servo myservo;  // create servo object to control a servo

const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
const int redLight = 2;
const int yellowLight = 4;
const int servoPin = 8;

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(redLight, OUTPUT);
   pinMode(yellowLight, OUTPUT);
//   pinMode(buzzer, OUTPUT);
    myservo.attach(servoPin);  // attaches the servo on GIO2 to the servo object
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
   int pos;
   if (cm < 20) {
    digitalWrite(yellowLight, LOW);
    digitalWrite(redLight, HIGH);
    // now rotate servo motor
    
    for (pos = 10; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(8);                       // waits 15ms for the servo to reach the position
    }
      
    delay(10000);        // ...for 1 sec
          Serial.println("Kavi you are close to 10 cm");
    for (pos = 180; pos >= 10; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(10);                       // waits 15ms for the servo to reach the position
    }
   } else {
//    noTone(buzzer);     // Stop sound...
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
