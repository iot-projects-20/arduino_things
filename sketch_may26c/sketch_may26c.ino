void setup() {
  Serial.begin(9600);
}

void loop() {
  int thisValue = 55;
  int thatValue = 50;
  
  if (thisValue != thatValue)
   {
     Serial.println("Correct");
   } 
   else {
    Serial.println("Incorrect");
   }

   delay(100000);
   
}
