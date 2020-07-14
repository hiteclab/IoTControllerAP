# IoTControllerAP V.1.0

Free software to control ESP8266 mudule using a client writen in Processing language.

Version 1.0 (ɔ) 2020  Jose David Cuartas, GPL v.3
Hiteclab, http://hiteclab.libertadores.edu.co/
Fundación Universitaria Los Libertadores, Colombia

Created using:
Arduino IDE 1.8.3

# Prerequisites:

Install the ESP board support to arduino.
Start Arduino and open the Preferences window.
Enter https://arduino.esp8266.com/stable/package_esp8266com_index.json into the Additional Board Manager URLs field.
Select **esp8266** versión 2.7.1  in Tools -> Board -> Boards Manager

# Install

open the **IoTControllerAP.ino** file in arduino and upload it to your ESP board. 

# How to use:

You can use the Processing IoTControllerAPClient or you can use your web browser like this:

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
Digital Output - Salida Digital
x is the pin number
s is the state, use the value: 1 to turn ON the pin 
s is the state, use the value: 0 turn OFF the pin 

