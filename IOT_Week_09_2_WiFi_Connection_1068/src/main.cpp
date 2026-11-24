#include <WiFi.h>

const char* ssid="Hassan";
const char* password="12345678";

void setup()
{
    Serial.begin(115200);

    WiFi.mode(WIFI_STA);

    WiFi.begin(ssid,password);

    Serial.print("Connecting to WiFi");

    while(WiFi.status()!=WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nWiFi Connected!");

    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}

void loop()
{
}