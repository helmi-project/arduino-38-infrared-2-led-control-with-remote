/*
   TUTORIAL IR REMOTE RECEIVER PADA ARDUINO
   TAMPILKAN KODE IR PADA SEVEN SEGMENT
   DAN ON OFF LED
   
   D4 -> Led Merah
   D2 -> IR
   D5 -> Led Hijau
   D6 -> Led Biru
   D7 -> Led Kuning
*/

#include <Wire.h>
#include <Arduino.h>
#include <TM1637Display.h>
#include "EcadioIRremote.h"

#define RECV_PIN 2//the SIG pin of Infrared Receiver is connected with D2 of OPEN-SMART UNO R3
#define CLK 10
#define DIO 11
#define merah 4
#define hijau 5
#define biru 6
#define kuning 7

IRrecv IR(RECV_PIN);
TM1637Display display(CLK, DIO);

void setup()
{
  Serial.begin(115200);
  IR.enableIRIn(); // memulai receiver
  display.setBrightness(0x0f);
  pinMode(merah, OUTPUT);
  pinMode(kuning,OUTPUT);
  pinMode(hijau,OUTPUT);
  pinMode(biru,OUTPUT);
}

void loop()
{
  if (IR.decode()) {//kalau ada kode yang valid

    if (IR.isReleased()) 
    {
      digitalWrite(merah, HIGH);
      Serial.print("key code is ");
      Serial.println(IR.keycode, DEC);
      display.showNumberDec(IR.keycode);
      Serial.println("*************");
      
    }
    digitalWrite(merah, LOW);
    if(IR.keycode==69){
      digitalWrite(kuning,HIGH);
    }
    if(IR.keycode==68){
      digitalWrite(kuning,LOW);
    }
    if(IR.keycode==70){
      digitalWrite(biru,HIGH);
    }
    if(IR.keycode==64){
      digitalWrite(biru,LOW);
    }
    if(IR.keycode==71){
      digitalWrite(hijau,HIGH);
    }
    if(IR.keycode==67){
      digitalWrite(hijau,LOW);
    }
    IR.resume(); //lanjutkan menerima sinyal IR lagi
  }
}
