#define BLYNK_TEMPLATE_ID "TMPL63FKyFho9"
#define BLYNK_TEMPLATE_NAME "GIAM SAT PHONG LANH"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial

#include "BlynkEdgent.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS D2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
#define USE_NODE_MCU_BOARD

#define APP_DEBUG

void setup() {
  Serial.begin(115200);
  BlynkEdgent.begin();

  sensors.begin();
}

void loop() {
  BlynkEdgent.run();
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  if (tempC != DEVICE_DISCONNECTED_C) {
    Blynk.virtualWrite(V0, tempC);
    Serial.print("Temperature: ");
    Serial.println(tempC);
  }
  
  delay(100);
}
