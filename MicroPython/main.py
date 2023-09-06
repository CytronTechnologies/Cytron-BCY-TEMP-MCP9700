"""
DESCRIPTION:
This example code for BCY-TEMP-MCP9700 tested on Raspbery Pi Pico using MicroPython.
This code applicable to other microcontroller analog pin.

AUTHOR  : Cytron Technologies Sdn Bhd
WEBSITE  : www.cytron.io
EMAIL    : support@cytron.io

REFERRENCE:
BCY-TEMP-MCP9700 Datasheet:
https://docs.google.com/document/d/1Yg4krOVZN__Q0NPKvb4om0IJVZMJksBEIjuhJPlcBTM/edit?usp=sharing
"""
#Import necessary libraries
import machine
import time

vout0 =  500   # sensor output  voltage in mV at 0°C for the  MCP9700/A
tc = 10        # 10 mV for °C temperature constant  for the  MCP9700/A

#Define analog pin GP28 used on the board
sensor = machine.ADC(28)

while True:
    
    vout_raw = sensor.read_u16()
    vout = (vout_raw * 3.3 * 1000) / 65536 #convert raw ADC 10-bit input value to mV
    
    ta = (vout - vout0) / tc; #calculate the ambient temperature
    
    #Serial print the sensor value every 1 second
    print('Ambient temperature =  {:.2f} °C'.format(ta))
    print('--------------------------------')
    time.sleep(1)
