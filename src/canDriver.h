//
//    👻 
//
// Created by AlxBilt on 12/1/2025
// SPDX-License-Identifier: MPL-2.0
#pragma once
#include <Arduino.h>
#include <FlexCAN_T4.h>


enum Bus {
   CANBUS_1 = 1,  // Cummins ECM (isolated)
   CANBUS_2 = 2,  // Ford vehicle Network
   CANBUS_3 = 3   // Ford PCM (isolated)
};

class CANDriver {
public:

   static void begin();

   static bool send(Bus bus, uint32_t id, const uint8_t *data, uint8_t len);
   static bool send(Bus bus, const CAN_message_t &msg);

   static void update();

   // RX Internal callback handlers
   static void handleCan1Rx(const CAN_message_t &msg);
   static void handleCan2Rx(const CAN_message_t &msg);
   static void handleCan3Rx(const CAN_message_t &msg);
   

private: 
   // Internal FlexCAN objects
   static FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> can1;
   static FlexCAN_T4<CAN2, RX_SIZE_256, TX_SIZE_16> can2;
   static FlexCAN_T4<CAN3, RX_SIZE_256, TX_SIZE_16> can3;

};

// #endif // CAN_DRIVER_CPP