/* solenoidAction: firmware to control the lock motor

    The solenoid-lock is normally in the neutral position inside the door panic bar.
    
    When the function "triplock" is called, it pulses the solenoid for unlockTime, then
    releases the solenoid.
    
    unlockTime should be long enough for the human to hear the solenoid unlock the door
    and react by opening the door.
        
    by: Bob Glicksman, Jim Schrempp; 8/9/2020
    (c) 2020 by Bob Glicksman, Jim Schrempp, Team Practical Projects

*/

#include "application.h"

void tripSolenoid();  // function to trip the lock

void initSolenoidAction();  // called once to initialize this module

