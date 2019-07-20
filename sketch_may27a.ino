const int pingPin = 6; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 7; // Echo Pin of Ultrasonic Sensor
#include <Servo.h> 

void setup() {
   Serial.begin(9600); // Starting Serial Terminal

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

void walk(Servo l_ankle, Servo r_ankle, Servo l_hip, Servo r_hip){ 
  l_ankle.write(180);
  delay(1000);
  delay(500);
  l_ankle.write(90);
  delay(500);

  r_ankle.write(180);
  delay(500);
  delay(500);
  r_ankle.write(90);
 
  
  
}

