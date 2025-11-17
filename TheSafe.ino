#include <Servo.h>
#include <Keypad.h>

Servo servo;
int angle = 10;
bool open = false;
bool closed = false;

// Correct initialization of arrays
int user[5] = {0, 0, 0, 0, 0};
int correct[5] = {3, 1, 4, 1, 5};

int count = 0;

// Keypad setup
const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  servo.attach(10); // Changed to pin 10 to avoid conflict
  servo.write(angle);
}

void loop() {
  char customKey = customKeypad.getKey();

  if (customKey) {
    // If '#' is pressed, check the password
    if (customKey == '#') {
      Serial.print("Entered: ");
      for (int i = 0; i < 5; i++) {
        Serial.print(user[i]);
      }
      Serial.println();

      // Compare arrays
      bool isEqual = true;
      for (int i = 0; i < 5; i++) {
        if (user[i] != correct[i]) {
          isEqual = false;
          break;
        }
      }

      if (isEqual) {
        open = true;
        closed = false;
        Serial.println("Correct Code: OPENING");
      } else {
        Serial.println("Incorrect Code");
      }

      // Reset input
      count = 0;
      for (int i = 0; i < 5; i++) {
        user[i] = 0;
      }
    }

    // If '*' is pressed, close the servo
    else if (customKey == '*') {
      closed = true;
      open = false;
      Serial.println("CLOSING");
      count = 0;
      for (int i = 0; i < 5; i++) {
        user[i] = 0;
      }
    }

    // Otherwise, store the digit
    else {
      if (count < 5) {
        Serial.print("Key Pressed: ");
        Serial.println(customKey);
        user[count] = customKey - '0'; // Convert char to int
        Serial.print("Stored: ");
        Serial.println(user[count]);
        count++;
      }
    }
  }

  // Handle opening servo
  if (open) {
    for (angle = 0; angle <= 95; angle++) {
      servo.write(angle);
      delay(10);
    }
    open = false; // Stop continuous loop
  }

  // Handle closing servo
  if (closed) {
    for (angle = 95; angle >= 0; angle--) {
      servo.write(angle);
      delay(10);
    }
    closed = false; // Stop continuous loop
  }
}
