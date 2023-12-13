#include <DallasTemperature.h>

#include <OneWire.h>

#define ONE_WIRE_BUS 5

OneWire onewire(ONE_WIRE_BUS);
DallasTemperature sensors(&onewire);

void setup() 
{
  Serial.begin(9600);
  Serial.println("dallas temperature IC control Librery Demo");

  sensors.begin();
}

void loop()
 {
  Serial.println("buscando temperaturas...");
  sensors.requestTemperatures();
  Serial.println("hecho");
  float tempC = sensors.getTempCByIndex(0);

  if (tempC != DEVICE_DISCONNECTED_C)
  {
    Serial.print("temperature for the device 1 (index 0) is: ");
    Serial.println(tempC);
  }
  else
  {
    Serial.println("error: could not read temperature data");
  }
  
}
