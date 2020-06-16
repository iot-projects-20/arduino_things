int resval = 0;

int h20 = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(h20, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

   resval = analogRead(h20);

 Serial.println(resval);
 

  if(resval <= 100) {
    Serial.println("Water level : Empty");
  }
  else if(resval <= 500 && resval >= 300 ) {
    Serial.println("Water level : Medium");
  }
  else if(resval > 600) {
    Serial.println("Water level : High");
  }
  delay(1000);
  
}
