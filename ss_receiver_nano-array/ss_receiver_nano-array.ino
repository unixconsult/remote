#include <SoftwareSerial.h>
#include <Servo.h>
//com6
Servo myservo;  // create servo object to control a servo

static const int RXPin = 4, TXPin = 5;
static const uint32_t remotebaud = 9600;


char tgarray[3] ;
//The serial connection to the hc12
SoftwareSerial ss(RXPin, TXPin);


void setup() {
  // put your setup code here, to run once:

 myservo.attach(9);  // attaches the servo on pin 9 to the servo object
 Serial.begin(9600);
  ss.begin(remotebaud);
 Serial.begin(9600);


  
}

void loop() {
  // put your main code here, to run repeatedly:
 if (ss.available()) {
 ss.readBytes(tgarray, 4);
    //myservo.write(sv );
      Serial.write(tgarray,4);
      
  }

  


}
