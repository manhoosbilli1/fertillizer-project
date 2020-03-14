//RECEIVER
#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial s(2,3);
String command,gas,t,h,mS,pL,wL;

//functions 
void decode(String command)
{
  gas= command.substring(command.indexOf('@')+1,command.indexOf(','));
  h  = command.substring(command.indexOf(',')+1,command.indexOf('!'));
  t  = command.substring(command.indexOf("!")+1,command.indexOf("#"));
  mS = command.substring(command.indexOf('#')+1,command.indexOf('%'));
  pL = command.substring(command.indexOf('%')+1,command.indexOf('^'));
  wL = command.substring(command.indexOf('^')+1,command.indexOf('$'));
}

//---------

void setup() {
  // put your setup code here, to run once:
s.begin(9600);
Serial.begin(9600);
Serial.print("Arduino start com4");
}

void loop(){
  // put your main code here, to run repeatedly:
  while(s.available())
  {
    command =  s.readString();
    Serial.println(command);
    decode(command);
    Serial.print(gas);
    Serial.print(',');
    Serial.print(h);
    Serial.print(',');
    Serial.print(t);
    Serial.print(',');
    Serial.print(mS);
    Serial.print(',');
    Serial.print(pL);
    Serial.print(',');
    Serial.println(wL);
  }
}

