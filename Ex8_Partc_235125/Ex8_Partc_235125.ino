/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
*/

const byte pin1 = 2;
const byte pin2 = 3;
const byte pin3 = 4;
const byte pin4 = 5;
const byte pin5 = 6;
const byte pin6 = 8;
const byte pin7 = 9;
const byte pin8 = 12;

void drawZero()
{
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, HIGH);
  digitalWrite(pin5, HIGH);
  digitalWrite(pin6, HIGH);
  digitalWrite(pin8, HIGH);
}

void drawOne()
{
  digitalWrite(pin4, HIGH);
  digitalWrite(pin8, HIGH);
}

void drawTwo()
{
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4,HIGH);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin5,HIGH);
  digitalWrite(pin6, HIGH);
}

void drawThree()
{
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, HIGH);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin8, HIGH);
  digitalWrite(pin6, HIGH);
}

void drawFour()
{
  digitalWrite(pin2,HIGH);
  digitalWrite(pin1,HIGH);
  digitalWrite(pin4,HIGH);
  digitalWrite(pin8,HIGH);
}

void drawFive()
{
  digitalWrite(pin3, HIGH);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin8,HIGH);
  digitalWrite(pin6, HIGH);
}

void drawSix()
{
  digitalWrite(pin3, HIGH);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin8,HIGH);
  digitalWrite(pin5, HIGH);
  digitalWrite(pin6, HIGH);
  digitalWrite(pin7, HIGH);
}

void drawSeven()
{
  digitalWrite(pin4, HIGH);
  digitalWrite(pin8, HIGH);
  digitalWrite(pin3, HIGH);
}

void drawEight()
{
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, HIGH);
  digitalWrite(pin5, HIGH);
  digitalWrite(pin6, HIGH);
  digitalWrite(pin8, HIGH);
}

void drawNine()
{
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, HIGH);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin8,HIGH);
  //digitalWrite(pin5, HIGH);
  digitalWrite(pin6, HIGH);
  digitalWrite(pin7, HIGH);
}

void allOff()
{
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, LOW);
  digitalWrite(pin6, LOW);
  digitalWrite(pin7, LOW);
  digitalWrite(pin8, LOW);
}

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  int convertedToSingleDigit = sensorValue / (1023 / 9);
  allOff();
  Serial.println(sensorValue);
  switch(convertedToSingleDigit)
  {
    case 0:
      drawZero();
      break;
    case 1: 
      drawOne();
      break;
    case 2:
      drawTwo();
      break;
    case 3: 
      drawThree();
      break;
    case 4:
      drawFour();
      break;
    case 5:
      drawFive();
      break;
    case 6:
      drawSix();
      break;
    case 7:
      drawSeven();
      break;
    case 8:
      drawEight();
      break;
    case 9:
      drawNine();
      break;
  }
  delay(1);  // delay in between reads for stability
}
