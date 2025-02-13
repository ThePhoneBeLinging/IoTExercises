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

const int red = 3;
const int yellow = 4;
const int green = 5;
const int blue = 6;
const int lastGreen = 7;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(lastGreen, OUTPUT);
  Serial.begin(9600);
}

void turnOffLEDS()
{
  digitalWrite(red,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
  digitalWrite(lastGreen,LOW);
}

// the loop function runs over and over again forever
void loop() {
  if (Serial.available() > 0)
  {
    char input = Serial.read();
    switch (input)
    {
      case 'a':
        digitalWrite(red,HIGH);
        break;
      case 'b':
        digitalWrite(yellow,HIGH);
        break;
      case 'c':
        digitalWrite(green,HIGH);
        break;
      case 'd':
        digitalWrite(blue,HIGH);
        break;
      case 'e':
        digitalWrite(lastGreen,HIGH);
        break;
      default:
        turnOffLEDS();
        break;
    }
  }
}
