# RFID_Lock

Hardware and firmware for a Photon-based device that can control various locking mechanisms.

The device subscribes to publications with the name "checkin". These events are published by an RFID Station. The event data is JSON and includes the deviceType of the publisher.

Each lock station is configured via Particle Cloud to act on a checkin event from a particular deviceType. If the event contains the correct deviceType, then this device will unlock a cabinet.
