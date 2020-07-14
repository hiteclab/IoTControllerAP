
// IoTControllerAP (Access Point)
// Version 1.0 (ɔ) 2020  Jose David Cuartas, GPL v.3
// Hiteclab, http://hiteclab.libertadores.edu.co/
// Fundación Universitaria Los Libertadores, Colombia
// Creado usando:
// Arduino IDE 1.8.3
// Start Arduino and open the Preferences window.
// Enter https://arduino.esp8266.com/stable/package_esp8266com_index.json into the Additional Board Manager URLs field.
// Driver: esp8266 versión 2.7.1 (Tools -> Board -> Boards Manager)

// To use send messages to the ip address: http://192.168.4.1 like this

// http://192.168.4.1/?EAPIN=x 
// Analogic input - Entrada Analógica
// x is the pin number

// http://192.168.4.1/?EDPIN=x
// Digital input - Entrada Digital
// x is the pin number

// http://192.168.4.1/?SMPIN=x&ANGLE=a
// Servo Motor
// x is the pin number
// a is the angle

// http://192.168.4.1/?SDPIN=x&STATE=s
// Digital Output - Salida Digital
// x is the pin number
// s is the state, use the value: 1 to turn ON the pin 
// s is the state, use the value: 0 turn OFF the pin 

#include <Servo.h>
#include <ESP8266WebServer.h>

Servo servomotor;  // variable para controar el servomotor
ESP8266WebServer iotcontroller(80); // ESP8266WebServer


const char *router = "IoT_Controller"; // Nombre del Access Point para establecer la conexio WiFi con la tarjeta ESP
//const char *pw = "12345678"; // Descomentar si se quiere usar password y descomentar la línea WiFi.softAP(router, pw);
String data;
int pin;
int angle;



void iotcommands() {

  // Salida digital
  if (iotcontroller.hasArg("SDPIN")){ 
      pin = iotcontroller.arg("SDPIN").toInt(); // lee el pin del argumento
      
      if (iotcontroller.hasArg("STATE")) {  // salida digital segun el argumento STATE
        if (iotcontroller.arg("STATE")== "1"){ 
          pinMode(pin, OUTPUT);
          digitalWrite(pin, LOW); 
          }
        if (iotcontroller.arg("STATE")== "0"){ 
          pinMode(pin, OUTPUT);
          digitalWrite(pin, HIGH); 
          }
      }
      iotcontroller.send(200, " ");
  }
  
  // Entrada digital
  if (iotcontroller.hasArg("EDPIN")){
    pin = iotcontroller.arg("EDPIN").toInt(); // lee el pin del argumento
    pinMode(pin, INPUT_PULLUP);
    data = 1-digitalRead(pin);
    iotcontroller.send(200, "text/plain", data);
  } 

  // Entrada analógica
  if (iotcontroller.hasArg("EAPIN")){
    pin = iotcontroller.arg("EAPIN").toInt(); // lee el pin del argumento
    pinMode(pin, INPUT);
    data = analogRead(pin);
    iotcontroller.send(200, "text/plain", data);
  }
  
  // Servo Motor
  if (iotcontroller.hasArg("SMPIN")){ 
    pin = iotcontroller.arg("SMPIN").toInt(); // lee el pin del argumento
    angle = iotcontroller.arg("ANGLE").toInt();
    servomotor.attach(pin);
    servomotor.write(angle);
    iotcontroller.send(200, " ");
  }

} // iotcommands


void setup() {
	
	delay(1000);

	//WiFi.softAP(router, pw); // usar esta opción si se quiere una conexion con password
  WiFi.softAP(router);

	iotcontroller.on("/", iotcommands);
	iotcontroller.begin();  
  
}

void loop() {
	iotcontroller.handleClient();
}
