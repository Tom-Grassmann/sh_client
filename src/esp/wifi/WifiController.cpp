#include "../../include/Include.h"

void WifiController::connectToWiFi(const char * ssid, const char * pwd) {

    int ledState = 0;

    Serial.println("Connecting to WiFi network: " + String(ssid));

    WiFi.begin(ssid, pwd);

    while (WiFi.status() != WL_CONNECTED)
    {
        // Blink LED while we're connecting:
        digitalWrite(2, ledState);
        ledState = (ledState + 1) % 2; // Flip ledState
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi connected!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}