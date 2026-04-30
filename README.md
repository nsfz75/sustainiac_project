# Sustainiac Wireless Mode Controller

A wireless control system for switching modes on a Sustainiac humbucker pickup using two Arduino-based units communicating via **OOK / ASK RF transmission**.

---

## Motivation

This project was driven by a practical constraint: I wanted to install a Sustainiac system in a guitar with significant sentimental value, but I did not want to permanently modify the instrument by drilling additional holes for control switches.

To avoid altering the guitar body, I designed a fully wireless control solution using a dedicated transmitter and receiver architecture.

![Target arrangement](assets/guitar_mod.png)

The system consists of:
- A **transmitter unit** housed in a custom enclosure mounted on a pedalboard, powered from a 12V supply.
- A **receiver unit** integrated into a redesigned guitar back plate, powered by the guitar’s internal battery.

This approach enables full external control of Sustainiac modes, eliminating the need for additional physical switches on the instrument.

The receiver interfaces directly with the Sustainiac control lines and selects operating modes based on commands received from the transmitter.

This project demonstrates:
- Embedded systems design
- RF communication (OOK / ASK)
- Hardware/software integration
- Practical mechanical and enclosure design under real-world constraints

---

## System Overview

The project consists of:

- **TX Unit (Transmitter)** – Sends wireless commands to select Sustainiac modes
- **RX Unit (Receiver)** – Receives commands and switches Sustainiac control lines accordingly

---

## Operation

The transmitter generates encoded **OOK (On-Off Keying) / ASK (Amplitude Shift Keying)** pulse signals using a low-cost RF module.

The receiver measures incoming pulse timings and decodes them into discrete mode commands.

These commands drive MOSFET-controlled outputs connected to the Sustainiac system, enabling real-time mode switching.

---

## Supported Modes

| Mode | Function |
|------|----------|
| Passive | Pickup operates normally |
| Sustain | Fundamental sustain mode |
| Blend | Mixed sustain mode |
| Harmonic | Harmonic feedback mode |

---

## PCB Design

### Transmitter PCB
![Sustainiac Box (TX) PCB](assets/sustainiac_tx_pcb.png)

### Receiver PCB
![Sustainiac Guard (RX) PCB](assets/sustainiac_rx_pcb.png)

---

## Hardware Render

### Sustainiac Guard
![3D rendering of Sustainiac Guard](assets/sustainiac_rx_guard.gif)

### Sustainiac Box
![3D rendering of Sustainiac Box](assets/sustainiac_tx_box.gif)