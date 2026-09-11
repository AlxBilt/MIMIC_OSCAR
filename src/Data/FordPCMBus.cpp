//
//    👻 
//
// Created by AlxBilt on 1/12/26.
// SPDX-License-Identifier: MPL-2.0
// Data input / sniffed from Ford PCM on CAN 3
#include "Config/configuration.h"
#ifdef FORD_BUS_INPUT
#include <FlexCAN_T4.h>
#include "canDriver.h"
#include <Arduino.h>
#include "FordPCMBus.h"
Bus FordPCMBus::outBus = CANBUS_3;      // Output to CAN3 by default

//============Buffered CAN Rules======================================================//


//============Deny List===============================================================//

uint32_t FordPCMBus::rxCount = 0;
uint32_t FordPCMBus::txCount = 0;
uint32_t FordPCMBus::blockedCount = 0;

static const uint32_t denyList[] = {
 // fill in correct block list
 //   0x420,
 //   0x201,
 //   0x215,
 //   0x420,
 //   0x422,
 //   0x423
};

static const uint8_t DENY_LIST_SIZE =
sizeof(denyList) / sizeof(denyList[0]);

bool FordPCMBus::isDenied(uint32_t id)
{
    for (uint8_t i = 0; i < DENY_LIST_SIZE; i++) {
        if (denyList[i] == id) {
            return true;
        }
    }
    return false;
}

void FordPCMBus::handleMessage(const CAN_message_t &msg)
{
    rxCount++;
#ifdef FORD_DENYLIST_ENABLE
    if (isDenied(msg.id)) {
        blockedCount++;
        return;   // do not forward
    }
#endif
    forwardMessage(msg);
    txCount++;
}

//=====================================================================================//

void FordPCMBus::forwardMessage(const CAN_message_t &msg) {
    CAN_message_t outMsg = msg;      // copy
    CANDriver::send(outBus, outMsg); // send to Ford network
}


// -------------------------
// 11-Bit Static member definitions
// -------------------------

/* FILL IN CUSTOM DEFINITIONS*/


// CAN data for OBD2 SCANNER
uint8_t  FordPCMBus::data720[8] = {0}; // OBD Scanner request
      /* FILL IN CUSTOM DEFINITIONS*/

uint8_t  FordPCMBus::data18DB33F1[8] = {0}; // OBD Scanner Request

uint32_t FordPCMBus::lastRequest = 0;


// =========================
// Handle Incoming CAN Messages
// =========================

 void FordPCMBus::FordPCMBusSniff(const CAN_message_t & msg)  {
 
  switch(msg.id)
  {
    
  // Sniff donor CAN bus to determine necessary data ID | dependent on vehicle model
  
 
    case 0x720:
        FordPCMBus::data720[0] = msg.buf[0]; // 6.0  PCM ? | *PLACEHODLER
         /* FILL IN CUSTOM DEFINITIONS*/

        CANDriver::send(CANBUS_2, msg);
      return;

       /* FILL IN CUSTOM DEFINITIONS*/

      default:
      // Uncomment only when debugging missing IDs
      // Serial.print(" Missing FORD CAN Data. Please check setup. \n");   
      //   forwardMessage(msg);  // pass-through unknown IDs now handled by handleMessage();
      // Serial.printf("Unknown Ford CAN ID: 0x%03X\n", msg.id);
    break;  
    
//  Serial.print(" ID: ");
//  Serial.print(msg.id, HEX);
//  Serial.print(" Data: ");    
// Serial.printf("ID: %03X DATA: ", msg.id); // merge upper 3 serial print
//  for ( uint8_t i = 0; i < msg.len; i++ ) {
//  Serial.print(msg.buf[i], HEX);
//  Serial.print(" ");
// }
//  Serial.println();
  
  }
}

 //============Buffered CAN List========================================//

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



  void FordPCMBus::initialize() {
  // Serial.begin(115200);
  Serial.println("AlxBilt Ford PCM Input-Bus- initializing CAN 3");
  }

  void FordPCMBus::loop() {  // request PGN's every 1 second

    uint32_t currentMillis = millis();
    if (currentMillis - lastRequest >= 1000) {
  // Print the observed frame
          lastRequest = currentMillis;
    //Serial.println("1 second tick");  // placeholder
  #ifdef DEBUG_STATS
    printStats();
  #endif
  }


}
                          
/****************************************************************************************************************************************
  END OF PROGRAM                                                    
****************************************************************************************************************************************/
#endif // FORD_BUS_INPUT