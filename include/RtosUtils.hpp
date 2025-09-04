#pragma once

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#ifdef __cplusplus
extern "C" {
#endif

/** 
 *  @brief Semaphore creation and checking function
 *  @param sem semaphore handle
 *  @param semName semaphore name
 *  @return ESP_OK if successful; if not, return ESP_ERR_INVALID_ARG
 */
esp_err_t create_and_check_sem(SemaphoreHandle_t &sem, const char* semName);


/**
 *  @brief Queue creation and checking function
 *  @param queue queue handle
 *  @param queueName queue name
 *  @param size number of items in queue
 *  @param itemSize
 *  @return ESP_OK if successful; if not, return ESP_ERR_INVALID_ARG
 */
esp_err_t create_and_check_queue(QueueHandle_t &queue, const char* queueName, size_t size, size_t itemSize);

/**
 *  @brief Task creation and checking function
 *  @param taskEnable macro definition
 *  @param taskFunc main function for task
 *  @param taskName 
 *  @param stackSize 
 *  @param priority
 *  @param taskHandle task handle
 *  @return ESP_OK if successful; if not, return ESP_ERR_INVALID_ARG
 */
esp_err_t create_and_check_task(bool taskEnable, void (*taskFunc)(void*), const char* taskName, uint32_t stackSize, UBaseType_t priority, TaskHandle_t* taskHandle);

/**
 *  @brief Checking and printing free stack (available from allocated amount) of each task
 *  @param taskHandle 
 *  @param taskName 
 */
void print_free_stack(TaskHandle_t taskHandle, const char* taskName);






#ifdef __cplusplus
}
#endif