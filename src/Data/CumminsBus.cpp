/*
 * SPDX-License-Identifier: MPL-2.0
 * ECHO / WRAITH
 * Copyright (c) 2026 AlxBilt
 *
 * Portions of the J1939 parsing logic are derived from:
 * OPCM | OSSM
 * Copyright (c) 2025 Joshua Austill
 * Licensed under the MIT License.
 *
 * See THIRD_PARTY_LICENSES/OPCM/LICENSE
 */
// Data input from Cummins ECM on CAN 1
//    👻 
//
// Created by AlxBilt on 12/10/25.
// SPDX-License-Identifier: MPL-2.0
#include "Config/configuration.h"
#ifdef CUMMINS_BUS_INPUT
#include <FlexCAN_T4.h>
#include "canDriver.h"
#include <Arduino.h>
#include "CumminsBus.h"
Bus CumminsBus::outBus = CANBUS_1;      // Output to CAN1 by default

//=====================================================================================//

// -------------------------
// 29-Bit J1939 Static member definitions
// -------------------------
  #ifdef J1939_BUS_INPUT
    uint8_t CumminsBus::data61443[8] = {0};   // EEC2 - Engine Electronics COntrol 2 (50 ms preferred / 100 ms)
 /* FILL IN CUSTOM DEFINITIONS*/

  #endif // J1939_BUS_INPUT
// -------------------------
// 11-Bit Static member definitions
// -------------------------

 /* FILL IN CUSTOM DEFINITIONS*/


// CAN data for OBD2 SCANNER
    uint8_t  CumminsBus::data7E0[8] = {0}; // OBD Scanner request
    
 /* FILL IN CUSTOM DEFINITIONS*/

    uint8_t  CumminsBus::data18DB33F1[8] = {0}; // OBD Scanner Request

  uint32_t CumminsBus::lastRequest = 0;

//static float battVolt;

// =========================
// Handle Incoming CAN Messages
// =========================

void CumminsBus::CumminsBusSniff(const CAN_message_t & msg) {

  
/*
J1939 29-bit CAN Identifier

0x18 F0 04 00
 │   │  │  │
 │   │  │  └── Source Address (SA)
 │   │  └───── PDU Specific (PS)
 │   └──────── PDU Format (PF)
 └──────────── Priority + Control Bits
*/

  #ifdef J1939_BUS_INPUT
  if(msg.flags.extended) {
    
  // J1939 Decoder 
  // Created by jlaustill on 7/4/21.
  // https://github.com/jlaustill
  
    uint8_t pf = (msg.id >> 16) & 0xFF;  // PDU Format
    uint8_t ps = (msg.id >> 8)  & 0xFF;  // PDU Specific
//  uint8_t src = msg.id & 0xFF;         // Source Address (Sender) not needed

    uint16_t pgn = ((uint16_t)pf << 8) | ps;

    switch(pgn) {

      /*
J1939 Decode Flow

29-bit CAN Frame
        │
        ▼
Extract PF + PS
        │
        ▼
Create PGN
        │
        ▼
switch(PGN)
        │
        ▼
PGN tells us how to interpret the 8 data bytes.
PGN 65262 (ET1)
        │
        ▼
SPN
┌─────────────────────────────────────────────┐
│ Byte 0 │ Byte 1 │ Byte 2 │ Byte 3 │ ...     │
└─────────────────────────────────────────────┘
    │         │        └──────┐
    │         │               │
    │         │           SPN 175
    │         │          Oil Temp
    │         │
    │     SPN 174
    │     Fuel Temp
    │
SPN 110
Coolant Temp
*/
    case 61443:   // EEC2 - Engine Electronics COntrol 2 (50 ms preferred / 100 ms)

      CumminsBus::data61443[0] = msg.buf[0];  // SPN 558  Accelerator Pedal Low Idle Switch; 
        /* FILL IN CUSTOM DEFINITIONS*/

    return;

    
    default:
    return; 
    }

  }

  #endif // J1939_BUS_INPUT
  
   switch(msg.id)  {

 
 case 0x7E0: // MAX31856 EGT Custom PID Torque Pro
    CumminsBus::data7E0[0] = msg.buf[0];    // ?  see excell sheet in XoRbit Tool Folder
      /* FILL IN CUSTOM DEFINITIONS*/
  return; 

   
   default: 
   // Uncomment only when debugging missing IDs
   //Serial.println(" Missing CUMMINS CAN Data. Please check setup. \n");   
  break;     

//  Serial.print(" ID: ");
//  Serial.print(msg.id, HEX);
//  Serial.print(" Data: ");    
//  Serial.printf("ID: %03X DATA: ", msg.id); // merge upper 3 serial print
//  for ( uint8_t i = 0; i < msg.len; i++ ) {
//  Serial.print(msg.buf[i], HEX);
//  Serial.print(" ");
  }
//  Serial.println();

}

// =================================================================================
// Getters  Getters Getters Getters Getters Getters Getters Getters Getters
// =================================================================================

/*
The key mental model
& mask → Read (check bits)
|= mask → turn bits ON
&= ~mask → turn bits OFF
& 0x00 → throw everything away
*/


  void CumminsBus::initialize() {
  // Serial.begin(115200);
  Serial.println("AlxBilt Cummins Input-Bus- initializing CAN 1");
  }

  void CumminsBus::loop() {  // request PGN's every 1 second
    uint32_t currentMillis = millis();
    if (currentMillis - lastRequest >= 1000) {
  // Print the observed frame
          lastRequest = currentMillis;
    //Serial.println("1 second tick");  // placeholder
    }
  }

/****************************************************************************************************************************************
  END OF PROGRAM                                                    
****************************************************************************************************************************************/
#endif // CUMMINS_BUS_INPUT

