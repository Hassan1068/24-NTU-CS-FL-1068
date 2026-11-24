#include <WiFi.h>

void setup() {

    Serial.begin(115200);

    WiFi.mode(WIFI_STA);

    WiFi.disconnect();

    delay(1000);

}

void loop() {

    Serial.println("Scanning WiFi networks...");

    int count = WiFi.scanNetworks();

    if (count == 0) {

        Serial.println("No networks found");

    }

    else {

        Serial.print("Networks found: ");

        Serial.println(count);

    }

    for (int i = 0; i < count; i++) {

        Serial.print("SSID: ");

        Serial.println(WiFi.SSID(i));

        Serial.print("RSSI: ");

        Serial.println(WiFi.RSSI(i));

        Serial.print("Channel: ");

        Serial.println(WiFi.channel(i));

        Serial.println("----------------");

    }

    WiFi.scanDelete();

    delay(5000);

}


// Important WiFi Commands Used in code
// Command	                  Explanation
// #include <WiFi.h>	        Includes ESP32 WiFi library.
// WiFi.mode(WIFI_STA);	      Sets ESP32 to Station mode.
// WiFi.disconnect();	        Disconnects ESP32 from WiFi.
// WiFi.scanNetworks();	      Scans nearby WiFi networks.
// WiFi.SSID(i);	            Gets the network name.
// WiFi.RSSI(i);	            Gets the signal strength.
// WiFi.channel(i);	          Gets the WiFi channel number.
// WiFi.scanDelete();	        Deletes previous scan results.