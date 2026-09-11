//
//    👻 
//
// Created by AlxBilt on 12/1/2025
// SPDX-License-Identifier: MPL-2.0
#pragma once
#include <Arduino.h>

class Scheduler {
public:
    typedef void (*TaskCallback)();

    struct Task {
        TaskCallback callback;
        uint32_t intervalMs;
        uint32_t nextRun;
    };

    static void addTask(TaskCallback cb, uint32_t intervalMs);
    static void update();
    

private:
    static const int MAX_TASKS = 20;
    static Task tasks[MAX_TASKS];
    static int taskCount;
};
