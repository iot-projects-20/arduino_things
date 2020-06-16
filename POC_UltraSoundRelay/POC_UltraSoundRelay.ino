const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
const int redLight = 2;



void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(redLight, OUTPUT);
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

//   Serial.println("distance is : " + cm);
   if (cm > 150) {
    Serial.println("Kavi you are close to 50 cm");
    digitalWrite(redLight, HIGH);
    
    if (cm < 5){
     digitalWrite(redLight, LOW);
     Serial.println("Kavi you are close to 5 cm");
     delay(1000); 


   } 
    delay(1000); 
   }
    else {
     digitalWrite(redLight, LOW);

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
