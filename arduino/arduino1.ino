
// Import libraries
#include <Wire.h>

// Define pins connected to the Arduino
const ultrasonicOneTrigPin = 2;
const ultrasonicOneEchoPin = A0;
const ultrasonicTwoTrigPin = 4;
const ultrasonicTwoEchoPin = A1;
const ultrasonicThreeTrigPin = 13;
const ultrasonicThreeEchoPin = 7;
const ultrasonicFourTrigPin = 8;
const ultrasonicFourEchoPin = 12;
const motorLeftPositive = 10;
const motorLeftNegative = 11;
const motorFrontPositive = 9;
const motorFrontNegative = 6;
const motorRightPositive = 3;
const motorRightNegative = 5;
const buzzer = A2;
const led = A3;

const vibrationLevel1 = 0;
const vibrationLevel2 = 28;
const vibrationLevel3 = 56;
const vibrationLevel4 = 85;
const vibrationLevel5 = 113;
const vibrationLevel6 = 141;
const vibrationLevel7 = 170;
const vibrationLevel8 = 198;
const vibrationLevel9 = 226;
const vibrationLevel10 = 255;

const volumeLevel1 = 0;
const volumeLevel2 = 222;
const volumeLevel3 = 444;
const volumeLevel4 = 666;
const volumeLevel5 = 888;
const volumeLevel6 = 1111;
const volumeLevel7 = 1333;
const volumeLevel8 = 1555;
const volumeLevel9 = 1777;
const volumeLevel10 = 2000;

// Define default values for vibration and volume
vibrationEnable = true;
volumeEnable = true;
currentvibrationLevel = vibra0tionLevel5;
volumeLevel = volumeLevel5;

void setup() {
    // Define Pinmodes
    pinMode(ultrasonicOneTrigPin, OUTPUT);
    pinMode(ultrasonicOneEchoPin, INPUT);
    pinMode(ultrasonicTwoTrigPin, OUTPUT);
    pinMode(ultrasonicTwoEchoPin, INPUT);
    pinMode(ultrasonicThreeTrigPin, OUTPUT);
    pinMode(ultrasonicThreeEchoPin, INPUT);
    pinMode(ultrasonicFourTrigPin, OUTPUT);
    pinMode(ultrasonicFourEchoPin, INPUT);
    pinMode(motorLeftPositive, OUTPUT);
    pinMode(motorLeftNegative, OUTPUT);
    pinMode(motorFrontPositive, OUTPUT);
    pinMode(motorFrontNegative, OUTPUT);
    pinMode(motorRightPositive, OUTPUT);
    pinMode(motorRightNegative, OUTPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(led, OUTPUT);

    // Run calibration for buzzer
    digitalWrite(Buzzer, HIGH);
    delay(2500);
    digitalWrite(Buzzer, LOW);



    //Start serical communication and the Wire library
    Wire.begin();
    Serial.begin(9600);
    Serial.println("Sightband is ready!");
}

void loop() {
  if (digitalRead(settingsPin) == HIGH) {

    // Trigger the ultrasonic sensor

    digitalWrite(ultrasonicOneTrigPin, LOW);

    delayMicroseconds(2);

    digitalWrite(ultrasonicOneTrigPin, HIGH);

    delayMicroseconds(10);

    digitalWrite(ultrasonicOneTrigPin, LOW);

 

    // Read the echo pin

    long duration1 = pulseIn(ultrasonicOneEchoPin, HIGH);

 

    // Calculate the distance

    float distance1 = duration1 * 0.034 / 2;

 

    // Print the distance to the serial monitor

    Serial.print("Distance: ");

    Serial.print(distance1);

    Serial.println(" cm");

  }

 

    // Determine which side the object is coming from

    if (distance1 < 20) { // Adjust the distance threshold as needed

        // Object is in distance

        digitalWrite(motorLeftPositive, LOW);

        digitalWrite(motorLeftNegative, HIGH);

        Serial.println("Object in distance of sensor 1");

    } else {

      // No object detected within the threshold distance

      digitalWrite(motorLeftPositive, LOW);

      digitalWrite(motorLeftNegative, LOW);

    } else {

      // Settings are off, turn off motors

      digitalWrite(motorLeftPositive, LOW);

      digitalWrite(motorLeftNegative, LOW);

    }

 

  //second sensor

 

  if (digitalRead(settingsPin) == HIGH) {

    // Trigger the ultrasonic sensor

    digitalWrite(ultrasonicTwoTrigPin, LOW);

    delayMicroseconds(2);

    digitalWrite(ultrasonicTwoTrigPin, HIGH);

    delayMicroseconds(10);

    digitalWrite(ultrasonicTwoTrigPin, LOW);

 

    // Read the echo pin

    long duration2 = pulseIn(ultrasonicTwoEchoPin, HIGH);

 

    // Calculate the distance

    float distance2 = duration2 * 0.034 / 2;

 

    // Print the distance to the serial monitor

    Serial.print("Distance: ");

    Serial.print(distance2);

    Serial.println(" cm");

  }

    // Determine which side the object is coming from

    if (distance2 < 20) { // Adjust the distance threshold as needed

        // Object is in distance

        digitalWrite(motorFrontPositive, LOW);

        digitalWrite(motorFrontNegative, HIGH);

        Serial.println("Object in distance of sensor 2");

    } else {

      // No object detected within the threshold distance

      digitalWrite(motorFrontPositive, LOW);

      digitalWrite(motorFrontNegative, LOW);

    } else {

      // Settings are off, turn off motors

      digitalWrite(motorFrontPositive, LOW);

      digitalWrite(motorFrontNegative, LOW);

    }

 

    //third sensor

 

  if (digitalRead(settingsPin) == HIGH) {

    // Trigger the ultrasonic sensor

    digitalWrite(ultrasonicThreeTrigPin, LOW);

    delayMicroseconds(2);

    digitalWrite(ultrasonicThreeTrigPin, HIGH);

    delayMicroseconds(10);

    digitalWrite(ultrasonicThreeTrigPin, LOW);

 

    // Read the echo pin

    long duration3 = pulseIn(ultrasonicTwoEchoPin, HIGH);

 

    // Calculate the distance

    float distance3 = duration3 * 0.034 / 2;

 

    // Print the distance to the serial monitor

    Serial.print("Distance: ");

    Serial.print(distance3);

    Serial.println(" cm");

  }

    // Determine which side the object is coming from

    if (distance3 < 20) { // Adjust the distance threshold as needed

        // Object is in distance

        digitalWrite(motorRightPositive, LOW);

        digitalWrite(motorRightNegative, HIGH);

        Serial.println("Object in distance of sensor 3");

    } else {

      // No object detected within the threshold distance

      digitalWrite(motorRightPositive, LOW);

      digitalWrite(motorRightNegative, LOW);

    } else {

      // Settings are off, turn off motors

      digitalWrite(motorRightPositive, LOW);

      digitalWrite(motorRightNegative, LOW);

    }

 

  // Small delay before the next loop

    delay(100);

}