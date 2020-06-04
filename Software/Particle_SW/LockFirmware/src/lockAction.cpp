/* LOCKTEST: firmware to control the motor-lock mechanism.  

    The motor-lock is normally in the locked position, except that the plastic keeper holds the 
    lock keeper back so that the latch-loop can be inserted.  When inserted, it is locked by 
    virtue of the keeper springing into the open middle of the lock-loop.
    
    When the cloud function "triplock" is called (with any argument), it pulses the motor-lock 
    to the "unlock" position for the period of "unlockTime" and then pulses the motor-lock back
    to the "lock" position.
    
    The constant "pulseTime" is the time to actually run the motor of the motor-lock.
    Motor direction is clockwise (unlock) for HIGH and counterclockwise (lock) for LOW.
    The motor must be wired for these directions.
    
    by: Bob Glicksman, Jim Schrempp; 6/3/2020
    (c) 2020 by Bob Glicksman, Jim Schrempp, Team Practical Projects

*/

#include "lockAction.h"

const int pulseTime = 30;   // motor activation time (ms)
const int unlockTime = 2000;    // unlock time for door to swing open

const int CLOSED_POSITION = 85; // servo opne position
const int OPEN_POSITION = 5;    // servo close (lock) position


const int directionPin = D2;
const int runPin = D3;

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



void initLockAction() { // called once to initialize this module
    
    pinMode(directionPin, OUTPUT);
    pinMode(runPin, OUTPUT);
        
    digitalWrite(directionPin, LOW);
    digitalWrite(runPin, LOW);    
    
    lock(); // put the latch into the lock position
    
}  

void tripLock() {  // function to trip the lock
    unlock();
    delay(unlockTime);
    lock();
}   // end of tripLock()
