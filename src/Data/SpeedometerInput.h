//
// Created by jlaustill on 7/20/21.
// https://github.com/jlaustill
//
// Created by jlaustill on 7/20/21.
// https://github.com/jlaustill
/*
 * SPDX-License-Identifier: MPL-2.0
 * ECHO / WRAITH
 * Copyright (c) 2026 AlxBilt
 *
 * Portions of the parsing logic are derived from:
 * OPCM | OSSM
 * Copyright (c) 2025 Joshua Austill
 * Licensed under the MIT License.
 *
 * See THIRD_PARTY_LICENSES/OPCM/LICENSE
 */
#pragma once
#ifdef SPEEDOMETER_INPUT

class SpeedometerInput {
public:
    static void initialize();
    static int getCurrentSpeedInMph();
};


#endif //SPEEDOMETERINPUT
