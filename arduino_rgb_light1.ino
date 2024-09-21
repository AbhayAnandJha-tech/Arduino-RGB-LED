const int buttonPin = 2;
const int redPin = 5;
const int greenPin = 6;
const int bluePin = 4;

int ledState = 0;
bool buttonPressed = false;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  updateLED();
}

void loop() {
  byte buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && !buttonPressed) {
    Serial.println("Button is pressed");
    buttonPressed = true;
    ledState = (ledState + 1) % 3; // Cycle through 0, 1, 2
    updateLED();
    delay(200); // Debounce delay
  } else if (buttonState == HIGH) {
    Serial.println("Button is not pressed");
    buttonPressed = false;
  }
}


void updateLED() {
  if (ledState == 0) {
    // Red
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  } else if (ledState == 1) {
    // Green
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  } else if (ledState == 2) {
    // Blue
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  }
}