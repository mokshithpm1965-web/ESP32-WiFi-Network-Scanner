#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("ESP32 WiFi Test Started");

  // Set the ESP32 to Wi-Fi station mode.
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

  Serial.println("Scanning WiFi networks...");

  // Scan for nearby Wi-Fi networks.
  int networks = WiFi.scanNetworks();

  if (networks == 0) {
    Serial.println("No networks found");
  } else {
    Serial.println("Networks found:");

    for (int i = 0; i < networks; i++) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" | Signal: ");
      Serial.print(WiFi.RSSI(i));
      Serial.println(" dBm");
    }
  }

  // Free memory used by the scan results.
  WiFi.scanDelete();
}

void loop() {
  // This program scans once when the ESP32 starts.
}
