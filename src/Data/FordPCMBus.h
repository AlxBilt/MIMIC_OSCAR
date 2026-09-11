//    👻 
//
// Created by AlxBilt on 1/12/2026
// SPDX-License-Identifier: MPL-2.0
#pragma once
#include <Arduino.h>
#include <FlexCAN_T4.h>
#include "canDriver.h"

/*
 * Ford CAN Gateway Module
 * ----------------------
 * Sniffs Ford PCM frames (CAN3).
 * Acts as a MITM gateway with deny-list routing.
 * Optionally caches selected frames for future translation.
 */

  #ifdef FORD_BUS_INPUT

  class FordPCMBus {
  public:

  

// ======================================================
// Sniffer — call from CAN3.onReceive() by GatewayModule::handleCanRx()
// ======================================================
  
    static void initialize();
    static void loop();
    static void FordPCMBusSniff(const CAN_message_t &msg);
    static void forwardMessage(const CAN_message_t &msg);
    static void handleMessage(const CAN_message_t &msg);
    

    static uint32_t rxCount;
    static uint32_t txCount;
    static uint32_t blockedCount;

  // static CAN_message_t data201;
  
  //============Buffered CAN List===============================================================//
  

  // =========================
  // Getters -> 
  // =========================
    static uint32_t getRxCount() {
      return rxCount;
    }         // stats getter
    static uint32_t getTxCount() {
      return txCount;
    }
    static uint32_t getBlockedCount() {
      return blockedCount;
    }
  
  

    static bool isDenied(uint32_t id);
    
  // ================= based on Powerstroke 6.0 & 6.4 ===============================

         
    static uint8_t data720[8]; // OBD2 Scanner
      /* FILL IN CUSTOM DECLARATION*/


    static uint8_t data18DB33F1[8]; // OBD2 Scanner

    static uint32_t lastRequest;

   
  
    private:
    // Output bus for forwarded frames (e.g., CANBUS_2)
    static Bus outBus;




  };
  
  #endif  // FORD_BUS_INPUT
