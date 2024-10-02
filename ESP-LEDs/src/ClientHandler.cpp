#include "ClientHandler.h"

// Constructor que inicializa la dirección IP del servidor y el puerto
ClientHandler::ClientHandler(const char* ip, int port) : SERVERIP(ip), SERVERPORT(port) {}

// Método para conectarse al servidor
bool ClientHandler::connect() {
    if (!client.connected()) {  // Solo intenta conectar si no está conectado
        if (client.connect(SERVERIP, SERVERPORT)) {
            Serial.println("Conected to server");
            return true;
        } else {
            Serial.println("Conection to server failed");
            return false;
        }
    }
    return true;  // Ya está conectado
}

// Método para enviar la distancia al servidor
void ClientHandler::sendDistance(float distance) {
    if (connect()) {  // Asegúrate de que estamos conectados antes de enviar
        String message = "SENSOR:" + String(distance);  // Mensaje a enviar
        client.println(message);  // Usa println para agregar un salto de línea
        Serial.print("Distance sent: ");
        Serial.println(distance);
    } else {
        Serial.println("Unable to send distance to server");
    }
}

// Método para recibir comandos del servidor
String ClientHandler::receiveCommand() {
    String command = "";  // Variable para almacenar el comando

    if (client.available()) {  // Verifica si hay datos disponibles
        command = client.readStringUntil('\n');  // Lee hasta el salto de línea
        Serial.print("Recieved Command: ");
        Serial.println(command);
    }
    return command;  // Devuelve el comando recibido
}
