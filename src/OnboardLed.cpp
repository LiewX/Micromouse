#include "InfraredSensors.hpp"
#include "PinAssignments.hpp"

void onboard_led_pin_setup() {
    gpio_config_t onboardLedGpioConfig = {
        .pin_bit_mask = 1ULL << ONBOARD_LED_PIN,
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    ESP_ERROR_CHECK(gpio_config(&onboardLedGpioConfig));
}