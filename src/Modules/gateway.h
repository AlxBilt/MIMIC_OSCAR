//    👻 
//
// Created by AlxBilt on 1/12/2026
// SPDX-License-Identifier: MPL-2.0
#pragma once
#include <Arduino.h>
#include <FlexCAN_T4.h>
#include "canDriver.h"



class GatewayModule {
public:
// --------------------------------------------------------
// Initialization
// --------------------------------------------------------
    static void begin(bool debug = false);
    static void update();
// --------------------------------------------------------
// CAN frame handler (called by CANDriver)
// --------------------------------------------------------
    static void handleCanRx(const CAN_message_t &msg, Bus bus);
// --------------------------------------------------------


/********************* TIPM GHOST EXAMPLE***********************************/
    static void taskSendCummins230();
    
//---------------------------------------------------------
// Function Call
//---------------------------------------------------------    
/********************* TIPM GHOST EXAMPLE***********************************/
    static void emitCumminsTipmGhostOne();
    private:


// --------------------------------------------------------
// Low-level forwarding (CAN1 <-> CAN2)
// --------------------------------------------------------
    static Bus outBus;



};

