#include <Arduino.h>
#include "WiFiConnectionManager.h"
#include "ClientHandler.h"
#include "LEDController.h"

const char* SSID = "TECHLAB";
const char* PASS = "catolica11";
const char* SERVER_IP = "192.168.79.27"; // IP del servidor
const int SERVER_PORT = 8081; // Puerto del servidor

const int LED1_PIN = 26;  
const int LED2_PIN = 25;  
const int LED3_PIN = 33; 
const int LED4_PIN = 32; 

WiFiConnectionManager wifiManager(SSID, PASS);
ClientHandler clientHandler(SERVER_IP, SERVER_PORT);
LEDController ledController(LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN); // Reemplaza con tus pines

void commandInterpreter(){
    if (clientHandler.connect()) {
        String command = clientHandler.receiveCommand();
        if (command.length() > 0) {
            Serial.print("Recieved command: ");
            Serial.println(command);
            ledController.controlLEDs(command);
        }
        
    }
    
}

void setup() {
    Serial.begin(115200);
    wifiManager.connect();
    ledController.setup();
}

void loop() {
    commandInterpreter();
}
