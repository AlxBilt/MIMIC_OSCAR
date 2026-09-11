//
// Created by jlaustill on 7/6/21.
// https://github.com/jlaustill
//
// Created by jlaustill on 7/20/21.
// https://github.com/jlaustill
/*
 * SPDX-License-Identifier: MPL-2.0
 * ECHO / WRAITH
 * Copyright (c) 2026 AlxBilt
 *
 * Portions of the parsing logic are derived from:
 * OPCM | OSSM
 * Copyright (c) 2025 Joshua Austill
 * Licensed under the MIT License.
 *
 * See THIRD_PARTY_LICENSES/OPCM/LICENSE
 */

#include "Config/configuration.h"

#ifdef SPEEDOMETER_OUTPUT

#include <Arduino.h>
// #include <TimerFour.h>
#include "Speedometer.h"

// Create an IntervalTimer object 
IntervalTimer speedoTimer;
int speedoState = LOW;

void speedoSignal() {
    if (speedoState == LOW) {
        speedoState = HIGH;
    } else {
        speedoState = LOW;
    }
    digitalWrite(2, speedoState);
}

Speedometer::Speedometer(int _clicksPerMile) {
    this->mph = 0;
}

void Speedometer::initialize() const {
    pinMode(2, OUTPUT);
    digitalWrite(2, HIGH);
    speedoTimer.begin(speedoSignal, 150000);
}

void Speedometer::SetMph(int _mph) {
    this->mph = _mph;
    long microseconds = Speedometer::MphToMicroseconds(this->mph);
    // Serial.print("setMPH: "); Serial.print(_mph); Serial.print(" micros: "); Serial.println(microseconds);
    speedoTimer.update(microseconds / 2);
    // double hertz = (double)_mph * SPEEDOMETER_OUTPUT_CLICKS_PER_MILE / 60 / 60;
    // tone(2, hertz);
//    Serial.println("mph: " + (String)this->mph);
//    Serial.println("microseconds: " + (String)microseconds);
//    Serial.println();
    // Timer4.setPeriod(microseconds);
}

long Speedometer::MphToMicroseconds(int _mph) {
    double hertz = (double)_mph * SPEEDOMETER_OUTPUT_CLICKS_PER_MILE / 60 / 60;
//    Serial.println("hertz: " + (String)hertz);
    long microseconds = Speedometer::HertzToMicroseconds(hertz);
//    Serial.println("microseconds: " + (String(microseconds)));
    return microseconds;
}

long Speedometer::HertzToMicroseconds(double _hz) {
    double duration;
    duration = 1.000000000 / _hz;
    return (long)(duration * 1000000.0);
}

#endif
