#include <SoftwareSerial.h>

//com6

//motor: 
// wired connections
#define HG7881_B_IA 10 // D10 --> Motor B Input A --> MOTOR B +
#define HG7881_B_IB 11 // D11 --> Motor B Input B --> MOTOR B -
 
// functional connections
#define MOTOR_B_PWM HG7881_B_IA // Motor B PWM Speed
#define MOTOR_B_DIR HG7881_B_IB // Motor B Direction
 
// the actual values for "fast" and "slow" depend on the motor
#define PWM_SLOW 50  // arbitrary slow speed PWM duty cycle
#define PWM_FAST 200 // arbitrary fast speed PWM duty cycle
#define DIR_DELAY 200 // brief delay for abrupt motor changes

int drivevalue;
int forwbackw;
bool isValidInput;
//end motor

static const int RXPin = 4, TXPin = 5;
static const uint32_t remotebaud = 9600;
uint16_t remotedata[4];
byte tgarray[3] ;
byte bytearray[8];

SoftwareSerial ss(RXPin, TXPin);


void setup() {
  // put your setup code here, to run once:

 //myservo.attach(9);  // attaches the servo on pin 9 to the servo object
 Serial.begin(9600);
ss.begin(remotebaud);
Serial.println("serial begins");

pinMode( MOTOR_B_DIR, OUTPUT );
  pinMode( MOTOR_B_PWM, OUTPUT );
  digitalWrite( MOTOR_B_DIR, LOW );
  digitalWrite( MOTOR_B_PWM, LOW );

}

void loop() {
  
      
      


if (ss.available()>11) {
 ss.readBytes(bytearray, sizeof bytearray);
    //myservo.write(sv );
      //Serial.write(tgarray,3);
       memcpy( remotedata, bytearray,sizeof remotedata);
Serial.println(sizeof(remotedata));
Serial.println(remotedata[0]);// vor-zurück vor 1023
Serial.println(remotedata[1]);//rechts-links  rechts 1023 , links 0
Serial.println(remotedata[2]);
/*
 "1) Fast forward" 
  ( "2) Forward" 
  "3) Soft stop (coast)" );
  "4) reverse" );
   "5) Fast reverse" );
   "6) Hard stop (brake)" );

*/
// var= map(value, fromLow, fromHigh, toLow, toHigh)

enum drive_t {fforward=1, //creates a new type "drive" 
forward=2,
sstop =3,
reverse=4,
freverse=5,
hstop=6};

// var= map(value, fromLow, fromHigh, toLow, toHigh)

int drivevalue = map(remotedata[0], 0, 1023, 0, 255);

drive_t drivestate;
if (remotedata[0]< 450) {
  drivestate = reverse;
}

else if  ((remotedata[0]> 580)&& (remotedata[0]< 1024) ) {
  drivestate = forward;
}

else { 
   drivestate = sstop;
}


switch( forwbackw )
    {
      case fforward: // 1) Fast forward
        Serial.println( "Fast forward..." );
        // always stop motors briefly before abrupt changes
        digitalWrite( MOTOR_B_DIR, LOW );
        digitalWrite( MOTOR_B_PWM, LOW );
        delay( DIR_DELAY );
        // set the motor speed and direction
        digitalWrite( MOTOR_B_DIR, HIGH ); // direction = forward
        analogWrite( MOTOR_B_PWM, 255-PWM_FAST ); // PWM speed = fast
        isValidInput = true;
        break;      
         
      case forward: // 2) Forward      
        Serial.println( "Forward..." );
        // always stop motors briefly before abrupt changes
        digitalWrite( MOTOR_B_DIR, LOW );
        digitalWrite( MOTOR_B_PWM, LOW );
        delay( DIR_DELAY );
        // set the motor speed and direction
        digitalWrite( MOTOR_B_DIR, HIGH ); // direction = forward
        analogWrite( MOTOR_B_PWM, 255-PWM_SLOW ); // PWM speed = slow
        isValidInput = true;
        break;      
         
      case sstop: // 3) Soft stop (preferred)
        Serial.println( "Soft stop (coast)..." );
        digitalWrite( MOTOR_B_DIR, LOW );
        digitalWrite( MOTOR_B_PWM, LOW );
        isValidInput = true;
        break;      
 
      case reverse: // 4) reverse
        Serial.println( "Fast forward..." );
        // always stop motors briefly before abrupt changes
        digitalWrite( MOTOR_B_DIR, LOW );
        digitalWrite( MOTOR_B_PWM, LOW );
        delay( DIR_DELAY );
        // set the motor speed and direction
        digitalWrite( MOTOR_B_DIR, LOW ); // direction = reverse
        analogWrite( MOTOR_B_PWM, PWM_SLOW ); // PWM speed = slow
        isValidInput = true;
        break;      
         
      case freverse: // 5) Fast reverse
        Serial.println( "Fast forward..." );
        // always stop motors briefly before abrupt changes
        digitalWrite( MOTOR_B_DIR, LOW );
        digitalWrite( MOTOR_B_PWM, LOW );
        delay( DIR_DELAY );
        // set the motor speed and direction
        digitalWrite( MOTOR_B_DIR, LOW ); // direction = reverse      
        analogWrite( MOTOR_B_PWM, PWM_FAST ); // PWM speed = fast
        isValidInput = true;
        break;
         
      case hstop: // 6) Hard stop (use with caution)
        Serial.println( "Hard stop (brake)..." );
        digitalWrite( MOTOR_B_DIR, HIGH );
        digitalWrite( MOTOR_B_PWM, HIGH );
        isValidInput = true;
        break;      
         
      default:
        // wrong character! display the menu again!
        isValidInput = false;
       
        Serial.println( "Soft stop (coast)..." );
        digitalWrite( MOTOR_B_DIR, LOW );
        digitalWrite( MOTOR_B_PWM, LOW );
        break;
    }



      
  }

  






 
}
