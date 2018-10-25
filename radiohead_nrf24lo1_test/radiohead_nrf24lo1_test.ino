#include <SPI.h>
#include <RH_NRF24.h>

RH_NRF24 nrf24;

const int buttonPin = 2;
const int ledPin = 3;

//String divider;
int buttonState = 1;
int oldButtonState = buttonState;
int ledState = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);

  if (!nrf24.init()) {
    Serial.println("init failed");
  } 
  // Defaults after init are 2.402 GHz (channel 2), 2Mbps, 0dBm
  if (!nrf24.setChannel(1)) {
    Serial.println("setChannel failed");
  } 
  if (!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm)) {
    Serial.println("setRF failed");
  } 
  Serial.println("Initialized");
}

void loop()
{

  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && oldButtonState == LOW) {
    ledState = 1 - ledState;
//    digitalWrite(ledPin, ledState);
//      char *intStr = itoa(ledState);

        String state = String(ledState);
        char stateChar[2];
        state.toCharArray(stateChar, 2);

        

     uint8_t data[2];
     data[2] = stateChar;
//      uint8_t data[2];
//      uint16_t i = *( uint16_t* ) data;
     uint8_t len = sizeof(data);
//     Serial.println(data);
     Serial.write(data, len); 

     digitalWrite(ledPin, ledState);
     
//    data[0] = (ledState >> 24) & 0xFF;
//    data[1] = (ledState >> 16) & 0xFF;
//    data[0] = (ledState >> 8) & 0xFF;
//    data[1] = ledState & 0xFF;

    nrf24.send(data, sizeof(data));
    nrf24.waitPacketSent();
    Serial.println("sent");
  }

  oldButtonState = buttonState; 

  delay(30);
  
//  if (!digitalRead(buttonPin)) {
//    //button is pressed, message should be sent, turn the green LED on
//    Serial.println("btn");
//   // Send a message
//    uint8_t data[] = "1";
//    nrf24.send(data, sizeof(data));
//    nrf24.waitPacketSent();
//    Serial.println("sent");
//    toggleLed();
//  }    
}


