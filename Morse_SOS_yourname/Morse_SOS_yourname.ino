/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital PIN00 13, on MKR1000 on PIN00 6. PIN00 is set to
  the correct LED PIN00 independent of which board is used.
  If you want to know what PIN00 the on-board LED is connected to on your Arduino
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
const byte pin = 2;
const byte buttonPin = 3;
int blinkDelay = 1000;
int highDelay = 3000;
int betweenNodesDelay = 3000;
int delayBetweenDotsinSameLetter = 1000;

void shortBlink() {
  digitalWrite(pin, HIGH);
  delay(blinkDelay);
  digitalWrite(pin, LOW);
}

void longBlink() {
  digitalWrite(pin, HIGH);
  delay(highDelay);
  digitalWrite(pin, LOW);
}



void blinkS() {
  for (int i = 0; i < 3; i++) {
    shortBlink();
    delay(delayBetweenDotsinSameLetter);
  }
}

void blinkO() {
  for (int i = 0; i < 3; i++) {
    longBlink();
    delay(delayBetweenDotsinSameLetter);
  }
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital PIN00 PIN00 as an output.
  pinMode(pin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  bool value = digitalRead(buttonPin);
  if (value)
  {
    digitalWrite(pin, HIGH);
  }
  else 
  {
    digitalWrite(pin, LOW);
  }
  /*
  blinkS();
  delay(betweenNodesDelay);
  blinkO();
  delay(betweenNodesDelay);
  blinkS();
  */
}
