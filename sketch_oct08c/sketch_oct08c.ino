const int buttonPin = 2;

int buttonState = 1;
int oldButtonState = buttonState;
int ledState = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && oldButtonState == LOW) {
    ledState = 1 - ledState;
    digitalWrite(LED_BUILTIN, ledState); 
  }

  oldButtonState = buttonState; 

  delay(30);
}
