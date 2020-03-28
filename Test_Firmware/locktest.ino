/* LOCKTEST: firmware to test out Photon control of the motor-lock mechanism.  Also test
    an external LED, a relay (e.g. to trip an external solenoid) and an on-board buzzer

    The motor-lock is normally in the locked position, except that the plastic keeper holds the 
    lock keeper back so that the latch-loop can be inserted.  When inserted, it is locked by 
    virtue of the keeper springing into the open middle of the lock-loop.
    
    When the cloud function "triplock" is called (with any argument), it pulses the motor-lock 
    to the "unlock" position for the period of "unlockTime" and then pulses the motor-lock back
    to the "lock" position.
    
    The constant "pulseTime" is the time to actually run the motor of the motor-lock.
    Motor direction is clockwise (unlock) for HIGH and counterclockwise (lock) for LOW.
    The motor must be wired for these directions.
    
    When the cloud function "testIO" is called (with any argument), it lights the external LED,
    activated the relay and activates the buzzer, all for 2 seconds.
    
    The cloud function "moveServo" will close the servo_lock when called with an argument of "0";
    it will open the servo_lock when called with any other argument.

    by: Bob Glicksma; 3/28/20
    (c) 2020 by Bob Glicksman, Jim Schrempp, Team Practical Projects

*/

const int pulseTime = 30;   // motor activation time (ms)
const int unlockTime = 2000;    // unlock time for door to swing open

const int CLOSED_POSITION = 85; // servo opne position
const int OPEN_POSITION = 5;    // servo close (lock) position


const int directionPin = D2;
const int runPin = D3;
const int ledPin = D7;

const int relayPin = D0;
const int servoPin = D1;
const int doorSensorPin = D4;
const int extLedPin = D5;
const int buzzerPin = D6;

Servo myservo;  // create servo object to control a servo


void setup() {
    
    pinMode(directionPin, OUTPUT);
    pinMode(runPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    pinMode(relayPin, OUTPUT);
    pinMode(doorSensorPin, INPUT_PULLUP);
    pinMode(extLedPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    
    digitalWrite(directionPin, LOW);
    digitalWrite(runPin, LOW);    
    
    digitalWrite(ledPin, LOW);
    digitalWrite(relayPin, LOW);
    digitalWrite(extLedPin, LOW);
    digitalWrite(buzzerPin, LOW);
    
    myservo.attach(servoPin);  // attaches servo pin to the servo object
    myservo.write(OPEN_POSITION);  // set initial position to open

    
    lock(); // put the latch into the lock position
    
    Particle.function("tripLock", tripLock);    // cloud function to trip the motor lock
    Particle.function("testIO", testIO);        // cloud function to test the external LED, relay and buzzer I/O
    Particle.function("moveServo", moveServo);  // cloud function to move the servo lock
    
    // just flash the D7 LED
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);

}   // end of setup()

void loop() {
    
    // do nothing
    
}   // end of loop()

int tripLock(String command) {  // cloud function to trip the lock
    unlock();
    delay(unlockTime);
    lock();
}   // end of tripLock()

int testIO(String command) {  // cloud function to test ext LED, buzzer, relay
    // light external LED and buzz buzzer
    digitalWrite(extLedPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(relayPin, HIGH);    
    delay(2000);   
    digitalWrite(extLedPin, LOW);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(relayPin, LOW); 

}   // end of testIO()

int moveServo(String position) {
    if(position == "0" ) {  // move the servo to the close position
        myservo.write(OPEN_POSITION);
        digitalWrite(ledPin, LOW);
    }
    else {                  // move the servo to the open position
        myservo.write(CLOSED_POSITION);
        digitalWrite(ledPin, HIGH);
    }
    
}   // end of moveServo()


void unlock() { // unlock the latch
    digitalWrite(directionPin, HIGH);   // motor direction is unlock
    digitalWrite(runPin, HIGH);
    delay(pulseTime);
    digitalWrite(runPin, LOW);
}   // end of unlock()

void lock() { // lock the latch
    digitalWrite(directionPin, LOW);   // motor direction is lock
    digitalWrite(runPin, HIGH);
    delay(pulseTime);
    digitalWrite(runPin, LOW);
}   // end of lock()

