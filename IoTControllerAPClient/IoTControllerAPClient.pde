
// IoTControllerAP Processing Client
// Version 1.0 (ɔ) 2020  Jose David Cuartas, GPL v.3
// Hiteclab, http://hiteclab.libertadores.edu.co/
// Fundación Universitaria Los Libertadores, Colombia

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

int ESPread;

void draw(){
}

// Presione el mouse para ejecutar el comando
void mousePressed(){
//ESPread = int(loadStrings("http://192.168.4.1/?EAPIN=0")[0]); // entrada analógica
//ESPread = int(loadStrings("http://192.168.4.1/?EDPIN=0")[0]); // entrada digital
//println(ESPread);

//loadStrings("http://192.168.4.1/?SMPIN=0&ANGLE=0"); // servo motor

loadStrings("http://192.168.4.1/?SDPIN=13&STATE=1"); // salida digital


}

void keyPressed(){
loadStrings("http://192.168.4.1/?SDPIN=13&STATE=0"); // salida digital

}
