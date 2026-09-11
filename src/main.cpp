//
//    👻 
//
// Created by AlxBilt on 12/1/2025
// SPDX-License-Identifier: MPL-2.0
    #include <Arduino.h>
    #include "Config/configuration.h"
    #include "Utils/Scheduler.h"
    #include "CANDriver.h"
    #include "IO/BlinkOutput.h"
    #include "Modules/Gateway.h"


    void setup() 
    {
    // ----------------------------------------------------------------------
    // Setup Application to run 
    // ----------------------------------------------------------------------
    // Initialize Gateway interfaces
    GatewayModule::begin();
    
    // Initialize CAN interfaces
    CANDriver::begin();

    // Heart beat
#ifdef BLINK_OUTPUT
    BlinkOutput::initialize();
#endif
   
    Serial.begin(115200);

    Serial.println("\n===== MIMIC ECHO Baseline Startup Example Gateway V1.0 Boot =====");
    Serial.println("===== Custom TIPM System Ready =====");
    Serial.println("===== User Define More Task  =====");
    // ----------------------------------------------------------------------
    // Start of  Tasks Updating 
    // ----------------------------------------------------------------------

    // Ford Pedal APP


    // Cummins BARO/MAP 

    
    // FanTach Emulator Module


    // FanControl Duty


    // Cummins Pedal APP


    // Ford Boost Gauge

    // Ford Tachometer

    // Cummins VSS

    // Ford cluster 

    // Cummisn Cruise control 

    
/*********************TIPM GHOST EXAMPLE *********************************************************/
   Scheduler::addTask(GatewayModule::taskSendCummins230, 10);

    // EGT Exhaust Temp Module

    // Heart beat
#ifdef BLINK_OUTPUT
    Scheduler::addTask(BlinkOutput::blink, 1000); // 1000 ms
#endif



    }

    void loop() 
    {

    // Handle mode updates (logic inside each module)

    // Run scheduled timed tasks
    Scheduler::update();



    }