#define trigPin 7
#define echoPin 8

#define greenLedPin 5
#define redLedPin 3

#define buzzPin 2


// defines variables

long duration;

void setup() {
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  Serial.begin(9600); // Starts the serial communication 38400
}

void loop() {
 BeepAndLight();
}

void BeepAndLight(){
  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, LOW);

  printDistance();

  if (calculateDistance() > 30) {
    SetLedGreenAndBeep();
  }
  if (calculateDistance() >= 15 && calculateDistance() <= 30) {
    SetLedYellowAndBeep();
  }
  if (calculateDistance() < 15) {
    SetLedRedAndBeep();
  }
  
  delay(200);
}

void printDistance() {
  Serial.print("Distance: ");
  Serial.print(calculateDistance());
  Serial.println(" cm");
}

int calculateDistance() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Prints the distance on the Serial Monitor
  //Serial.print("Distance: ");
  //Serial.println(distance);
  return duration * 0.034 / 2;
}

void SetLedGreenAndBeep() {
  buzOnGreen();
}

void SetLedRedAndBeep() {
  buzOnRed();
}

void SetLedYellowAndBeep() {
  buzOnYellow();
}

void buzOnGreen() {
  //tone(buzzPin, 255);
  //delay(100);
  noTone(buzzPin);
  analogWrite(greenLedPin, 255);
  delay(900);

}

void buzOnYellow() {
  tone(buzzPin, 255);
  delay(100);
  noTone(buzzPin);
  analogWrite(redLedPin, 150);
  analogWrite(greenLedPin, 255);
  delay(600);

}

void buzOnRed() {
  tone(buzzPin, 255);
  delay(100);
  noTone(buzzPin);
  analogWrite(redLedPin, 255);
  delay(300);
}
