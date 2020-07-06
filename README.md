# IoTControllerAP V.1.0

Free software to control ESP8266 mudule using a client writen in Processing language.

Version 1.0 (ɔ) 2020  Jose David Cuartas, GPL v.3
Hiteclab, http://hiteclab.libertadores.edu.co/
Fundación Universitaria Los Libertadores, Colombia

To use send messages to the ip address: http://192.168.4.1 like this

http://192.168.4.1/?EAPIN=x 
Analogic input - Entrada Analógica
x is the pin number

http://192.168.4.1/?EDPIN=x
Digital input - Entrada Digital
x is the pin number

http://192.168.4.1/?SMPIN=x&ANGLE=a
Servo Motor
x is the pin number
a is the angle

http://192.168.4.1/?SDPIN=x&STATE=s
Digital Input - Salida Digital
x is the pin number
s is the state, use the value: 1 to turn ON the pin 
s is the state, use the value: 0 turn OFF the pin 

