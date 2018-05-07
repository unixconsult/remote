#include <SoftwareSerial.h>

//com6


static const int RXPin = 4, TXPin = 5;
static const uint32_t remotebaud = 9600;
float tgfloat[3];
byte tgarray[3] ;
byte bytearray[12];

SoftwareSerial ss(RXPin, TXPin);


void setup() {
  // put your setup code here, to run once:

 //myservo.attach(9);  // attaches the servo on pin 9 to the servo object
 Serial.begin(9600);
ss.begin(remotebaud);
Serial.println("serial begins");

}

void loop() {
  
      
      


if (ss.available()>11) {
 ss.readBytes(bytearray, sizeof bytearray);
    //myservo.write(sv );
      //Serial.write(tgarray,3);
       memcpy( tgfloat, bytearray,sizeof tgfloat);
Serial.println(sizeof(tgfloat));
Serial.println(tgfloat[0]);
Serial.println(tgfloat[1]);
Serial.println(tgfloat[2]);
      
  }

  






 
}
