//    👻 
//
// Created by AlxBilt on 12/1/2026
// SPDX-License-Identifier: MPL-2.0
#pragma once

/******************************************************************************
*  GLOBAL SYSTEM CONFIGURATION (V4.0)
*****************************************************************************/

// -----------------------------
// MAIN MODE SELECTION
// -----------------------------
// -----------------------------
// CAN BUS SETTINGS
// -----------------------------
#define CAN1_BAUDRATE      500000     // Cummins or source bus
#define CAN2_BAUDRATE      500000     // Ford or target vehicle network bus
#define CAN3_BAUDRATE      500000     // Ford PCM isolated

// The Cummins bus provides data, so don't enable both with 0x215 speed at same time
#define CUMMINS_BUS_INPUT
#ifdef CUMMINS_BUS_INPUT
#endif

// Enable Ford PCM bus input module
#define FORD_BUS_INPUT
#ifdef FORD_BUS_INPUT
#endif

// Enable deny-list filtering for Ford CAN gateway
//#define FORD_DENYLIST_ENABLE

 // Enable Ford Vehicle Bus
 #define FORD_VEHICLE_BUS_INPUT
 #ifdef FORD_VEHICLE_BUS_INPUT
 #endif




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
#define BLINK_OUTPUT
#ifdef BLINK_OUTPUT
#endif

//#define ENABLE_SD_LOGGING
#ifdef ENABLE_SD_LOGGING
#endif

// Enable J1939 receiver
//#define J1939_BUS_INPUT
#ifdef J1939_BUS_INPUT
#endif

// -----------------------------
// GPIO CONFIGURATION
// -----------------------------
//#define SPEEDOMETER_INPUT   // Pulse input pin 5 from wheel sensor
#ifdef  SPEEDOMETER_INPUT
#define SPEEDOMETER_INPUT_CLICKS_PER_MILE   8000
#endif

// -----------------------------
// SPEEDOMETER SETTINGS
// -----------------------------
// enable if you want a speedometer out on pin 2
//#define SPEEDOMETER_OUTPUT
#ifdef  SPEEDOMETER_OUTPUT
#define SPEEDOMETER_OUTPUT_CLICKS_PER_MILE 8000
#endif
// -----------------------------
// FEATURE ENABLES
// (Modules still compile; runtime determines active mode)
// -----------------------------

// #define ENABLE_SD_LOGGING
// #define PIN_SD_CS          10  // SD card CS pin



