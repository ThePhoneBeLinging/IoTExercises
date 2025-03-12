
const byte pin1 = 9; 
const byte pin2 = 8;
const byte pin3 = 12;
const byte pin4 = 7; 
const byte pin5 = 10;
const byte pin6 = 13;
const byte pin7 = 11;
const byte pin8 = 1;

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


const int pin10 = 2;
const int pin11 = 3;
const int pin12 = 4;
const int pin13 = 5;
const int pin14 = 6;
const byte buttonPin = A0;
int multiplier = 1;
int activeLED = -1;
bool pressed = false;
int correctAnswers = 0;


void setup() {
  pinMode(pin10, OUTPUT);
  pinMode(pin11, OUTPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin13, OUTPUT);
  pinMode(pin14, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(0,OUTPUT);
  allOff();
  drawZero();
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
  if (analogRead(buttonPin) > 200) {
    pressed = true;
    if (activeLED == 2) {
      correctAnswers++;
      multiplier++;
      indicateSuccess();
    } else {
      indicateFailure();
    }
    allOff();
    // Update the display to show current correct answers count
    switch (correctAnswers) 
    {
      case 0:
      {
        drawZero();
      }
      case 1:
      {
        drawOne();
        break;
      }
      case 2:
      {
        drawTwo();
        break;
      }
      case 3:
      {
        drawThree();
        break;
      }
      case 4:
      {
        drawFour();
        break;
      }
      case 5:
      {
        drawFive();
        break;
      }
      case 6:
      {
        drawSix();
        break;
      }
      case 7:
      {
        drawSeven();
        break;
      }
      case 8:
      {
        drawEight();
        break;
      }
      case 9:
      {
        drawNine();
        break;
      }
    }
    return true;
  }
  return false;
}

// Play the success sound
void indicateSuccess() {
  tone(0,880,500);
  turnAllLEDs(LOW);
  delay(1000);
}

// Play the failure sound
void indicateFailure() {
  tone(0,440,500);
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
    drawZero();
    delay(200);
    turnAllLEDs(LOW);
    allOff();
    delay(200);
  }
}

void turnAllLEDs(int state) {
  digitalWrite(pin10, state);
  digitalWrite(pin11, state);
  digitalWrite(pin12, state);
  digitalWrite(pin13, state);
  digitalWrite(pin14, state);
}

int getLEDFromIndex(int index) {
  switch (index) {
    case 0: return pin10;
    case 1: return pin11;
    case 2: return pin12;
    case 3: return pin13;
    case 4: return pin14;
  }
  return -1;
}