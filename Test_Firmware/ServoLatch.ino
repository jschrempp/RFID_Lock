/* SERVOLATCH: program to open and close a door latch using a servo
    with a hook on its shaft.
    
    date: 3/10/20, by Bob Glicksman
    
    (c) 2020 by Bob Glicksman, Jim Schrempp, and team Practical Projects
*/

const int CLOSED_POSITION = 85;
const int OPEN_POSITION = 5;

const int SERVO_PIN = A5;
const int BUTTON_PIN = D4;
const int LED_PIN = D7;

Servo myservo;  // create servo object to control a servo

bool pos = false;    // variable to store the servo position

void setup() {
    myservo.attach(SERVO_PIN);  // attaches pin D3 to the servo object
    myservo.write(OPEN_POSITION);  // set initial position to open
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
    
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    digitalWrite(LED_PIN, LOW);
    
    Particle.function("moveServo", moveServo);

} // end of setup

void loop() {
 
    if (pos) {
        myservo.write(CLOSED_POSITION);
        digitalWrite(LED_PIN, HIGH);
    }
    else {
        myservo.write(OPEN_POSITION);
        digitalWrite(LED_PIN, LOW);
    }

} // end of loop
 
int moveServo(String position) {

    if(position == "0" ) {
        pos = false;
    }
    else {
        pos = true;
    }
}
