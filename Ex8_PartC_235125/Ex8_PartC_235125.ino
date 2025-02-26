
const byte blue = 3;
const byte green = 5;
const byte red = 6; 

void setup() {
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  // modulo 146 to get 7 different colors
  int diff = sensorValue % 146;
  // Multiply to still be able to get the full spectrum from 0 to 255;
  diff *= 1.746575342;
  // Purple To Blue
  if (sensorValue < 146)
  {
    analogWrite(blue, 255);
    analogWrite(green, 0);
    analogWrite(red, 255 - diff);
  }
  // Blue to Cyan
  else if (sensorValue < 292)
  {
    analogWrite(blue, 255);
    analogWrite(green, 0 + diff);
    analogWrite(red, 255 - diff);
  }
  // Cyan to Light-Green (Thats why its not 0,255,0);
  else if (sensorValue < 584)
  {
    analogWrite(blue, 255 - diff/2);
    analogWrite(green, 255);
    analogWrite(red, 0 + diff/2);
  }
  // Light-Green to Yellow
  else if (sensorValue < 730)
  {
    analogWrite(blue, 255/2 - diff/2);
    analogWrite(green, 255);
    analogWrite(red, 255/2 + diff/2);
  }
  // Yellow to Orange
  else if (sensorValue < 876)
  {
    analogWrite(blue, 0);
    analogWrite(green, 255 - diff/2);
    analogWrite(red, 255);
  }
  // Orange to Red
  else if (sensorValue < 1024)
  {
    analogWrite(blue, 0);
    analogWrite(green,255/2 - diff/2);
    analogWrite(red, 255);
  }
  else
  {
    analogWrite(blue, 0);
    analogWrite(green, 0);
    analogWrite(red, 0);
  }
  delay(1);
}
