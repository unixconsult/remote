#include <Servo.h>



Servo myservo;  // create servo object to control a servo



int potpin = PE_4;  // analog pin used to connect the potentiometer

int val;    // variable to read the value from the analog pin



void setup()

{

Serial2.begin(9600); //tx pd7 , rx pd6
Serial3.begin(9600); // tx pc7 , rx pc6



  myservo.attach(PF_1);  // attaches the servo on Port F, pin 1 (Red LED pin) to                                     the servo object

}



void loop()

{

Serial3.println("hellot");

delay(100);
Serial3.write(99);


  val = analogRead(potpin);            // reads the value of the potentiometer (                                    value between 0 and 4095)

  val = map(val, 0, 4095, 0, 179);     // scale it to use it with the servo (val                                    ue between 0 and 180)

  myservo.write(val);                  // sets the servo position according to t                                    he scaled value

  delay(15);                           // waits for the servo to get there

}
