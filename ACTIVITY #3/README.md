This laboratory activity involves developing an Arduino-based system that monitors temperature and ambient light levels using a 
temperature sensor and a photoresistor. If both the temperature and brightness exceed predefined thresholds, the system activates 
a fire warning by rapidly blinking an LED. The program continuously reads sensor data, displays real-time values on the serial monitor, 
and evaluates conditions to determine when to trigger the LED indicator. To implement this system, a temperature sensor must be 
connected to A0, a photoresistor to A2, and an LED to pin 12 with a suitable resistor. The Arduino IDE is used to upload the code, 
and upon execution, the serial monitor displays sensor readings. If the detected values surpass the set limits, the LED blinks rapidly as a fire alert.
