#include <String.h> 
#include <SoftwareSerial.h>
SoftwareSerial SIM900(7,8);// RX, TX recorder que se cruzan

void setup() {

  //inicializamos el modulo y el puerto serial a 19200 baudios
  
  SIM900.begin(19200); 
  Serial.begin(19200); 
  delay(1000); 
}

void loop() {

    if(Serial.available()){
      switch(Serial.read()){
        
        case 's': 
          Envio_de_mensaje1();
          break;
        case 'n': 
          Envio_de_mensaje2();
          break;
        case 'p': 
          Envio_de_mensaje3();
          break;
        case 'm': 
          llamada(); 
        }
      }
     if (SIM900.available()){
      Serial.write(SIM900.read());
      }
}

void Envio_de_mensaje1(){

    SIM900.print("AT+CMGF=1\r"); // configuramos el modulo para el envio de mensajes
    delay(100); 
    SIM900.println("AT+CMGS=\"+51XXXXXXXXX\""); //colocamos el numero y el codigo postal peru(+51) 
    delay(100); 
    SIM900.println("HOLA MUNDO, PRIMER MENSAJE DE PRUEBA"); //eSCRIBIMOS EL MENSAJE
    delay(100); 
    SIM900.println((char)26); // Terminamos el mensaje con ctrl +z ((char(26))
    SIM900.println();
  }
void Envio_de_mensaje2(){

    SIM900.print("AT+CMGF=1\r"); 
    delay(100); 
    SIM900.println("AT+CMGS=\"+51XXXXXXXXX\""); 
    delay(100); 
    SIM900.println("Ingenieria Electronica y Telecomunicaciones");
    delay(100); 
    SIM900.println((char)26);
    SIM900.println();
  }
void Envio_de_mensaje3(){

    SIM900.print("AT+CMGF=1\r"); 
    delay(100); 
    SIM900.println("AT+CMGS =\"+51XXXXXXXXX\""); 
    delay(100); 
    SIM900.println("Universidad Nacional de Piura-Peru");
    delay(100); 
    SIM900.println((char)26);
    SIM900.println();
  }

void llamada(){
  SIM900.println("ATD + +51XXXXXXXXX;"); //Comando para hacer llamadas
  delay(100); 
  SIM900.println();
  }


