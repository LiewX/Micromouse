#pragma once

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const char* task1Name;

// Task Handler
extern TaskHandle_t xTask_TrapCommutation;

// Function prototypes for task
void task_trap_commutation(void *pvParameters);


#ifdef __cplusplus
}
#endif