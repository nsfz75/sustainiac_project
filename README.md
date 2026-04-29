# Sustainiac Wireless Mode Controller

A wireless control system for switching modes on a Sustainiac humbucker pickup using two Arduino-based units communicating via **OOK / ASK RF transmission**.

The project consists of:

- **TX Unit (Transmitter)** – Sends wireless commands to select Sustainiac modes.
- **RX Unit (Receiver)** – Receives commands and switches the Sustainiac control lines accordingly.

This allows remote mode selection without hardwiring traditional switches.

---

## Project Overview

The transmitter sends encoded **OOK (On-Off Keying) / ASK (Amplitude Shift Keying)** pulse signals over a low-cost RF transmitter module.

The receiver listens for incoming pulse timings and interprets them as mode commands.

Once decoded, the receiver switches output MOSFETs / control lines connected to the Sustainiac humbucker system.

---

## Supported Modes

The receiver supports four Sustainiac operating states:

| Mode | Function |
|------|----------|
| Passive | Pickup operates normally |
| Sustain | Fundamental sustain mode |
| Harmonic | Harmonic feedback mode |
| Blend | Mixed sustain mode |

---

## Hardware Render

### Sustainiac Guard
![3D rendering of Sustainiac Guard](assets/sustainiac_rx_guard.gif)

### Sustainiac Box
![3D rendering of Sustainiac Box](assets/sustainiac_tx_box.gif)