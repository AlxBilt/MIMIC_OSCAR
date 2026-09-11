# MIMIC_WRAITH   👻 
ECHO — Open-source CAN gateway firmware with WRAITH technology for builders. A working foundation for creating custom automotive CAN interfaces, signal translators, and vehicle integration modules.

🔴 **Red Pill:** Build it yourself. The source is yours to explore.

🔵 **Blue Pill:** Use a finished commercial implementation delivered as `.hex` file.

```text
                    ECHO BASELINE
                          │
             ┌────────────┴────────────┐
             │                         │
          CANDriver                Scheduler
             │                         │
       ┌─────┼─────┐                   │
       │     │     │                   │
      CAN1  CAN2  CAN3                 │
       │     │     │                   │
       ▼     ▼     ▼                   │
    Cummins Ford  Ford PCM             │
      Bus   Vehicle   Bus              │
       │     │     │                   │
       └─────┴─────┴──────────┐        │
                              ▼        │
                        GatewayModule ◄─┘
                              │
                              ▼
                       BUILD CAN FRAME
                              │
                              ▼
                       CANDriver::send()

/************************************************/

              OPEN SOURCE MODEL
                     │
                     ▼
              DIY COMMUNITY
                     │
          ┌──────────┴──────────┐
          │                     │
     "I'll build it"      "Build it for me"
          │                     │
          ▼                     ▼
   Community project      PAID FIRMWARE
                                │
                                ▼
                         MIMIC PRODUCT
