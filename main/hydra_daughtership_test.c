/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

#include "hydra.h"

#ifdef CONFIG_IDF_TARGET_ESP32
#define CHIP_NAME "ESP32"
#endif

#ifdef CONFIG_IDF_TARGET_ESP32S2BETA
#define CHIP_NAME "ESP32-S2 Beta"
#endif

#define NBR_POINTS 100
#define PRESSURE_MIN 1000000
#define PRESSURE_MAX 11*PRESSURE_MIN
#define WINDSPEED_MIN 1000000
#define WINDSPEED_MAX 11*WINDSPEED_MIN

void app_main(void)
{
    uint32_t pressure = PRESSURE_MIN;
    uint32_t pressure_step = (PRESSURE_MAX - PRESSURE_MIN)/NBR_POINTS;
    uint32_t windspeed = WINDSPEED_MIN;
    uint8_t wind_direction = 0;
    uint32_t windspeed_step = (WINDSPEED_MAX - WINDSPEED_MIN)/NBR_POINTS;

    hydra_init();

    while (1) {
        send_pressure(pressure);
        pressure += pressure_step;
        if ((pressure >= PRESSURE_MAX) || (pressure < PRESSURE_MIN))
            pressure_step = -pressure_step;

        vTaskDelay(10/portTICK_PERIOD_MS);

        send_wind_speed(windspeed, wind_direction);
        windspeed += windspeed_step;
        if ((windspeed >= WINDSPEED_MAX) || (windspeed < WINDSPEED_MIN)) {
            windspeed_step = -windspeed_step;
            if (windspeed >= WINDSPEED_MAX)
                wind_direction = !wind_direction;
        }

        vTaskDelay(750/portTICK_PERIOD_MS);
    }
}
