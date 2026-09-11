// SPDX-License-Identifier: MPL-2.0

/*
 * ECHO / WRAITH
 * Copyright (c) 2026 AlxBilt
 *
 * Portions of the parsing logic are derived from:
 * OPCM 
 * Copyright (c) 2025 Joshua Austill
 * Licensed under the MIT License.
 *
 * See THIRD_PARTY_LICENSES/OPCM/LICENSE
 */

//    👻 
//
// Implemented by AlxBilt on 1/12/2026
// SPDX-License-Identifier: MPL-2.0
//  Data sheet of CAN frames


#include <FlexCAN_T4.h>

/******************************************************************************
 *   DEFAULT TEMPLATE RESPONSE FRAMES
 *   Used by PulseToCanModule, Gateway rules, or TestBench presets.
 *****************************************************************************/

// CAN DATA DECLARATION 
uint8_t emptyBytePad = 0x00;

/**************************TIPM DATA EXAMPLE****************************************/
CAN_message_t cumminsTipmGhostOneResponse = {
    .id = 0x230, //  from TIPM -> arbitrary value 
    .len = 8,
    .buf = {emptyBytePad, emptyBytePad, emptyBytePad, emptyBytePad, emptyBytePad, emptyBytePad,
            emptyBytePad, emptyBytePad}};       


