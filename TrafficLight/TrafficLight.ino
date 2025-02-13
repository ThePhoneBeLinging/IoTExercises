/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

const int redLED = 3;
const int yellowLED = 4;
const int greenLED = 5;
const int delayMS = 1000;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Traffic light init");
}

void turnOnLED(int led)
{
  digitalWrite(led, HIGH);
}

void turnOffLED(int led)
{
  digitalWrite(led, LOW);
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("Red Light");
  turnOnLED(redLED);
  delay(delayMS);
  Serial.println("Red And Yellow, get Ready");
  turnOnLED(yellowLED);
  delay(delayMS);
  turnOffLED(redLED);
  turnOffLED(yellowLED);
  Serial.println("Green GO");
  turnOnLED(greenLED);
  delay(delayMS);
  turnOffLED(greenLED);
  
  Serial.println("Begin Stopping");
  turnOnLED(yellowLED);
  delay(delayMS);
  turnOffLED(yellowLED);
}
