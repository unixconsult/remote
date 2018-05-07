#include <SoftwareSerial.h>
//com7
static const int RXPin = 4, TXPin = 5;
static const uint32_t remotebaud = 9600;

const byte turnleftPin = 2;
const byte turnrightPin = 3;
const byte ledpin = 13;
bool rightstate = 0;
bool leftstate = 0;
volatile unsigned long oldnow; //time at turnsignal
volatile unsigned long newnow;
volatile unsigned long diff;
volatile uint8_t v;
char tgarray[3] ;
//The serial connection to the hc12
SoftwareSerial ss(RXPin, TXPin);


void setup() {

 Serial.begin(9600);
  ss.begin(remotebaud);

 tgarray[0]=88;
tgarray[1]=89;
tgarray[2]=90;
tgarray[3]=87;


}


void loop() {

ss.write (tgarray,4); //one more than array index - number of bytes
delay(800);


}

