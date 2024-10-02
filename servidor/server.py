import socket

# Función para decidir qué LED activar
def processDistance(distance):
    if 3 <= distance < 30:
        return "LED:1"
    elif 30 <= distance < 60:
        return "LED:2"
    elif 60 <= distance < 90:
        return "LED:3"
    elif 90 <= distance < 120:
        return "LED:4"
    elif 120 <= distance < 400:
        return "LED:ALL"
    else:
        return "LED:NONE"

# Configuración del servidor
sensorSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ledSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sensorSocket.bind(('0.0.0.0', 8080))
sensorSocket.listen(1)

ledSocket.bind(('0.0.0.0', 8081))
ledSocket.listen(1)

print("Waiting for ESP-32 conections...")

try:
    sensorConn, _ = sensorSocket.accept()
    print("Sensor ESP-32 connected successfully")
    ledConn, _ = ledSocket.accept()
    print("LEDs ESP-32 connected successfully")

    print("ESP-32 conections successful")

    while True:
        data = sensorConn.recv(1024).decode('utf-8')
        if data.startswith("SENSOR:"):
            # Extraer distancia
            try:
                distance = float(data.split(":")[1])
                print(f"Distance recieved: {distance} cm")

                # Procesar la distance y decidir qué LED encender
                ledCommand = processDistance(distance)
                print(f"Command sent: {ledCommand}")

                # Enviar el comando al ESP-32 que controla los LEDs
                ledConn.send((ledCommand + '\n').encode('utf-8'))
            except ValueError:
                print("Error: Non valid distance value")
except Exception as e:
    print(f"Conection error: {e}")
finally:
    sensorConn.close()
    ledConn.close()
    sensorSocket.close()
    ledSocket.close()