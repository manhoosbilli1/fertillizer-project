//TRANSMITTER

#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial s(3, 2);
String ptr;
int gas = 20.9454;
float h = 46;
float t = 87;
int motorStatus = 1;
int plantLength = 45;
int waterLevel = 1;

//functions
String encode(int gas, float h, float t, int motorStatus, int plantLength, int waterLevel)
{
  ptr = "@";
  ptr += String(gas);
  ptr += ',';
  ptr += String(h, 2);
  ptr += '!';
  ptr += String(t, 2);
  ptr += '#';
  ptr += String(motorStatus);
  ptr += '%';
  ptr += String(plantLength);
  ptr += '^';
  ptr += String(waterLevel);
  ptr += "$";
  return ptr;
}

void setup()
{
  // put your setup code here, to run once:
  s.begin(9600);

}

void loop()
{
  // put your main c  ode here, to run repeatedly:
  
  s.println(encode(gas, h, t, motorStatus, plantLength, waterLevel));
  delay(2000);
}
