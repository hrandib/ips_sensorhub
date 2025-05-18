#include "sensors.h"

#include "esp_log.h"
#include "esp_check.h"
#include "esp_err.h"
#include <driver/i2c.h>

static const char *TAG = "SENSORS";

static void i2c_init(void)
{
    static const i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = 17,
        .scl_io_num = 18,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = 100000,
        .clk_flags = 0,
    };
    ESP_ERROR_CHECK(i2c_param_config(I2C_NUM_0, &conf));
    ESP_ERROR_CHECK(i2c_driver_install(I2C_NUM_0, conf.mode, 0, 0, 0));


    // Initialize I2C here
    ESP_LOGI(TAG, "I2C initialized");
}

static esp_err_t hdc1080_init(i2c_port_t i2c_num)
{
    // Initialize HDC1080 sensor here
    // This is a placeholder function. Replace with actual initialization code.
    ESP_LOGI(TAG, "HDC1080 initialized");
    return ESP_OK;
}
static esp_err_t bmp280_init(i2c_port_t i2c_num)
{
    // Initialize BMP280 sensor here
    // This is a placeholder function. Replace with actual initialization code.
    ESP_LOGI(TAG, "BMP280 initialized");
    return ESP_OK;
}

static esp_err_t bh1750_init(i2c_port_t i2c_num)
{
    // Initialize BH1750 sensor here
    // This is a placeholder function. Replace with actual initialization code.
    ESP_LOGI(TAG, "BH1750 initialized");
    return ESP_OK;
}

static esp_err_t s8_init(void)
{
    // Initialize S8 sensor here
    // This is a placeholder function. Replace with actual initialization code.
    ESP_LOGI(TAG, "S8 initialized");
    return ESP_OK;
}


void sensors_init(void)
{
    i2c_init();

    ESP_LOGI(TAG, "Initializing HDC1080 sensor");
    esp_err_t ret = hdc1080_init(I2C_NUM_0);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize HDC1080 sensor: %s", esp_err_to_name(ret));
    } else {
        ESP_LOGI(TAG, "HDC1080 sensor initialized");
    }

    ESP_LOGI(TAG, "Initializing BMP280 sensor");
    ret = bmp280_init(I2C_NUM_0);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize BMP280 sensor: %s", esp_err_to_name(ret));
    } else {
        ESP_LOGI(TAG, "BMP280 sensor initialized");
    }

    ESP_LOGI(TAG, "Initializing BH1750 sensor");
    esp_err_t ret = bh1750_init(I2C_NUM_0);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize BH1750 sensor: %s", esp_err_to_name(ret));
    } else {
        ESP_LOGI(TAG, "BH1750 sensor initialized");
    }

    ESP_LOGI(TAG, "Initializing S8 sensor");
    esp_err_t ret = s8_init();
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize S8 sensor: %s", esp_err_to_name(ret));
    } else {
        ESP_LOGI(TAG, "S8 sensor initialized");

    // Initialize sensors here
    ESP_LOGI(TAG, "Sensors initialized");
}