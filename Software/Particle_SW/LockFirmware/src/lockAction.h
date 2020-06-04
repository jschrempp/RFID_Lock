/* lockAction: firmware to control the lock motor

    The motor-lock is normally in the locked position, except that the plastic keeper holds the 
    lock keeper back so that the latch-loop can be inserted.  When inserted, it is locked by 
    virtue of the keeper springing into the open middle of the lock-loop.
    
    When the function "triplock" is called, it pulses the motor-lock 
    to the "triplock" position for the period of "unlockTime" and then pulses the motor-lock back
    to the "lock" position.
    
    The constant "pulseTime" is the time to actually run the motor of the motor-lock.
    Motor direction is clockwise (unlock) for HIGH and counterclockwise (lock) for LOW.
    The motor must be wired for these directions.
    
    by: Bob Glicksman, Jim Schrempp; 6/3/2020
    (c) 2020 by Bob Glicksman, Jim Schrempp, Team Practical Projects

*/

#include "application.h"

void tripLock();  // function to trip the lock

void initLockAction();  // called once to initialize this module

