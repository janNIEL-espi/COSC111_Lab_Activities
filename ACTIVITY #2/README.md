This laboratory activity focuses on understanding analog signals and their implementation in an Arduino circuit, including the 
conversion of analog to digital signals using the map() function. The objective is to create a running light effect where multiple 
LEDs gradually increase in brightness before turning off sequentially, producing a smooth transition. Building on the previous activity, 
this implementation requires using pins 8 to 12, with LEDs turning on sequentially from pin 12 to 8 and then turning off in the same 
order with a one-second delay. The brightness of the LEDs is controlled using the analogWrite() function, while a while() loop and an
array are utilized to set pin modes. To execute the project, LEDs must be connected to the designated pins, the code uploaded to the 
microcontroller, and upon running, the LEDs will display the intended gradual lighting effect.
