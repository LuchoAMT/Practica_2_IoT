#include "WiFiConnectionManager.h"

// Constructor que inicializa el SSID y la contraseña
WiFiConnectionManager::WiFiConnectionManager(const char* wifiSSID, const char* wifiPass)
    : SSID(wifiSSID), PASS(wifiPass) {}

// Método para conectar al WiFi
void WiFiConnectionManager::connect() {
    Serial.print("Conectando a la red WiFi: ");
    Serial.println(SSID);

    WiFi.begin(SSID, PASS);  // Inicia la conexión al WiFi

    // Espera a que la conexión se establezca
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);  // Espera medio segundo
        Serial.print(".");  // Indica que está intentando conectar
    }

    Serial.println("\nConectado al WiFi");
    Serial.print("Dirección IP: ");
    Serial.println(WiFi.localIP());  // Muestra la dirección IP asignada
}

