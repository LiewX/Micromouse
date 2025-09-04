#include "InfraredSensors.hpp"
#include "PinAssignments.hpp"

void infrared_sensors_pin_setup() {
    gpio_config_t infraredSensorGpioConfig = {
        .pin_bit_mask = (1ULL << INFRARED_SENSOR_PIN_1) |
                        (1ULL << INFRARED_SENSOR_PIN_2) | 
                        (1ULL << INFRARED_SENSOR_PIN_3) | 
                        (1ULL << INFRARED_SENSOR_PIN_4),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    ESP_ERROR_CHECK(gpio_config(&infraredSensorGpioConfig));
}
