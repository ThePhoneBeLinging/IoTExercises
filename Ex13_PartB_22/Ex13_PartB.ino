#include <LiquidCrystal.h>


const int pin0 = 2;
const int pin1 = 3;
const int pin2 = 4;
const int pin3 = 5;
const int pin4 = 6;
const int buttonPin = 10;
int multiplier = 1;
int activeLED = -1;
bool pressed = false;
int correctAnswers = 0;

const int rs = 12, en = 11, d4 = 7, d5 = 8, d6 = 1, d7 = 0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(pin0, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(buttonPin, INPUT);
  lcd.clear();
  lcd.print("Score: 0");
}

void loop() {
  // Continue playing the game until reaching 10 correct answers
  while (correctAnswers < 10) {
    cycleLEDs();
    // If 8 correct answers is reached start flashing randomly
    if (correctAnswers >= 8) {
      flashRandomly();
    }
  }
  gameOver();
}

// Turn the LED's on one by one 
void cycleLEDs() {
  for (int i = 0; i < 5; i++) {
    int currentLED = getLEDFromIndex(i);
    digitalWrite(currentLED, HIGH);
    activeLED = i;
    for (int i = 0; i < 1000/multiplier; i++)
    {
        delay(1);
        // Check if the button was pressed while this LED was on
        if (checkButtonPress()) {
        return;
        }
    }
    digitalWrite(currentLED, LOW);
    
  }
}

// Check if the button was pressed at the correct time
bool checkButtonPress() {
  if (digitalRead(buttonPin) == HIGH) {
    pressed = true;
    if (activeLED == 2) {
      correctAnswers++;
      multiplier++;
      indicateSuccess();
    } else {
      indicateFailure();
    }
    // Update the display to show current correct answers count
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Score: ");
    lcd.print(correctAnswers);
    return true;
  }
  return false;
}

void indicateSuccess() {
  for (int i = 0; i < 3; i++) {
    turnAllLEDs(HIGH);
    delay(100);
    turnAllLEDs(LOW);
    delay(100);
  }
}

void indicateFailure() {
  turnAllLEDs(LOW);
  delay(500);
}

void flashRandomly() {
  for (int i = 0; i < 10; i++) {
    int randomLED = random(5);
    digitalWrite(getLEDFromIndex(randomLED), HIGH);
    delay(100);
    digitalWrite(getLEDFromIndex(randomLED), LOW);
  }
}

void gameOver() {
  while (true) {
    turnAllLEDs(HIGH);
    delay(200);
    turnAllLEDs(LOW);
    delay(200);
  }
}

void turnAllLEDs(int state) {
  digitalWrite(pin0, state);
  digitalWrite(pin1, state);
  digitalWrite(pin2, state);
  digitalWrite(pin3, state);
  digitalWrite(pin4, state);
}

int getLEDFromIndex(int index) {
  switch (index) {
    case 0: return pin0;
    case 1: return pin1;
    case 2: return pin2;
    case 3: return pin3;
    case 4: return pin4;
  }
  return -1;
}