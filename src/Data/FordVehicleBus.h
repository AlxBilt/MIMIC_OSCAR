//    👻 
//
// Created by AlxBilt on 1/12/2026
// SPDX-License-Identifier: MPL-2.0
#pragma once
#include <Arduino.h>
#include <FlexCAN_T4.h>
#include "canDriver.h"
#ifdef FORD_VEHICLE_BUS_INPUT

class FordVehicleBus {
public:

  static void initialize();
  static void loop();
  static void VehicleSniff(const CAN_message_t &msg);


   // =========================
   // Getters
   // =========================




  
  static uint8_t data720[8]; // OBD2 Scanner
      /* FILL IN CUSTOM DECLARATIONS*/

  static uint8_t data18DB33F1[8]; // OBD2 Scanner

  static uint32_t lastRequest;

private:

  static Bus outBus;
};
 
#endif // FORD_VEHICLE_BUS_INPUT
