#include <SoftwareSerial.h>
//com7
static const int RXPin = 4, TXPin = 5;
static const uint32_t remotebaud = 9600;


volatile unsigned long oldnow; //time at turnsignal 
volatile unsigned long newnow;
volatile unsigned long diff;
volatile uint16_t v;
byte serialdata[4];
  int lf = 10;

//The serial connection to the hc12
SoftwareSerial ss(RXPin, TXPin);


void setup() {

  analogReference(DEFAULT);
 
 Serial.begin(9600);
  ss.begin(remotebaud);


Serial.println("here starts");
  
}

void loop() {
  // put your main code here, to run repeatedly:

  
if (Serial.available() < 54) {

     // error

     return;

   }
 
   for (byte n = 0; n < 5; n++) {

      serialdata[n] = ss.read();

   }                                

 
 
    Serial.write(serialdata,sizeof(serialdata));
delay(8);








}



