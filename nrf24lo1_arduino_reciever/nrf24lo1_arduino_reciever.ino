#include <SPI.h>
#include <RH_NRF24.h>

RH_NRF24 nrf24;

//String divider;

const int buttonPin = 2;
const int ledPin = 3;

//String divider;
int buttonState = 1;
int oldButtonState = buttonState;
int ledState = 0;

void setup() {
//  pinMode(LED_BUILTIN, OUTPUT);
pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Hello World");

  if (!nrf24.init()) {
    Serial.println("init failed");
  }
  Serial.println("Initialized");
  // Defaults after init are 2.402 GHz (channel 2), 2Mbps, 0dBm
  if (!nrf24.setChannel(1)) {
    Serial.println("setChannel failed");
  }
  Serial.println("Set Channel");
  if (!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm)) {
    Serial.println("setRF failed");
  }
  Serial.println("Set Rf");
}

void loop() {

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && oldButtonState == LOW) {
    toggleLed();
  }

  oldButtonState = buttonState; 

//  delay(30);
  
  uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];
  uint8_t len = sizeof(buf);

  if (nrf24.waitAvailableTimeout(300)) { 
    if (nrf24.recv(buf, &len)) {
//      divider += "=";
//      Serial.print(divider + "\n");
////      Serial.println((char*)buf);
Serial.write(buf, len);  
toggleLed(); 

//      if (divider.length() > 5) {
//        divider = "";
//      }
    } else {
      Serial.println("recv failed");
    }
  }
}

void toggleLed() {
  ledState = 1 - ledState;
  digitalWrite(ledPin, ledState); 
}

