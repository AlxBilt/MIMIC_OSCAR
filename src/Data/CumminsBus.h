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
//
// Created by AlxBilt on 12/101/25.
// SPDX-License-Identifier: MPL-2.0
#pragma once
#include <Arduino.h>
#include <FlexCAN_T4.h>
#include "canDriver.h"

/*
 * Cummins CAN Module
 * ------------------
 * Collects and decodes Cummins ECM frames received on CAN1.
 * Stores raw bytes from each known ID.
 *
 * Provides clean getter functions for:
 *   - Speed (raw /128, kph, mph)
 *   - RPM
 *   - ECT / IAT
 *   - MAP
 *   - Oil pressure
 *   - Cruise On / Cruise Active
 *
 * Gateway reads these values and converts them to Ford frames.
 */


#ifdef CUMMINS_BUS_INPUT
class CumminsBus {
 public:

// ======================================================
// Sniffer — call from CAN1.onReceive() by GatewayModule::handleCanRx()
// ======================================================
   
  static void initialize();
  static void loop();
  static void CumminsBusSniff(const CAN_message_t& msg);


    
   // =========================
   // Getters
   // =========================
    



//=====================================================================================//

// -------------------------
// 29-Bit J1939 Static member declarations
// -------------------------
  #ifdef J1939_BUS_INPUT
    static uint8_t data61443[8];  // EEC2 - Engine Electronics COntrol 2 (50 ms preferred / 100 ms)
      /* FILL IN CUSTOM DEFINITIONS*/
#endif // J1939_BUS_INPUT
// -------------------------
// 11-Bit Static member declarations
// -------------------------

  static uint8_t data7E0[8]; // OBD2 Scanner
      /* FILL IN CUSTOM DECLARATIONS*/

  static uint8_t data18DB33F1[8]; // OBD2 Scanner
     static uint32_t lastRequest;

private:
         static Bus outBus;
};
 

#endif  // CUMMINS_BUS_INPUT