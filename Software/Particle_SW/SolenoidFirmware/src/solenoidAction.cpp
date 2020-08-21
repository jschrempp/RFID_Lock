/* solenoidAction: firmware to control the lock motor

    The solenoid-lock is normally in the neutral position inside the door panic bar.
    
    When the function "triplock" is called, it pulses the solenoid for unlockTime, then
    releases the solenoid.
    
    unlockTime should be long enough for the human to hear the solenoid unlock the door
    and react by opening the door.
        
    by: Bob Glicksman, Jim Schrempp; 8/9/2020
    (c) 2020 by Bob Glicksman, Jim Schrempp, Team Practical Projects

*/

#include "solenoidAction.h"

const int unlockTime = 2000;    // unlock time for door to swing open
const int runPin = D0;

void unlock() { // unlock the latch
    digitalWrite(runPin, HIGH);
}   // end of unlock()

void lock() { // lock the latch
    digitalWrite(runPin, LOW);
}   // end of lock()



void initSolenoidAction() { // called once to initialize this module
    
    pinMode(runPin, OUTPUT);
        
    digitalWrite(runPin, LOW);    
    
}  

void tripSolenoid() {  // function to trip the lock
    unlock();
    delay(unlockTime);
    lock();
}   // end of tripLock()
