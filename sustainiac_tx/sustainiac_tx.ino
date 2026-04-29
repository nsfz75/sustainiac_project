/*
  OOK Transmitter Code
  Sends pulse widths that match your receiver decoder.

  Modes:
  Passive  = <=500us
  Sustain  = 501-1200us
  Harmonic = 1201-2000us
  Blend    = 2001-3000us

  Example buttons:
  BTN1 = Passive
  BTN2 = Sustain
  BTN3 = Harmonic
  BTN4 = Blend
*/

const int tx_pin = 7;     // Data pin to OOK transmitter module

const int btn1 = 2;
const int btn2 = 3;
const int btn3 = 4;
const int btn4 = 5;

// Pulse widths matched to receiver thresholds
const unsigned int pulse_passive  = 300;
const unsigned int pulse_sustain  = 800;
const unsigned int pulse_harmonic = 1600;
const unsigned int pulse_blend    = 2600;

// Gap between repeated packets
const unsigned int repeat_gap = 5000;   // us
const int repeats = 5;

void setup() {
  pinMode(tx_pin, OUTPUT);
  digitalWrite(tx_pin, LOW);

  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(btn4, INPUT_PULLUP);
}

void loop() {

  if (digitalRead(btn1) == LOW) {
    sendCommand(pulse_passive);
    delay(150);
  }

  else if (digitalRead(btn2) == LOW) {
    sendCommand(pulse_sustain);
    delay(150);
  }

  else if (digitalRead(btn3) == LOW) {
    sendCommand(pulse_harmonic);
    delay(150);
  }

  else if (digitalRead(btn4) == LOW) {
    sendCommand(pulse_blend);
    delay(150);
  }
}


// Sends repeated HIGH pulses
void sendCommand(unsigned int pulseWidth) {

  for (int i = 0; i < repeats; i++) {

    digitalWrite(tx_pin, HIGH);
    delayMicroseconds(pulseWidth);

    digitalWrite(tx_pin, LOW);
    delayMicroseconds(repeat_gap);
  }
}