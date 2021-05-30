#define NUMREADINGS 50 // Raise number to increase data smoothing

int senseLimit = 50; // Raise number to decrease sensitivity of the antenna (up to 1023 max)

int probePin = 5; // Set analog pin 5 as the antenna pin
int val = 0; // Reading from probePin

int LED1 = 11;
int LED2 = 10;
int LED3 = 9;
int LED4 = 8;
int LED5 = 7;
int LED6 = 6;
int LED7 = 5;
int LED8 = 4;
int LED9 = 3;
int LED10 = 2;

int readings[NUMREADINGS]; // Readings from the analog input
int index = 0; // Index of the current reading
int total = 0;
int average = 0;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);

  for (int i = 0; i < NUMREADINGS; i++)
    readings[i] = 0;
}

void loop() {
  val = analogRead(probePin); // Take a reading from probe
  if (val >= 1) { // If the reading isn't zero, proceed
    val = constrain(val, 1, senseLimit); // If the reading is
    // higher than the current
    // senseLimit value, update
    // senseLimit value with
    // higher reading
    val = map(val, 1, senseLimit, 1, 1023); // Remap the constrained value within a 1 to 1023 range
    total -= readings[index]; // Subtract the last reading
    readings[index] = val; // Read from the sensor
    total += readings[index]; // Add the reading to the total
    index = (index + 1); // Advance to the next index
    if (index >= NUMREADINGS) // If we're at the end of the array
      index = 0; // loop around to the beginning
    average = total / NUMREADINGS; // Calculate the average reading
    if (average > 10) { // If the average reading is higher than 50
      digitalWrite(LED1, HIGH); // turn on the first LED
    }
    else { // If it's not
      digitalWrite(LED1, LOW); // turn off that LED
    }
    if (average > 15) { // And so on
      digitalWrite(LED2, HIGH);
    }
    else {
      digitalWrite(LED2, LOW);
    }
    if (average > 20) {
      digitalWrite(LED3, HIGH);
    }
    else {
      digitalWrite(LED3, LOW);
    }
    if (average > 30) {
      digitalWrite(LED4, HIGH);
    }
    else {
      digitalWrite(LED4, LOW);
    }
    if (average > 40) {
      digitalWrite(LED5, HIGH);
    }
    else {
      digitalWrite(LED5, LOW);
    }

    if (average > 50) {
      digitalWrite(LED6, HIGH);
    }
    else {
      digitalWrite(LED6, LOW);
    }
    if (average > 60) {
      digitalWrite(LED7, HIGH);
    }
    else {
      digitalWrite(LED7, LOW);
    }
    if (average > 70) {
      digitalWrite(LED8, HIGH);
    }
    else {
      digitalWrite(LED8, LOW);
    }
    if (average > 80) {
      digitalWrite(LED9, HIGH);
    }
    else {
      digitalWrite(LED9, LOW);
    }
    if (average > 90) {
      digitalWrite(LED10, HIGH);
    }
    else {
      digitalWrite(LED10, LOW);
    }
    Serial.println(val); 
  }
}
