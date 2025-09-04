#include <esp_log.h>
#include <esp_err.h>
#include "RtosUtils.hpp"

static const char* TAG = "RTOS";

esp_err_t create_and_check_sem(SemaphoreHandle_t &sem, const char* semName) {
    sem = xSemaphoreCreateMutex();
    if (sem == NULL) {
        ESP_LOGI(TAG, "Failed to create semaphore '%s'.", semName);
        return ESP_ERR_INVALID_ARG;
    }
    ESP_LOGI(TAG, "Semaphore '%s' created successfully.\n", semName);
    return ESP_OK;
}

esp_err_t create_and_check_queue(QueueHandle_t &queue, const char* queueName, size_t size, size_t itemSize) {
    queue = xQueueCreate(size, itemSize);
    if (queue == NULL) {
        ESP_LOGI(TAG, "Failed to create queue '%s'.\n", queueName);
        return ESP_ERR_INVALID_ARG;
    }
    ESP_LOGI(TAG, "Queue '%s' created successfully.\n", queueName);
    return ESP_OK;
}

esp_err_t create_and_check_task(bool taskEnable, void (*taskFunc)(void*), const char* taskName, uint32_t stackSize, UBaseType_t priority, TaskHandle_t* taskHandle) {
    if (taskEnable) {
        BaseType_t status = xTaskCreate(taskFunc, taskName, stackSize, NULL, priority, taskHandle);
        if (status != pdPASS) {
            ESP_LOGI(TAG, "Failed to create task '%s'.\n", taskName);
            return ESP_ERR_INVALID_ARG;
        }
        ESP_LOGI(TAG, "Task '%s' created successfully.\n", taskName);
    }
    return ESP_OK;
}

void print_free_stack(TaskHandle_t taskHandle, const char* taskName) {
    if (taskHandle != nullptr) {
        UBaseType_t highWaterMark = uxTaskGetStackHighWaterMark(taskHandle);
        ESP_LOGI(TAG, "High Watermark for task '%s': %u", taskName, (unsigned int) highWaterMark);
    }
}