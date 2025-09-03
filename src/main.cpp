// C/C++ Headers

// IDF Headers
#include <driver/gpio.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

// Component Headers

// Private Headers

void gpio_setup() {
    static const char* TAG = "GPIO Setup";

    // Onboard LED
    ESP_LOGI(TAG, "Setting up GPIO for LED.");
    gpio_config_t onboardLedGpioConfig = {
        .pin_bit_mask = 1ULL << GPIO_NUM_2,
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    ESP_ERROR_CHECK(gpio_config(&onboardLedGpioConfig));

    // Motor Pins

    // Current Sense ADC Pins


}

extern "C" void app_main() {
    gpio_setup();
    
}