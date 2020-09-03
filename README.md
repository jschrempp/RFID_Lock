# RFID_Lock

Hardware and firmware for a Photon-based device that can control various locking mechanisms.

The device subscribes to publications with the name "checkin". These events are published by an RFID Station. 
The event data is JSON encoded and includes the deviceType of the publisher, as well as a secret security key.

Each lock station is configured via an App (or via the Particle Cloud) to act on a checkin event from a particular deviceType. 
If the event contains the correct deviceType and the correct secret key, then this device will unlock a cabinet, door, machine or power.

## Story
Our MN_ACL project (https://github.com/TeamPracticalProjects/MN_ACL) creates an infrastructure for secure, 
RFID-based access control to a Makerspace and it's various internal equipment locations.  That project integrates
Particle Argon-based RFID stations with a commercial cloud CRM system and an internal tracking database.
The MN_ACL project ensures that people who access the facility are paid up members in good standing and that
members who access certain locations containing sophisticated industrial equipment have basic operating 
and safety instruction credentials.  The project controls access via red/green lit buttons and an audible beeper.

Certain locations within the Makerspace contain expensive materials, parts and accessories.  We decided to create 
a Particle Photon-based add-on that could subscribe to publications sent by the Argons in the RFID stations
and unlock cabinets containing these expensive accessories.  We therefore needed to find an inexpensive but 
effective electrically controlled locking mechanism and create a Photon-based printed circuit board (and
associated Particle firmware) to unlock the cabinet when a member taps into one of the relevant RFID
stations with credentials that allow them access to these accessories.

COVID-19 related health and safety regulations require that the front door be locked to the outside and 
access to the facility be controlled. There is a 24 volt (DC) solenoid in the door mechanism that is wired 
back into the facility equipment room.  We determined that mounting an RFID station at the front entrance and 
using the same publish/subscribe mechanism as for cabinet locks, we could remotely and securely activate the front 
door solenoid lock to admit members when they tap their badge to the front door RFID station.

We decided to generalize this mechanism as much as possible in order to accommodate other access control requirements as
they arise in the future.

We decided that we needed a separate WiFi enabled circuit board for this purpose because:

1. The relationship between RFID stations and cabinets/locks is many to many.

2. Hardwiring a lock control signal from an RFID station to certain cabinets or locks is both inconvenient
and easily hacked.

3. A general-purpose, secure, WiFi enabled locking mechanism is a worthwhile and useful project
in and of itself, independent of the MN_ACL project and it's RFID stations.

We selected the Particle Photon for this project because it provides a low cost and secure means of WiFi
control and communication and because of Particle's simple and elegant cloud communication capabilities.

## Locking Mechanisms
### Locking a cabinet
We investigated a number of solutions for electrically controlled locking mechanisms and we ultimately
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
thereafter be closed and will lock anytime after the small motor returns to the locked position. The 
device can therefore unlock, opening the cabinet door, and then immediately re-lock and the door can 
be closed and will automatically lock at any time thereafter.

### The front door
The facility front door has a locking pushbar that includes a solenoid for remote unlocking.  This solenoid
was already wired back to the facility's equipment room. We experimentally determined that activating the 
solenoid for 2 seconds after a successful RFID card tap-in by a member in good standing is more than sufficient 
to provide entry to the facility.

### Our documentation
This project contains complete instructions for building an RFID Lock using the Tokatuker product.  This
project also contains instructions and firmware for activating a door-unlocking solenoid.
We also investigated various other locking mechanisms based upon servos, solenoids, etc.
We have included some information about these other approaches in this repository but we cannot
supply complete mechanics and Particle firmware to use them, as we did not carry these other locking
solutions through to a complete project solution.

## Electronics
We developed a printed circuit board that houses a Photon and integrates the Photon with components
that allowed us to test out various locking solutions.  This printed circuit board seemed so generally
useful to us that we have made it a project unto itself.  See: 
https://github.com/TeamPracticalProjects/Wireless_IO_Board

This project uses the Wireless_IO_Board hardware and we have added the Particle firmware necessary
to subscribe to publications from MN_ACL RFID Stations.  The documentation included with this project
provides ample references to these other projects where necessary.  Two sets of firmware are documented:
(1) firmware to respond to valid check-in events and unlock the modified Tokatuker motor lock.
(2) firmware to respond to valid check-in event and activate a door unlock solenoid.

## Mechanics
The modifications to the Tokatuker lock are documented in this repository.  Likewise, instructions
are provided for mounting the hardware in a small test cabinet that is demonstrative but also
useful in its own right.

## Firmware
This project includes Particle firmware (source code) for the Photon that integrates the RFID Lock
into the complete MN_ACL access control solution.


