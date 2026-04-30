/*
  Modes:
  Passive = <=500us
  Sustain = 501-1200us
  Blend = 1201-2000us
  Harmonic = 2001-3000us

  Example buttons:
  BTN1 = Passive
  BTN2 = Sustain
  BTN3 = Blend
  BTN4 = Harmonic
*/

const int tx_pin = 7;

//----- Buttons -----//
const int btn_passive  = 2;
const int btn_sustain  = 3;
const int btn_blend    = 4;
const int btn_harmonic = 5;

//----- Timing (us) -----//
const int bit_time = 500;
const int repeats  = 3;

//----- Mode encoding (2-bit) -----//
enum Mode {
  PASSIVE  = 0b00,
  SUSTAIN  = 0b01,
  BLEND    = 0b10,
  HARMONIC = 0b11
};

void setup() {
  pinMode(tx_pin, OUTPUT);
  digitalWrite(tx_pin, LOW);

  pinMode(btn_passive, INPUT_PULLUP);
  pinMode(btn_sustain, INPUT_PULLUP);
  pinMode(btn_blend, INPUT_PULLUP);
  pinMode(btn_harmonic, INPUT_PULLUP);
}

void loop() {

  if (digitalRead(btn_passive) == LOW) {
    sendFrame(PASSIVE);
    delay(150);
  }
  else if (digitalRead(btn_sustain) == LOW) {
    sendFrame(SUSTAIN);
    delay(150);
  }
  else if (digitalRead(btn_blend) == LOW) {
    sendFrame(BLEND);
    delay(150);
  }
  else if (digitalRead(btn_harmonic) == LOW) {
    sendFrame(HARMONIC);
    delay(150);
  }
}

//----- Send frame  -----//
void sendFrame(Mode mode) {

  for (int r = 0; r < repeats; r++) {

    sendPreamble();

    sendBit((mode >> 1) & 1);
    sendBit(mode & 1);

    delayMicroseconds(bit_time * 4);
  }
}

//----- Sync pattern -----//
void sendPreamble() {
  for (int i = 0; i < 8; i++) {
    sendBit(i % 2);  // 10101010
  }
}

//----- OOK bit transmission -----//
void sendBit(bool bitVal) {

  digitalWrite(tx_pin, HIGH);

  if (bitVal) {
    delayMicroseconds(bit_time);
  } else {
    delayMicroseconds(bit_time / 2);
  }

  digitalWrite(tx_pin, LOW);
  delayMicroseconds(bit_time);
}