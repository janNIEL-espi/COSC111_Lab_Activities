This final laboratory activity focuses on developing a system that detects button presses using an Arduino and communicates the button state 
to a Python script, which then triggers an API to control an LED. Additionally, the project involves establishing a connection between two 
devices using Wi-Fi or a hotspot, where one device runs the Arduino code for the button, and the other, connected via the network, controls 
an LED on a breadboard. The Arduino code configures a button on pin 12, reads its state, and transmits the data via serial communication. 
The Python script establishes a serial connection, processes the button state, and calls an API to turn the LED on or off accordingly. To 
implement the system, the button must be connected to the designated Arduino pin, the Arduino code uploaded, and the Python script executed. 
When the button is pressed, the Python script communicates with the API, enabling remote LED control.
