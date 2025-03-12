/* The code below was provided by ChatGPT-4-turbo using the prompt:

"Exercise13: Catchthe LED gamePart 
A)
•  Modify ”Blink” to ”StopIt”, and the game should do the following:
•  5 LEDsflash consecutively, one after the other
•  Press the button when the middle LED is lit up
•  Indicate with LEDs if   answer is    correct(all lights blink fast) or incorrect(all lights off)
•  Print the result(succes counter) to serialmonitor Increase”succes counter”
•  If correctanswer, LEDs should start to blink consecutively faster
•  If ”successcounter” equals 8, lightsshouldstart to flash randomly
•  Game ends when”successcounter” reaches 10

Can you give me the code for this?"

Looking at the code we see some key takeaways regarding the quality:

- There can be some timing issues regarding the buttonpress and the LED flash. 
  Since a delay is used before reading from buttonPin, if the LED is lit and the button is pressed during the delay, this wont be registered.
  
- furthermore digitalRead(BUTTON_PIN) == LOW is used instead of HIGH, 
  meaning that the code actually checks if the button has not been pressed, resulting in an incorrect game state

- a couple of things that the AI code does better than our code, is that it is significantly more compact, and uses a lot more for loops
  we however find this to reduce readability, and prefer our solution. We do not feel that the AI code
  has "clever solutions" that we have not used ourselves. Apart from that our code and the AI code is quite similar. We have split
  the functionality into many of the same functions, which works in mostly the same ways.

- Lastly we also see that the AI has assumed some things regarding the assignment, that differed from our approach.
  This includes the delayTime

- Other than this the solution looks fine and actually more compact than our code. You just have to be wary when using AI generated code,
  as it makes assumptions and almost always make small mistakes.

We did not experience any difficulties making the AI write "propper code". It, as stated above, had some flaws, 
but it generated a mostly functional program using a single prompt, that could be fixed with a little debugging.
*/

#define NUM_LEDS 5
#define BUTTON_PIN 2
#define SUCCESS_LIMIT 10

int leds[NUM_LEDS] = {3, 4, 5, 6, 7}; // LED pins
int successCounter = 0;
int delayTime = 300; // Initial speed

void setup() {
    for (int i = 0; i < NUM_LEDS; i++) {
        pinMode(leds[i], OUTPUT);
    }
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    Serial.begin(9600);
}

void loop() {
    int middleLED = NUM_LEDS / 2; // Middle LED index
    bool caught = false;

    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(leds[i], HIGH);
        delay(delayTime);

        if (i == middleLED && digitalRead(BUTTON_PIN) == LOW) {
            caught = true;
        }
        digitalWrite(leds[i], LOW);
    }

    if (caught) {
        successCounter++;
        Serial.print("Success: ");
        Serial.println(successCounter);
        blinkFast(3);
        delayTime = max(50, delayTime - 30); // Increase speed
    } else {
        allLightsOff();
    }

    if (successCounter >= 8) {
        randomFlashing();
    }

    if (successCounter >= SUCCESS_LIMIT) {
        endGame();
    }
}

void blinkFast(int times) {
    for (int i = 0; i < times; i++) {
        for (int j = 0; j < NUM_LEDS; j++) {
            digitalWrite(leds[j], HIGH);
        }
        delay(100);
        for (int j = 0; j < NUM_LEDS; j++) {
            digitalWrite(leds[j], LOW);
        }
        delay(100);
    }
}

void allLightsOff() {
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(leds[i], LOW);
    }
}

void randomFlashing() {
    for (int i = 0; i < 10; i++) {
        digitalWrite(leds[random(NUM_LEDS)], HIGH);
        delay(100);
        allLightsOff();
        delay(100);
    }
}

void endGame() {
    for (int i = 0; i < 5; i++) {
        blinkFast(1);
        delay(200);
    }
    while (true);
}

