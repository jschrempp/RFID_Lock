# RFID_Lock
Hardware and firmware for a Photon-based device that can control various locking mechanisms.
The device can subscribe to publications from an RFID station in order to unlock a cabinet or
activate some powered equipment.  

## Story
Our MN_ACL project (https://github.com/TeamPracticalProjects/MN_ACL) creates an infrastructure for secure, 
RFID-based access control to a Makerspace and it's various internal equipment locations.  That project integates
Particle Argon-based RFID stations with a commercial cloud CRM system and an internal tracking database.
The MN_ACL project ensures that people who access the facility are paid up members in good standing and that
members who access certain locations containing sophisticated industrial equipment have basic operating 
and safety instruction credentials.  The project controls access via red/green lit buttons and audible beeper.

Certain locations within the Makerspace contain expensive materials, parts and accessories.  We decided to create 
a Particle Photon-based add-on that could subscribe to publications sent by the Argons in the RFID stations
and unlock cabinets containing these expensive accessories.  We therefore needed to find an inexpensive but 
effective electrically controlled locking mechanism and create a Photon-based printed circuit board (and
associated Particle firmware) to unlock the cabinet when a member taps into one of the relevant RFID
stations with credentials that allow them access to these accessories.

We decided that we needed a separate WiFi enabled circuit board for this purpose because:

1. The relationship between RFID stations and cabinets is many to many.

2. Hardwiring a lock control signal from an RFID station to certain cabinets is both inconvenient
and easily hacked.

3. A general-purpose, secure, WiFi enabled cabinet locking mechanism is a worthwile and useful project
in and of itself, independent of the MN_ACL project and it's RFID stations.

We selected the Particle Photon for this project because it provides a low cost and secure means of WiFi
control and communication and because of Particle's simple and elegant cloud communication capabilities.

## Locking Mechanisms
We investigated a number of solutions for electrically contolled locking mechanisms and we ultimately
decided to hack an off-the-shelf mechanism from Tokatuker; see: 
https://www.amazon.com/Tokatuker-Electronic-Cabinet-Hidden-Drawer/dp/B075QF1VPR

The Tokatuker cabinet lock is a complete RFID solution in itself, but it does not have the required 
security or database integrations required for this project.  We therefore removed the electronics 
and provided our own Photon-based hardware to control the lock.  We also removed the batteries and 
we power the Tokatuker mechanism from our hardware so that the cabinets would not be stuck locked 
if a battery runs down.

We chose the Tokatuker solution because the locking mechanism itself is very innovative and uses only
a small, low power DC motor to control a mechanically robust locking system.  We found that pulsing this
motor for 30 milliseconds in one direction unlocks the lock and pulsing it for 30 milliseconds in the 
opposite direction re-locks the lock.  Unlocking the lock springs the cabinet door open and the door can
thereafter be closed and will lock anytime after the small motor returns to the locked position.  
The device can therefore unlock, opening the cabinet door, and then immediately re-lock and the door can 
be closed and will automatically lock at any time thereafter.

This project contains complete instructions for building an RFID Lock using the Tokatuker product.
However, we also investigated various other locking mechanisms based upon servos, solenoids, etc.
We have included some information about these other approaches in this repository but we cannot
supply complete mechanics and Particle firmware to use them, as we did not carry these other locking
solutions through to a complete project solution.

## Electronics
We developed a printed circuit board that houses a Photon and integrates the Photon with components
that allowed us to test out various locking solutions.  This printed circuity board seemed so generally
useful to us that we have made it a project unto itself.  See: 
https://github.com/TeamPracticalProjects/Wireless_IO_Board

This project uses the Wireless_IO_Board hardware and we have added the Particle firmware necessary
to subscribe to publications from MN_ACL RFID stations.  The documentation included with this project
provides ample references to these other projects where necessary.

## Mechanics
The modifications to the Tokatuker lock are documented in this repository.  Likewise, instructions
are provided for mounting the hardware in a small test cabinet that is demonstrative but also
useful in its own right.

## Firmware
This project includes Particle firmware (source code) for the Photon that integrates the RFID Lock
into the complete MN_ACL access control solution.


