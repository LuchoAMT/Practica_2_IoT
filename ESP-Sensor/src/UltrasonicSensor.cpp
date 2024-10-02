#include "UltrasonicSensor.h"

// Constructor que inicializa los pines del sensor
UltrasonicSensor::UltrasonicSensor(int trigger, int echo)
    : triggerPin(trigger), echoPin(echo) {}

// Método para configurar el sensor
void UltrasonicSensor::setup() {
    pinMode(triggerPin, OUTPUT);  // Configura el pin del trigger como salida
    pinMode(echoPin, INPUT);      // Configura el pin del echo como entrada
}

// Método para obtener la distancia en centímetros
float UltrasonicSensor::getDistance() {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    
    long duration = pulseIn(echoPin, HIGH);
    float distance = (duration * 0.0343) / 2; 

    return distance; 
}
