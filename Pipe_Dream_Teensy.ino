// Define global variables
byte targetNote1 = 96; // C6
byte targetNote2 = 97; // C#6
byte targetNote3 = 98; // D6
byte targetNote4 = 99; // D#6
byte targetNote5 = 100; // E6
byte targetNote6 = 101; // F6
byte targetNote7 = 102; // F#6
byte targetNote8 = 103; // G6
byte targetNote9 = 104; // G#6
byte targetNote10 = 105; // A6
byte targetNote11 = 106; // A#6
byte targetNote12 = 107; // B6

bool isModulating1 = false; // Flag for modulation loop on pin 22
bool isModulating2 = false; // Flag for modulation on pin 21
bool isModulating3 = false; // Flag for modulation loop on pin 20
bool isModulating4 = false; // Flag for modulation on pin 19
bool isModulating5 = false; // Flag for modulation loop on pin 18
bool isModulating6 = false; // Flag for modulation on pin 17
bool isModulating7 = false; // Flag for modulation loop on pin 16
bool isModulating8 = false; // Flag for modulation on pin 15
bool isModulating9 = false; // Flag for modulation loop on pin 14
bool isModulating10 = false; // Flag for modulation on pin 13
bool isModulating11 = false; // Flag for modulation loop on pin 12
bool isModulating12 = false; // Flag for modulation on pin 11

void setup() {
  pinMode(1, OUTPUT); // Set pin 1 as output for modulation 1
  pinMode(2, OUTPUT); // Set pin 2 as output for modulation 2
  pinMode(3, OUTPUT); // Set pin 3 as output for modulation 3
  pinMode(4, OUTPUT); // Set pin 4 as output for modulation 4
  pinMode(5, OUTPUT); // Set pin 5 as output for modulation 5
  pinMode(6, OUTPUT); // Set pin 6 as output for modulation 6
  pinMode(7, OUTPUT); // Set pin 7 as output for modulation 7
  pinMode(8, OUTPUT); // Set pin 8 as output for modulation 8
  pinMode(17, OUTPUT); // Set pin 17 as output for modulation 9
  pinMode(18, OUTPUT); // Set pin 18 as output for modulation 10
  pinMode(19, OUTPUT); // Set pin 19 as output for modulation 11
  pinMode(20, OUTPUT); // Set pin 20 as output for modulation 12
  
  Serial.begin(115200); // Initialize serial communication
  while (!Serial); // Wait for Serial Monitor to open
  Serial.println("Teensy initialized.");
  usbMIDI.setHandleNoteOn(handleNoteOn); // Set MIDI note-on handler
  usbMIDI.setHandleNoteOff(handleNoteOff); // Set MIDI note-off handler
}

void loop() {
  usbMIDI.read(); // Read incoming MIDI data
  updateModulation(); // Update modulations based on flags
}

void handleNoteOn(byte channel, byte note, byte velocity) {
  Serial.print("Note On, ch=");
  Serial.print(channel);
  Serial.print(", note=");
  Serial.print(note);
  Serial.print(", velocity=");
  Serial.println(velocity);

  if (note == targetNote1) { // Check if received note matches C6
    isModulating1 = true; // Start modulation loop for pin 1
  } 
  else if (note == targetNote2) { // Check if received note matches C#6
  isModulating2 = true; // Start modulation for pin 2
  }
  else if (note == targetNote3) { // Check if received note matches D6
  isModulating3 = true; // Start modulation for pin 3
  }
  else if (note == targetNote4) { // Check if received note matches D#6
  isModulating4 = true; // Start modulation for pin 4
  }
  else if (note == targetNote5) { // Check if received note matches E6
  isModulating5 = true; // Start modulation for pin 5
  }
  else if (note == targetNote6) { // Check if received note matches F6
  isModulating6 = true; // Start modulation for pin 6
  }
  else if (note == targetNote7) { // Check if received note matches F#6
  isModulating7 = true; // Start modulation for pin 7
  }
  else if (note == targetNote8) { // Check if received note matches G6
  isModulating8 = true; // Start modulation for pin 8
  }
  else if (note == targetNote9) { // Check if received note matches G#6
  isModulating9 = true; // Start modulation for pin 17
  }
  else if (note == targetNote10) { // Check if received note matches A6
  isModulating10 = true; // Start modulation for pin 18
  }
  else if (note == targetNote11) { // Check if received note matches A#6
  isModulating11 = true; // Start modulation for pin 19
  }
  else if (note == targetNote12) { // Check if received note matches B6
  isModulating12 = true; // Start modulation for pin 20
  }
}

void handleNoteOff(byte channel, byte note, byte velocity) {
  Serial.print("Note Off, ch=");
  Serial.print(channel);
  Serial.print(", note=");
  Serial.print(note);
  Serial.print(", velocity=");
  Serial.println(velocity);

  if (note == targetNote1) { // Check if received note matches C6
    isModulating1 = false; // Stop modulation loop for pin 1
    digitalWrite(1, LOW); // Turn off modulation for pin 1
  } 
  else if (note == targetNote2) { // Check if received note matches C#6
    isModulating2 = false; // Stop modulation for pin 2
    digitalWrite(2, LOW); // Turn off modulation for pin 2
  }
  else if (note == targetNote3) { // Check if received note matches D6
    isModulating3 = false; // Stop modulation for pin 3
    digitalWrite(3, LOW); // Turn off modulation for pin 3
  }
  else if (note == targetNote4) { // Check if received note matches D#6
    isModulating4 = false; // Stop modulation for pin 4
    digitalWrite(4, LOW); // Turn off modulation for pin 4
  }
  else if (note == targetNote5) { // Check if received note matches E6
    isModulating5 = false; // Stop modulation for pin 5
    digitalWrite(5, LOW); // Turn off modulation for pin 5
  }
  else if (note == targetNote6) { // Check if received note matches F6
    isModulating6 = false; // Stop modulation for pin 6
    digitalWrite(6, LOW); // Turn off modulation for pin 6
  }
  else if (note == targetNote7) { // Check if received note matches F#6
    isModulating7 = false; // Stop modulation for pin 7
    digitalWrite(7, LOW); // Turn off modulation for pin 7
  }
  else if (note == targetNote8) { // Check if received note matches G6
    isModulating8 = false; // Stop modulation for pin 8
    digitalWrite(8, LOW); // Turn off modulation for pin 8
  }
  else if (note == targetNote9) { // Check if received note matches G#6
    isModulating9 = false; // Stop modulation for pin 17
    digitalWrite(17, LOW); // Turn off modulation for pin 17
  }
  else if (note == targetNote10) { // Check if received note matches A6
    isModulating10 = false; // Stop modulation for pin 18
    digitalWrite(18, LOW); // Turn off modulation for pin 18
  }
  else if (note == targetNote11) { // Check if received note matches A#6
    isModulating11 = false; // Stop modulation for pin 19
    digitalWrite(19, LOW); // Turn off modulation for pin 19
  }
  else if (note == targetNote12) { // Check if received note matches B6
    isModulating12 = false; // Stop modulation for pin 20
    digitalWrite(20, LOW); // Turn off modulation for pin 20
  }
}

void updateModulation() {
  if (isModulating1) { // Check if modulation loop for pin 1 should continue
    int period = 955; // Modulation period (adjust as needed)
    int pwmResolution = 255; // PWM resolution (8-bit)
    int dutyCycle = pwmResolution / 2 + pwmResolution / 2 * sin(2 * PI * micros() / period);

    for (int i = 0; i < pwmResolution; i++) {
      if (i < dutyCycle) {
        digitalWrite(1, HIGH);
      } else {
        digitalWrite(1, LOW);
      }
    }
  }

  if (isModulating2) { // Check if modulation loop for pin 2 should continue
    int period = 901; // Modulation period (adjust as needed)
    int pwmResolution = 255; // PWM resolution (8-bit)
    int dutyCycle = pwmResolution / 2 + pwmResolution / 2 * sin(2 * PI * micros() / period);

    for (int i = 0; i < pwmResolution; i++) {
      if (i < dutyCycle) {
        digitalWrite(2, HIGH);
      } else {
        digitalWrite(2, LOW);
      }
    }
  }

  if (isModulating3) { // Check if modulation loop for pin 3 should continue
    int period = 851; // Modulation period (adjust as needed)
    int pwmResolution = 255; // PWM resolution (8-bit)
    int dutyCycle = pwmResolution / 2 + pwmResolution / 2 * sin(2 * PI * micros() / period);

    for (int i = 0; i < pwmResolution; i++) {
      if (i < dutyCycle) {
        digitalWrite(3, HIGH);
      } else {
        digitalWrite(3, LOW);
      }
    }
  }

  if (isModulating4) { // Check if modulation loop for pin 4 should continue
    int period = 803; // Modulation period (adjust as needed)
    int pwmResolution = 255; // PWM resolution (8-bit)
    int dutyCycle = pwmResolution / 2 + pwmResolution / 2 * sin(2 * PI * micros() / period);

    for (int i = 0; i < pwmResolution; i++) {
      if (i < dutyCycle) {
        digitalWrite(4, HIGH);
      } else {
        digitalWrite(4, LOW);
      }
    }
  }

  if (isModulating5) { // Check if modulation loop for pin 5 should continue
    int period = 758; // Modulation period (adjust as needed)
    int pwmResolution = 255; // PWM resolution (8-bit)
    int dutyCycle = pwmResolution / 2 + pwmResolution / 2 * sin(2 * PI * micros() / period);

    for (int i = 0; i < pwmResolution; i++) {
      if (i < dutyCycle) {
        digitalWrite(5, HIGH);
      } else {
        digitalWrite(5, LOW);
      }
    }
  }

  if (isModulating6) { // Check if modulation loop for pin 6 should continue
    int period = 716; // Modulation period (adjust as needed)
    int pwmResolution = 255; // PWM resolution (8-bit)
    int dutyCycle = pwmResolution / 2 + pwmResolution / 2 * sin(2 * PI * micros() / period);

    for (int i = 0; i < pwmResolution; i++) {
      if (i < dutyCycle) {
        digitalWrite(6, HIGH);
      } else {
        digitalWrite(6, LOW);
      }
    }
  }

  if (isModulating7) { // Check if modulation loop for pin 7 should continue
    int period = 676; // Modulation period (adjust as needed)
    int pwmResolution = 255; // PWM resolution (8-bit)
    int dutyCycle = pwmResolution / 2 + pwmResolution / 2 * sin(2 * PI * micros() / period);

    for (int i = 0; i < pwmResolution; i++) {
      if (i < dutyCycle) {
        digitalWrite(7, HIGH);
      } else {
        digitalWrite(7, LOW);
      }
    }
  }

  if (isModulating8) { // Check if modulation loop for pin 8 should continue
    int period = 638; // Modulation period (adjust as needed)
    int pwmResolution = 255; // PWM resolution (8-bit)
    int dutyCycle = pwmResolution / 2 + pwmResolution / 2 * sin(2 * PI * micros() / period);

    for (int i = 0; i < pwmResolution; i++) {
      if (i < dutyCycle) {
        digitalWrite(8, HIGH);
      } else {
        digitalWrite(8, LOW);
      }
    }
  }

  if (isModulating9) { // Check if modulation loop for pin 17 should continue
    int period = 602; // Modulation period (adjust as needed)
    int pwmResolution = 255; // PWM resolution (8-bit)
    int dutyCycle = pwmResolution / 2 + pwmResolution / 2 * sin(2 * PI * micros() / period);

    for (int i = 0; i < pwmResolution; i++) {
      if (i < dutyCycle) {
        digitalWrite(17, HIGH);
      } else {
        digitalWrite(17, LOW);
      }
    }
  }

  if (isModulating10) { // Check if modulation loop for pin 18 should continue
    int period = 568; // Modulation period (adjust as needed)
    int pwmResolution = 255; // PWM resolution (8-bit)
    int dutyCycle = pwmResolution / 2 + pwmResolution / 2 * sin(2 * PI * micros() / period);

    for (int i = 0; i < pwmResolution; i++) {
      if (i < dutyCycle) {
        digitalWrite(18, HIGH);
      } else {
        digitalWrite(18, LOW);
      }
    }
  }

  if (isModulating11) { // Check if modulation loop for pin 19 should continue
    int period = 536; // Modulation period (adjust as needed)
    int pwmResolution = 255; // PWM resolution (8-bit)
    int dutyCycle = pwmResolution / 2 + pwmResolution / 2 * sin(2 * PI * micros() / period);

    for (int i = 0; i < pwmResolution; i++) {
      if (i < dutyCycle) {
        digitalWrite(19, HIGH);
      } else {
        digitalWrite(19, LOW);
      }
    }
  }

  if (isModulating12) { // Check if modulation loop for pin 20 should continue
    int period = 506; // Modulation period (adjust as needed)
    int pwmResolution = 255; // PWM resolution (8-bit)
    int dutyCycle = pwmResolution / 2 + pwmResolution / 2 * sin(2 * PI * micros() / period);

    for (int i = 0; i < pwmResolution; i++) {
      if (i < dutyCycle) {
        digitalWrite(20, HIGH);
      } else {
        digitalWrite(20, LOW);
      }  
    }
  }
}