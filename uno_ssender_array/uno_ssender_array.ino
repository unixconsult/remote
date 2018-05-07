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



  
}

void loop() {
  // put your main code here, to run repeatedly:

  

  newnow = millis();

serialdata[0]= 99;
serialdata[1]= 100;
serialdata[2]= 101;
serialdata[3]= 102;
serialdata[4]= 103;

                                   

ss.write(serialdata,sizeof(serialdata));
Serial.println("array of 5  ");
    Serial.write(serialdata,sizeof(serialdata));
delay(300);








}



