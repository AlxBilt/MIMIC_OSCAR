# MIMIC_WRAITH   👻 
ECHO — CAN gateway firmware for WRAITH hardware. A working foundation for creating custom automotive CAN interfaces, signal translators, and vehicle integration modules. 
Current application: 2006+ Cummins drivetrain converted into 2005+ Ford Powerstroke Superduty chassis.  

🔴 **Red Pill:** Build it yourself. The source is yours to explore.

🔵 **Blue Pill:** Use a finished commercial implementation delivered as `.hex` file.

```text
                    ECHO BASELINE
                          │
             ┌────────────┴────────────┐
             │                         │
          CANDriver                    │
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
     "You'll build it."      "We'll Build it for you."
          │                     │
          ▼                     ▼
   Community project      PAID FIRMWARE
                                │
                                ▼
                         MIMIC PRODUCT
