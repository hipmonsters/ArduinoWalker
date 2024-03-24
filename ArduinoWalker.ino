/*********
  HipMonsters.com
  See more ate www.HipMonsters.com
  Simple Aiduino controler for a solenoid
*********/

// The varibale storing what state the relat for the solenoid is currently in
volatile byte solenoidSate = LOW; 

// Which pin the relay conected to the solenoid is pugged into the Arduino
int solenoidRelayPin = 8;
 
 // the last time the leg moved forward
long legMovementTime = 0;

// how long the leg should move forward.
long legMovementLength = 10000;

// This runs when the Aruino boots up
void setup() { 

  // Lets the Arduino know it can write out to the pin for the relay
  pinMode(solenoidPin, OUTPUT);  

  // Sets the relaty to High (on)
  digitalWrite(solenoidPin, HIGH);
 
  // Sets the last time the leg moved to right now.
  legMovementTime = millis();
   
  //Tells the Arduino to listen to the text port so we can send commands to it.
  Serial.begin(9600);

  //Writes to the serial port 
  Serial.println("ACTIVE!");
}

// This is the loop which continious runs to send commands to the pin.
void loop() {

  // Here is where we define how the Arduino makes the legs move between lett and right
  // The flow control logic here sasy: If enough time has past and the left leg was moved last time moove the right leg
  if ((millis() - legMovementTime) > legMovementLength && solenoidSate == HIGH) {

    digitalWrite(solenoidPin, HIGH);
    solenoidSate = LOW; 
    Serial.println("OFF"); 
    legMovementTime = millis();

  // The flow control logic here sasy: If enough time has past and the right leg was moved last time moove the left leg
  } else if  ( (millis() - legMovementTime) > legMovementLength && solenoidSate == LOW) {

    digitalWrite(solenoidPin, LOW); 
    solenoidSate = HIGH; 
    Serial.println("ON"); 
    legMovementTime = millis();
  } 

  // Tells the loop to pause for 50 microseconds 
  delay(50);
}
 
// Happy coding!
 