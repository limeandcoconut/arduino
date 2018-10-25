#include <RH_ASK.h>
#include <SPI.h>
RH_ASK driver(1000, 11, 12, 10);

void setup() {
  Serial.begin(9600);
  
  if (!driver.init()) {
    Serial.println("failed");
  }
  Serial.println("test setup");
}

void loop() {
    const char *msg = "Hello World!";
    Serial.println("test transmit");
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);
}
