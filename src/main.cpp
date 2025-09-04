// C/C++ Headers

// IDF Headers
#include <driver/gpio.h>
#include <driver/ledc.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

// Component Headers

// Private Headers
#include "PinAssignments.hpp"
#include "InfraredSensors.hpp"
#include "Motor.hpp"
#include "OnboardLed.hpp"
#include "RtosUtils.hpp"

void gpio_setup() {
    static const char* TAG = "GPIO SETUP";
    
    // Onboard LED
    ESP_LOGI(TAG, "Setting up GPIO for LED.");
    onboard_led_pin_setup();
    
    // IR Pins
    ESP_LOGI(TAG, "Setting up GPIO for Infrared Sensors.");
    infrared_sensors_pin_setup();
    
    // Motor Pins
    ESP_LOGI(TAG, "Setting up GPIO for Motor.");
    motor_pin_setup();
    
    ESP_LOGI(TAG, "Completed.");
}

void create_tasks() {
    static const char* TAG = "RTOS";
    

}


extern "C" void app_main() {
    gpio_setup();
    create_tasks();
}