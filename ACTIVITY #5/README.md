This laboratory activity involves establishing a serial communication interface between a FastAPI backend and an Arduino to remotely control 
an LED via HTTP requests. The FastAPI server transmits commands to the Arduino, enabling users to turn the LED on and off through 
API endpoints (`/led/on` and `/led/off`). The objective is to implement real-time interaction between a web server and physical hardware. 
To set up the hardware, an LED must be connected to pin 11 of the Arduino with a current-limiting resistor, and the board should be linked 
to the computer via USB. The software setup requires installing FastAPI and PySerial (`pip install fastapi uvicorn pyserial`), ensuring the 
Arduino is recognized by the system, and uploading the corresponding Arduino sketch using the Arduino IDE.
