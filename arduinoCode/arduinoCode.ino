
// Voegt de servo library toe
#include <Servo.h>. 

// Hier staan de echo en trig pin op vastgemaakt
const int trigPin = 10;
const int echoPin = 11;

// Variabelen voor de afstand en duur
long duration;
int distance;

Servo myServo; // Maakt een nieuw object van de servo motor aan om deze later in de code te gebruiken
void setup() {
  pinMode(trigPin, OUTPUT); // Zet de trigpin als output
  pinMode(echoPin, INPUT); // Zet de echopin als input
  Serial.begin(9600);
  myServo.attach(12); // Geeft aan op welke pin de motor zit gekoppeld
}
void loop() {
  // Roteerd de servo motor van 15 tot 165 graden
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();// Roept de functie aan die meet hoe ver een object van de afstandsmeter afstaat
  
  Serial.print(i); // Zet het huidige aantal graden in de seriele poort vast
  Serial.print(","); // Waarde later nodig in de code
  Serial.print(distance); // Stuurt de afstandwaarde naar de seriele poort
  Serial.print("."); // Waarde later nodig in de code
  }
  // Herhaalt de rotatie maar van andersom (van 165 tot 15) graden
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
// Functie voor het berekenen van de afstand die de afstandssensor opmeet
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Zet de trigpin in HIGH state voor 10 sec
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}
