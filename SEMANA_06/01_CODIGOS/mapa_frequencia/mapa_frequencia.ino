/**************
 * Include Libraries
 **************/
#include "UbidotsEsp32Mqtt.h"
#include <WiFi.h>
#include "PubSubClient.h"
/**************
 * Define Constants
 **************/
const char *UBIDOTS_TOKEN = "BBFF-NN0joLZJJ1mzKgpf5fHcxKMYM5kxTh";
const char *WIFI_SSID = "Inteli-COLLEGE";  // Put here your Wi-Fi SSID
const char *WIFI_PASS = "QazWsx@123";      // Put here your Wi-Fi password
const char *DEVICE_LABEL = "Duda";         // Replace with the device label to subscribe to
const char *VARIABLE_LABEL = "Potencia";   // Replace with your variable label to subscribe to
const char *VARIABLE_LABEL2 = "LED";       //Teste com o LED!!!!!!!! PS: Não deu certo hahaha
const uint8_t LED = 32;                    // Pin used to write data based on 1's and 0's coming from Ubidots
const int PUBLISH_FREQUENCY = 1000;        // Update rate in milliseconds
unsigned long timer;
Ubidots ubidots(UBIDOTS_TOKEN);
/**************
 * Auxiliar Functions
 **************/
void callback(char *topic, byte *payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    if ((char)payload[0] == '1') {
      digitalWrite(LED, HIGH);
    } else {
      digitalWrite(LED, LOW);
    }
  }
  Serial.println();
}
/**************
 * Main Functions
 **************/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  ubidots.setDebug(true);  // uncomment this to make debug messages available
  ubidots.connectToWifi(WIFI_SSID, WIFI_PASS);
  ubidots.setCallback(callback);
  ubidots.setup();
  ubidots.reconnect();
  ubidots.subscribeLastValue(DEVICE_LABEL, VARIABLE_LABEL);
}
void loop() {
  int potencia = WiFi.RSSI();
  // put your main code here, to run repeatedly:
  if (millis() - timer > PUBLISH_FREQUENCY) {
    ubidots.add(VARIABLE_LABEL, potencia);  // Insira variável e dispositivo a serem publicados
    ubidots.publish(DEVICE_LABEL);

    ubidots.add(VARIABLE_LABEL2, 32);  // Insira variável e dispositivo a serem publicados
    ubidots.publish(DEVICE_LABEL);

    timer = millis();
  }
  if (!ubidots.connected()) {
    ubidots.reconnect();
    ubidots.subscribeLastValue(DEVICE_LABEL, VARIABLE_LABEL);
  }
  ubidots.loop();
}
