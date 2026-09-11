// GatewayModule.cpp == SENDER of CAN data
// Clean Gateway: read parsed CumminsBus values -> convert -> 
// Populate dataResponses -> send on CAN2
//
// A real-time CAN gateway/emulator
//
/****************THE BUILDER OF CAN FRAMES************************* */ 
// Created by AlxBilt on 12/1/25.👻
// SPDX-License-Identifier: MPL-2.0

#include "Config/configuration.h"

#include "Gateway.h"
#include "Data/dataResponses.h"   // templates: fordTachResponse, fordSpeedResponse, fordEctResponse, ...
#include "Data/CumminsBus.h"      // canonical Cummins getters and raw arrays
#include "canDriver.h"
#include <Arduino.h>

#include "Data/FordVehicleBus.h"
#include "Data/FordPCMBus.h"


Bus GatewayModule::outBus = CANBUS_2; // default to CAN2 (Ford network & cluster)

// Example ***************************************Example 
    void GatewayModule::emitCumminsTipmGhostOne()
    {
    cumminsTipmGhostOneResponse.buf[0] = 0x0F;
    cumminsTipmGhostOneResponse.buf[1] = 0x43;    
    cumminsTipmGhostOneResponse.buf[2] = 0xDA;    
    cumminsTipmGhostOneResponse.buf[3] = 0xCD;   
    cumminsTipmGhostOneResponse.buf[4] = 0x70;   
    cumminsTipmGhostOneResponse.buf[5] = 0x81; // on day of test Torque Pro show 41% fuel
    cumminsTipmGhostOneResponse.buf[6] = 0xFF; // same as 0b10000000; 50% Fuel default level
    cumminsTipmGhostOneResponse.buf[7] = 0x10;
    
    CANDriver::send(CANBUS_1, cumminsTipmGhostOneResponse);
    }

    void GatewayModule::taskSendCummins230() 
    {
    emitCumminsTipmGhostOne();
    }

// Internal anonymous namespace for local helpers & timers
namespace {



    
}//end namespace

// -------------------------------------------------------------------------
// GatewayModule public API
// -------------------------------------------------------------------------
void GatewayModule::begin(bool debug) {
    Serial.println("[GatewayModule] Starting...");
    Serial.println("[GatewayModule] Ready.");
}

void GatewayModule::update() {


}

// ================================================================
// HANDLE CAN RX — this is the gateway's input hook (called by CANDriver)
// ================================================================
void GatewayModule::handleCanRx(const CAN_message_t &msg, Bus bus) {


    // 2) If message arrives from Cummins bus (CAN1), parse/update CumminsBus canonical holder
    if (bus == CANBUS_1) { // Cummins ECM
        // Let CumminsBus parse and store raw bytes — Gateway will read getters in update()
        CumminsBus::CumminsBusSniff(msg);

        return;
    }

    // 3) If message arrives from Ford Vehicle bus (CAN2)
    // (we emit translated frames instead) — optionally forward to CAN1 - dependent on application
    if (bus == CANBUS_2) { // Gateway output bus
        FordVehicleBus::VehicleSniff(msg); 
    //    if (passThrough) forward(bus, msg);
        return;
    }

    // 4) If message arrives from Ford PCM bus (CAN3) 
     // (we emit translated frames instead) — optionally forward to CAN2
     // - dependent on application
    if (bus == CANBUS_3) { // Ford PCM
        FordPCMBus::FordPCMBusSniff(msg); 

   // if (passThrough) forward(bus, msg);

        return;
    }
}








