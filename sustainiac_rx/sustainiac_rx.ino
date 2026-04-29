 // Pins
const int signal_pin = 2;       // Input from OOK receiver
const int mosfet_1_pin = 3;      // MOSFET control pin for mode 1
const int mosfet_2_pin = 4;      // MOSFET control pin for mode 2
const int mosfet_3_pin = 5;      // MOSFET control pin for mode 3

// Timing thresholds
const unsigned long pulse_passive_max   = 500;    // up to 500us = Passive/Off
const unsigned long pulse_sustain_max   = 1200;   // 501-1200us = Sustain
const unsigned long pulse_harmonic_max  = 2000;   // 1201-2000us = Harmonic
const unsigned long pulse_blend_max     = 3000;   // 2001-3000us = Blend

// Timeout in milliseconds
const unsigned long signal_timeout = 500;  // default to Passive if no signal for 500ms

unsigned long last_signal_time = 0;

void setup() {
  pinMode(signal_pin, INPUT);
  pinMode(mosfet_1_pin, OUTPUT);
  pinMode(mosfet_2_pin, OUTPUT);
  pinMode(mosfet_3_pin, OUTPUT);
  
  // Start in Passive mode
  set_mode_passive();
}

void loop() {
  unsigned long pulse = pulseIn(signal_pin, HIGH, 4000); // wait max 4ms for pulse
  if (pulse > 0) {
    last_signal_time = millis();
    if (pulse <= pulse_passive_max) {
      set_mode_passive();
    } else if (pulse <= pulse_sustain_max) {
      set_mode_sustain();
    } else if (pulse <= pulse_harmonic_max) {
      set_mode_harmonic();
    } else if (pulse <= pulse_blend_max) {
      set_mode_blend();
    } 
  }

  // Check for timeout
  if (millis() - last_signal_time > signal_timeout) {
    set_mode_passive();
  }
}

// Mode functions
void set_mode_passive() {
  digitalWrite(mosfet_1_pin, LOW);
  digitalWrite(mosfet_2_pin, LOW);
  digitalWrite(mosfet_3_pin, LOW);
}

void set_mode_sustain() {
  digitalWrite(mosfet_1_pin, HIGH);
  digitalWrite(mosfet_2_pin, LOW);
  digitalWrite(mosfet_3_pin, LOW);
}

void set_mode_harmonic() {
  digitalWrite(mosfet_1_pin, LOW);
  digitalWrite(mosfet_2_pin, HIGH);
  digitalWrite(mosfet_3_pin, LOW);
}

void set_mode_blend() {
  digitalWrite(mosfet_1_pin, LOW);
  digitalWrite(mosfet_2_pin, LOW);
  digitalWrite(mosfet_3_pin, HIGH);
}