# MIMIC_OSCAR_Punto-de-Partida   👻 
                                        OSCAR — Open Source CAN Automotive Research.

OSCAR_Punto-de-Partida — A CAN gateway firmware for use with WRAITH 3000 hardware. A working foundation for creating custom automotive CAN interfaces, signal translators, and vehicle integration modules. 

*There is ECHO, a separate commercial application not included here for: 2006+ Cummins drivetrain converted into 2005+ Ford Powerstroke Superduty chassis. See our business page for more details.

🔴 **Red Pill:** Build it yourself. The source is yours to explore. We provide no ongoing support for OSCAR.

🔵 **Blue Pill:** Use a finished modular commercial implementation delivered as `.hex` file.

```text
                    OSCAR BASELINE
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
  ENGINE    BODY   PCM                 │
      Bus   Vehicle   Bus              │
       │     │     │                   │
       └─────┴─────┴──────────┐        │
                              ▼        │
                        SendModule ◄─┘
                              │
                              ▼                                                  
                              ▼
                            send()

/************************************************/

                MODEL OPTIONS
                     │
                     ▼
                     │
          ┌──────────┴──────────┐
          │                     │
     "You'll build it."      "We'll Build it for you."
          │                     │
OSCAR_PUTO DE PARTIDA          ECHO
          │                     │
          │                     │
   OPEN SOURCE             PRIVATE
   COMMUNITY               COMMERCIAL
        │                     │
        ▼                     ▼
  Users build it        We provide service
  for each other       / finished solutions
          │                     │
          ▼                     ▼
OSCAR Community project      PAID ECHO FIRMWARE
                                │
                                ▼
                         MIMIC ECHO PRODUCT

          
