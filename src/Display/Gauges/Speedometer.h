//
// Created by jlaustill on 7/6/21.
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

#include "Config/configuration.h"

#ifdef SPEEDOMETER_OUTPUT
class Speedometer {
public:
    explicit Speedometer(int _clicksPerMile = SPEEDOMETER_OUTPUT_CLICKS_PER_MILE);
    void initialize() const;
    void SetMph(int _mph);
    static long MphToMicroseconds(int _mph);

private:
    static long HertzToMicroseconds(double _hz);
    int mph;
};
#endif // SPEEDOMETER_OUTPUT


