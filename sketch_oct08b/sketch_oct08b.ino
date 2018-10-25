const int buttonPin = 2;
const int ledPin = 3;

int buttonState = 1;
int oldButtonState = buttonState;
int ledState = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && oldButtonState == LOW) {
    ledState = 1 - ledState;
    digitalWrite(ledPin, ledState); 
  }

  oldButtonState = buttonState; 

  delay(30);
}
