// Created by jlaustill on 7/6/24
/*MIT License

Copyright (c) 2025 Joshua Austill

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "Config/configuration.h"
#ifdef BLINK_OUTPUT

#include "BlinkOutput.h"
#include <stdint.h>
#include <Arduino.h>
uint32_t lastBlink = 0;

// Dedicated heartbeat LED.
// Pin 13 cannot be used because SPI SCK for MAX31856
// shares the onboard LED circuit on Teensy 4.1.
constexpr uint8_t HEARTBEAT_PIN = 8;
 

void BlinkOutput::initialize() {
//  pinMode(LED_BUILTIN, OUTPUT);  // Teensy 4.1 onboard LED
    pinMode(HEARTBEAT_PIN, OUTPUT);
  lastBlink = millis();
}

void BlinkOutput::blink() {
  uint32_t currentMillis = millis();
  if (currentMillis - lastBlink >= 1000) {
    lastBlink = currentMillis;
//  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));  // Toggle the LED state
    digitalWrite(HEARTBEAT_PIN,!digitalRead(HEARTBEAT_PIN));
                
  }
}

#endif  // BLINK_OUTPUT