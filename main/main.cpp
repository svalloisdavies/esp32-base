#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_log.h"
#include <tuple>




template <class... T>
std::tuple<std::size_t, std::common_type_t<T...>> sum(T... args)
{
    return { sizeof...(T), (args + ...) };
}

static const char *TAG = "main";

extern "C" {
    void app_main();
}

void app_main(void)
{

    /* Configure the peripheral according to the LED type */
    for (;;){
        auto [iNumbers, iSum]{ sum(1, 2, 3) };
        ESP_LOGI(TAG, "hello from: %s: %d %d", "main", iNumbers, iSum);
        vTaskDelay(CONFIG_LOOP_PERIOD / portTICK_PERIOD_MS);
    }
}
