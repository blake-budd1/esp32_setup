#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_event_loop.h"
#include "esp_wifi.h"
#include "nvs_flash.h"
#include "esp_netif.h"


/**************** TO CREATE A WIFI CONNECTION POINT ON THE ESP32 **************************/
#define AP_SSID "espwifi"
#define AP_PASSWORD "1111"
#define AP_MAX_CONN 4
#define AP_CHANNEL 6

/**************** MODIFY THESE TO THE PASSWORD AND USERNAME OF THE WIFI *******************/
#define STA_SSID "Blake (2)"
#define STA_PASSWORD "blake111"

/****************************** TO SCAN FOR AVAILABLE NETWORKS ****************************/
void scann(){
// configure and run the scan process in blocking mode
  wifi_scan_config_t scan_config = {
    .ssid = 0,
    .bssid = 0,
    .channel = 0,
        .show_hidden = true
    };
  printf("Start scanning...");
  ESP_ERROR_CHECK(esp_wifi_scan_start(&scan_config, true));
  printf(" completed!\n");
 
  // get the list of APs found in the last scan
  uint16_t ap_num;
  wifi_ap_record_t ap_records[20];
     ESP_ERROR_CHECK(esp_wifi_scan_get_ap_num(&ap_num));
  ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&ap_num, ap_records));
  
  // print the list 
  printf("Found %d access points:\n", ap_num);

  printf("               SSID              | Channel | RSSI |   MAC \n\n");
  //printf("----------------------------------------------------------------\n");
  for(int i = 0; i < ap_num; i++){
    printf("%32s | %7d  \n", ap_records[i].ssid, ap_records[i].primary);
  }

//  printf("----------------------------------------------------------------\n");   
 
}


void app_main()
{
  // initialize NVS
  ESP_ERROR_CHECK(nvs_flash_init());
  
  esp_netif_init();

  wifi_init_config_t wifi_config = WIFI_INIT_CONFIG_DEFAULT();
  ESP_ERROR_CHECK(esp_wifi_init(&wifi_config));
  ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));// set wifi mode to Access point


  /************** TO CONNECT TO A WIFI OPTION *******************/
  wifi_config_t sta_config = {
    .sta = {
        .ssid = STA_SSID,
        .password = STA_PASSWORD,
    },
   
  };
   ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &sta_config));

    
  // configure the wifi connection and start the interface
  /************* TO CREATE A WIFI CONNECTION POINT (FROM BOARD) ********************/
  wifi_config_t ap_config = {
    .ap = {
        .ssid = AP_SSID,
        .password = AP_PASSWORD,
        .max_connection = AP_MAX_CONN,
        .channel = AP_CHANNEL,
        .ssid_hidden = 0,
    },
  };
  //ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_AP, &ap_config));
  
  ESP_ERROR_CHECK(esp_wifi_start());// starts wifi usage
  ESP_ERROR_CHECK(esp_wifi_connect());
  
  //scann();
}

/* going to have to:
    - power on
    - connect on different device to the esp32 wifi
    - sign into desired wifi
    - use the esp32 to connect to the desired wifi
    - Could initially display some QR code to go to the website needed to enter the desired wifi
*/