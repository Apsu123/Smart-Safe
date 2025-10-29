# 🔐 Arduino Keypad Servo Lock System


A simple yet effective **keypad-controlled servo lock** built with Arduino.  
Enter a **5-digit passcode** to unlock your servo-driven lock mechanism — ideal for boxes, doors, or safes.

---

## 🧩 Features

- 🔢 4x4 keypad input system  
- 🔐 5-digit passcode authentication  
- ⚙️ Servo-based lock/unlock mechanism  
- 🧠 Serial output for debugging and feedback  
- ✳️ Reset or close lock with a single key press  

---

## ⚙️ Hardware Requirements

| Component | Quantity | Description |
|------------|-----------|-------------|
| Arduino Uno / Nano / Mega | 1 | Main microcontroller |
| 4x4 Matrix Keypad | 1 | Input interface |
| Servo Motor (SG90 / MG996R) | 1 | Lock actuator |
| Jumper Wires | — | For wiring |
| Breadboard | 1 | Optional for prototyping |

---

## 🔌 Pin Configuration

| Component | Arduino Pin | Description |
|------------|--------------|-------------|
| **Servo Signal** | 10 | Controls servo position |
| **Keypad Rows** | 9, 8, 7, 6 | Row connections |
| **Keypad Columns** | 5, 4, 3, 2 | Column connections |

---

## 🧠 Code Overview

### 1️⃣ Initialization
- Sets up servo and keypad in `setup()`
- Servo starts at angle 10° (neutral)

### 2️⃣ Input Collection
- Each key press adds a digit to the `user[]` array
- Input resets after every check or close command

### 3️⃣ Passcode Verification
When `#` is pressed:
```cpp
int correct[5] = {3, 1, 4, 1, 1};

If match → servo opens

Else → “Incorrect Code” message

4️⃣ Lock Command

Press * to close the lock (servo rotates back).

5️⃣ Servo Movement

Open: 0° → 95°

Close: 95° → 0°

🔢 Default Passcode
3 1 4 1 1


To change it, edit this line:

int correct[5] = {3, 1, 4, 1, 1};

🧭 Keypad Controls
Key	Function
0-9	Enter digits
#	Check code / Unlock
*	Close / Reset
🖥️ Serial Monitor Output Example
Key Pressed: 3
Stored: 3
Key Pressed: 1
Stored: 1
Key Pressed: 4
Stored: 4
Key Pressed: 1
Stored: 1
Key Pressed: 1
Stored: 1
Entered: 31411
Correct Code: OPENING

⚡ Setup Instructions

Connect components as per the pin configuration

Open the sketch in Arduino IDE

Install required libraries (see below)

Select your Arduino board and COM port

Upload the code

Open Serial Monitor (9600 baud) and test your keypad input

🧰 Dependencies

Install these from the Arduino IDE Library Manager:

Servo.h

Keypad.h

🚀 Future Enhancements

🖲️ Add an LCD screen for user feedback

💾 Save passcode to EEPROM (non-volatile memory)

🔔 Add buzzer or LED indicators

⏱️ Add timeout or limited attempts for extra security

🏁 License

This project is released under the MIT License.
You are free to use, modify, and distribute it with attribution.
