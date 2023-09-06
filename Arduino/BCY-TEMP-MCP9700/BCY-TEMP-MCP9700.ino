/*
DESCRIPTION:
This example code for BCY-TEMP-MCP9700 tested on Arduino UNO.
This code applicable to other microcontroller analog pin.

AUTHOR  : Cytron Technologies Sdn Bhd
WEBSITE  : www.cytron.io
EMAIL    : support@cytron.io

REFERRENCE:
BCY-TEMP-MCP9700 Datasheet:
https://docs.google.com/document/d/1Yg4krOVZN__Q0NPKvb4om0IJVZMJksBEIjuhJPlcBTM/edit?usp=sharing
*/

// set  pin numbers:
const int vout_pin = A0;            // input for reading the sensor  output

// set constants:
const float vout0 = 500;   //  sensor output  voltage in mV at 0°C for the  MCP9700/A
const float tc = 10; // 10 mV for °C temperature constant  for the  MCP9700/A

// variables:
float vout, vout_raw, ta;

void setup() {
  Serial.begin(9600);
  pinMode(vout_pin, INPUT); // set pin in as input
}

void loop() {
  vout_raw = analogRead(vout_pin);
  vout = (vout_raw * 5 * 1000) / 1023; //convert raw ADC 10-bit input value to mV
  ta = (vout - vout0) / tc; //calculate the ambient temperature

  Serial.print("Ambient temperature =  " );
  Serial.print(ta);
  Serial.println(" °C" );
  delay (1000);
}