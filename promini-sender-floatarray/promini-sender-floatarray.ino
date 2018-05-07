#include <SoftwareSerial.h>
//com8
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
byte tgarray[3] ;

float tgfloat[3];
byte bytearray[12];
//The serial connection to the hc12
SoftwareSerial ss(RXPin, TXPin);


void setup() {

 Serial.begin(9600);
  ss.begin(remotebaud);
  
tgfloat[0]= 2.4;
 tgfloat[1]= 3.4;
 tgfloat[2]= 4.4;



}


void loop() {

  memcpy(bytearray, tgfloat, sizeof bytearray);


//ss.write (tgarray,3); //one more than array index - number of bytes

ss.write (bytearray,sizeof bytearray); //needs delay of (sizeof bytearray)ms 
delay(15);
 tgfloat[0]=  analogRead(A0); // vor-zurück vor 1023
 tgfloat[1]=  analogRead(A1);//rechts-links  rechts 1023 , links 0
}

