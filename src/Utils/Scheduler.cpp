//
//    👻 
//
// Created by AlxBilt on 12/1/2025
// SPDX-License-Identifier: MPL-2.0
#include "Scheduler.h"

Scheduler::Task Scheduler::tasks[MAX_TASKS];
int Scheduler::taskCount = 0;

void Scheduler::addTask(TaskCallback cb, uint32_t intervalMs) {
    if (taskCount >= MAX_TASKS) return;

    tasks[taskCount].callback = cb;
    tasks[taskCount].intervalMs = intervalMs;
    tasks[taskCount].nextRun = millis() + intervalMs;
    taskCount++;
}

void Scheduler::update() {
    uint32_t now = millis();

    for (int i = 0; i < taskCount; i++) {
        if (now >= tasks[i].nextRun) {
            tasks[i].callback();
            tasks[i].nextRun = now + tasks[i].intervalMs;
        }
    }


}
