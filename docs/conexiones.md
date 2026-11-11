# Conexiones (ESP32-CAM + L298N)

| L298N | ESP32-CAM | Función |
| --- | --- | --- |
| IN1 | GPIO12 | Motor izquierdo, sentido A |
| IN2 | GPIO13 | Motor izquierdo, sentido B |
| IN3 | GPIO14 | Motor derecho, sentido A |
| IN4 | GPIO15 | Motor derecho, sentido B |
| ENA / ENB | Puentes a 5 V (o PWM) | Habilitación de los motores |
| GND | GND | Tierra común: ESP32-CAM, driver y baterías |
| 12 V / VS | Batería (+) | Alimentación de motores (no usar el pin de 5 V del ESP32-CAM) |

> **Nota:** GPIO12 es un pin de *strapping* (define el voltaje de la flash). Si está en alto al arrancar,
> el ESP32 puede no iniciar. Desconectar IN1 al cargar el programa o cambiar de pin.
> Estos pines coinciden con los de la tarjeta SD, por lo que no se usa la SD.

Diagrama de conexión: ver `media/fotos/` (agregar `diagrama_conexion.png`).
