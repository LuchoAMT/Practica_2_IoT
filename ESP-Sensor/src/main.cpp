#include <Arduino.h>
#include "WiFiConnectionManager.h"
#include "ClientHandler.h"
#include "UltrasonicSensor.h"

const char* SSID = "TECHLAB";
const char* PASS = "catolica11";
const char* SERVER_IP = "192.168.79.27"; // IP del servidor
const int SERVER_PORT = 8080; // Puerto del servidor

const int TRIGGER_PIN = 18; 
const int ECHO_PIN = 5;

WiFiConnectionManager wifiManager(SSID, PASS);
ClientHandler clientHandler(SERVER_IP, SERVER_PORT);
UltrasonicSensor ultrasonicSensor(TRIGGER_PIN, ECHO_PIN); 

float previousDistance = 0.0f;

void sendDistanceIfChanged() {
    float currentDistance = ultrasonicSensor.getDistance();
    Serial.print("Distance: ");
    Serial.println(currentDistance);

    // Verifica si hay una diferencia significativa en la distancia antes de enviar
    if (abs(currentDistance - previousDistance) > 5) {
        if (clientHandler.connect()) { // Asegura que el cliente esté conectado
            clientHandler.sendDistance(currentDistance); // Envía la distancia
            previousDistance = currentDistance; // Actualiza la distancia previa
        }
    }
}

void setup() {
    Serial.begin(115200);
    wifiManager.connect();
    ultrasonicSensor.setup();
}

void loop() {
    sendDistanceIfChanged();
    delay(500);
}
