

// Import libraries
#include <Wire.h>

// Define pins
const int encoderCLK = 2;
const int encoderDT = 3;
const int encoderSW = 4;
const int pushButtonLeft = 5;
const int pushButtonRight = 6;
const int pushButtonDown = 7;
const pushButtonBack = 8;
const pushButtonSelect = 9;
const LEDpwr = 10;
const flickSwitchVolume = 11;
const flickSwitchVibration = 12;
const LEDcaution = 13;


void setup() {
    // Define pinmodes
    pinMode(encoderCLK, INPUT);
    pinMode(encoderDT, INPUT);
    pinMode(encoderSW, INPUT);
    pinMode(pushButtonLeft, INPUT);
    pinMode(pushButtonRight, INPUT);
    pinMode(pushButtonDown, INPUT);
    pinMode(pushButtonBack, INPUT);
    pinMode(pushButtonSelect, INPUT);
    pinMode(LEDpwr, OUTPUT);
    pinMode(flickSwitchVolume, INPUT);
    pinMode(flickSwitchVibration, INPUT);
    pinMode(LEDcaution, OUTPUT);
  
    //Start serial communication and the Wire library
    Wire.begin();
    Serial.begin(9600);
    Serial.println("Sightband is ready!");
}

void loop() {
  // put your main code here, to run repeatedly:
}