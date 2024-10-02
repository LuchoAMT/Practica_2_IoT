#include "LEDController.h"

LEDController::LEDController(int l1, int l2, int l3, int l4) 
    : led1(l1), led2(l2), led3(l3), led4(l4) {}

void LEDController::setup() {
    // Configura los pines de los LEDs como salidas
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
}

void LEDController::controlLEDs(const String& command) {
    // Apaga todos los LEDs inicialmente
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);

    // Controla los LEDs según el comando recibido
    if (command == "LED:1") {
        digitalWrite(led1, HIGH);
    } else if (command == "LED:2") {
        digitalWrite(led2, HIGH);
    } else if (command == "LED:3") {
        digitalWrite(led3, HIGH);
    } else if (command == "LED:4") {
        digitalWrite(led4, HIGH);
    } else if (command == "LED:ALL") {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
    } else if (command == "LED:NONE") {
        // Todos los LEDs permanecen apagados
    }
}
