/*
---- Receiver Code ----
Mert Arduino Tutorial & Projects (YouTube)
Please Subscribe for Support
*/

#include <Servo.h>    //the library which helps us to control the servo motor
#include <SPI.h>      //the communication interface with the modem
#include "RF24.h"     //the library which helps us to control the radio modem

//define the servo name
Servo myServo1;
Servo myServo3;
Servo myServo4;
Servo myServo2;
Servo myServo5;

RF24 radio(5,10);     /*This object represents a modem connected to the Arduino. 
                      Arguments 5 and 10 are a digital pin numbers to which signals 
                      CE and CSN are connected.*/

const uint64_t pipe = 0xE8E8F0F0E1LL; //the address of the modem,that will receive data from the Arduino.

int msg[1];

int data; //data variable
int pos; //position variable

void setup(){

  //define the servo input pins
  myServo1.attach(15); //A1
  myServo3.attach(16); //A2
  myServo4.attach(17); //A3
  myServo2.attach(18); //A4
  myServo5.attach(19); //A5
  
  radio.begin();                    //it activates the modem.
  radio.openReadingPipe(1, pipe);   //determines the address of our modem which receive data.
  radio.startListening();           //enable receiving data via modem
  }


//You don't need to make changes in this section
void loop(){
  if(radio.available()){
    radio.read(msg, 1);

    if(msg[0] <11 && msg[0] >-1){
      data = msg[0], pos=map(data, 0, 10, 175, 0);
      myServo1.write(pos); 
    }
    if(msg[0] <21 && msg[0]>10){
      data = msg[0], pos=map(data, 11, 20, 175, 0);
      myServo3.write(pos);
    }
    if(msg[0] <31 && msg[0]>20){
      data = msg[0], pos=map(data, 21, 30, 175, 0);
      myServo4.write(pos);
    }
    if(msg[0] <41 && msg[0]>30){
      data = msg[0], pos=map(data, 31, 40, 175, 0);
      myServo2.write(pos);
    }
    if(msg[0] <51 && msg[0]>40){
      data = msg[0], pos=map(data, 41, 50, 175, 0);
      myServo5.write(pos);
    }
  }
}
