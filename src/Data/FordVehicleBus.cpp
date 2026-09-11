// Data input from Vehicle OBD2 bus on CAN 2 | Custer BUS
//    👻 
//
// Created by AlxBilt on 1/12/2026
// SPDX-License-Identifier: MPL-2.0
#include "Config/configuration.h"
#ifdef FORD_VEHICLE_BUS_INPUT
#include <FlexCAN_T4.h>
#include "canDriver.h"
#include <Arduino.h>
#include "FordVehicleBus.h"
Bus FordVehicleBus::outBus = CANBUS_2;      // Output to CAN2 by default

// -------------------------
// 11-Bit Static member definitions
// -------------------------

 /* FILL IN CUSTOM DEFINITIONS*/


// CAN data for OBD2 SCANNER
uint8_t  FordVehicleBus::data720[8] = {0}; // OBD Scanner request
      /* FILL IN CUSTOM DEFINITIONS*/

uint8_t  FordVehicleBus::data18DB33F1[8] = {0}; // OBD Scanner Request

uint32_t FordVehicleBus::lastRequest = 0;

void FordVehicleBus::VehicleSniff(const CAN_message_t &msg) {
  switch (msg.id) {

    

    case 0x720:
        FordVehicleBus::data720[0] = msg.buf[0]; // 6.0  PCM ? | *PLACEHODLER
      /* FILL IN CUSTOM DEFINITIONS*/

        CANDriver::send(CANBUS_3, msg);
      return;

 

    default:
      // Uncomment only when debugging missing IDs
      // Serial.print(" Missing FORD CAN Data. Please check setup. \n");   
      //   forwardMessage(msg);  // pass-through unknown IDs now handled by handleMessage();
      // Serial.printf("Unknown Ford CAN ID: 0x%03X\n", msg.id);
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



void FordVehicleBus::initialize() {
  Serial.println("AlxBilt Ford VehicleInput-Bus- initializing CAN 2");
}

void FordVehicleBus::loop() {  // request PGN's every 1 second
  uint32_t currentMillis = millis();
  if (currentMillis - lastRequest >= 1000) {
 // Print the observed frame
        lastRequest = currentMillis;
  //Serial.println("1 second tick");  // placeholder
  }
}

#endif // FORD_VEHICLE_BUS_INPUT