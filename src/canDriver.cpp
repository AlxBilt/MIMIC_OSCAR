//
//    👻 
//
// Created by AlxBilt on 12/1/2025
// SPDX-License-Identifier: MPL-2.0
#include "canDriver.h"
#include "Modules/gateway.h"

#ifndef CAN_DRIVER_CPP

// Default CAN baudrate
int baud = 500000;

// Static object definitions
FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> CANDriver::can1;  // Cummins ECM (isolated)
FlexCAN_T4<CAN2, RX_SIZE_256, TX_SIZE_16> CANDriver::can2;  // Ford vehicle Network
FlexCAN_T4<CAN3, RX_SIZE_256, TX_SIZE_16> CANDriver::can3;  // Ford PCM (isolated)


void CANDriver::begin() {
    Serial.println("[CANDriver] initializing CAN1, CAN2, & CAN3...");
    
// === CAN1  (Cummins ECM)===
    can1.begin();
    can1.setBaudRate(baud);
    can1.enableFIFO();
    can1.enableFIFOInterrupt();
    can1.onReceive(handleCan1Rx);

// === CAN2 (Ford vehicle network)===
    can2.begin();
    can2.setBaudRate(baud);
    can2.enableFIFO();
    can2.enableFIFOInterrupt();
    can2.onReceive(handleCan2Rx);

// === CAN3 (Ford PC isolated)===
    can3.begin();
    can3.setBaudRate(baud);
    can3.enableFIFO();
    can3.enableFIFOInterrupt();
    can3.onReceive(handleCan3Rx);    

    Serial.println("[CANDriver] OK");
}

bool CANDriver::send(Bus bus, uint32_t id, const uint8_t *data, uint8_t len) {
    CAN_message_t msg;
    msg.id  = id;
    msg.len = len;
    memcpy(msg.buf, data, len);
    return send(bus, msg);
}

bool CANDriver::send(Bus bus, const CAN_message_t &msg) {
    switch (bus) {
        case CANBUS_1: return can1.write(msg);
        case CANBUS_2: return can2.write(msg);
        case CANBUS_3: return can3.write(msg);
        default:       return false;
    }
  }
  

void CANDriver::update() {
    // Both CAN buses handle by interrupts. 
    // No polling required unless extended features are added
    // Interrupt-driven; nothing needed here yet
}

// ================= RX DISPATCH =================

void CANDriver::handleCan1Rx(const CAN_message_t &msg) {

    GatewayModule::handleCanRx(msg, CANBUS_1);
}

void CANDriver::handleCan2Rx(const CAN_message_t &msg) {

    GatewayModule::handleCanRx(msg, CANBUS_2);
}

void CANDriver::handleCan3Rx(const CAN_message_t &msg) {

    GatewayModule::handleCanRx(msg, CANBUS_3);
}
 

#endif // CAN_DRIVER_CPP