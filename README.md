# Robot móvil diferencial con ESP32-CAM

**Universidad Autónoma del Estado de México – Facultad de Ingeniería**
Materia: Robótica | Tarea 4: Prueba de funcionalidad de un robot móvil diferencial
Profesor: Jaime García García | Toluca, México, 2 de noviembre de 2026

**Integrantes:** Brenda Miranda Reyes · Valeria Natasha Bejarano Pallares · Francisco David Nava Segundo

## Descripción
Robot de ruedas diferencial (kit tipo LaFvin: ESP32-CAM, driver L298N, 2 motores DC, rueda loca y chasis)
que ejecuta las rutinas: **adelante, atrás, giro izquierda, giro derecha y giro de 360°**.
Incluye prueba de PWM mínimo, calibración de tiempos y análisis con el modelo cinemático diferencial.

## Estructura del repositorio
```
robot-movil-diferencial/
├── src/
│   ├── robot_diferencial/robot_diferencial.ino   # Código principal (rutinas de movimiento)
│   └── prueba_pwm_minimo/prueba_pwm_minimo.ino   # Barrido de PWM para cada motor (Parte B)
├── docs/
│   ├── conexiones.md                # Tabla de pines
│   ├── calibracion.md               # Tablas de resultados y cinemática
│   └── problemas_y_soluciones.md
├── media/
│   ├── README.md                    # Enlaces a videos y lista de fotos
│   ├── fotos/
│   └── videos/
└── reporte/                         # Reporte de la práctica
```

## Hardware
ESP32-CAM · Driver L298N · 2 motores DC con llantas · Rueda loca · Baterías (2×18650 o 4×AA) ·
Programador FTDI o ESP32-CAM-MB.

## Conexiones
| L298N | ESP32-CAM |
| --- | --- |
| IN1 | GPIO12 |
| IN2 | GPIO13 |
| IN3 | GPIO14 |
| IN4 | GPIO15 |
| ENA/ENB | Puentes a 5 V (o PWM) |
| GND | GND (tierra común) |
| VS | Batería (+) |

Detalles y advertencias (pin de strapping GPIO12) en [`docs/conexiones.md`](docs/conexiones.md).

## Cómo usarlo
1. Instalar **Arduino IDE** y el soporte de placas **ESP32 (core 3.x)**.
2. Seleccionar la placa *AI Thinker ESP32-CAM*.
3. Abrir `src/robot_diferencial/robot_diferencial.ino` y cargarlo.
4. Abrir el monitor serie a **115200 baudios**; mostrará la etiqueta de cada movimiento.
5. Con el core ESP32 2.x `analogWrite` no existe: usar `ledcSetup/ledcAttachPin` o `digitalWrite`
   con ENA/ENB puenteados a 5 V.

Parámetros a calibrar en el código: `velocidad`, `t_adelante`, `t_atras`, `t_giro90`, `t_giro360`.

## Resultados
| Movimiento | Error |
| --- | --- |
| Adelante (desviación lateral 4.2 cm) | 4.2 % |
| Atrás (3.8 cm al origen) | 3.8 % |
| Izquierda (87.5°) | 2.77 % |
| Derecha (91.8°) | 2 % |
| 360° (355°) | 1.38 % |

Más detalle en [`docs/calibracion.md`](docs/calibracion.md).

## Videos y evidencias
Ver [`media/README.md`](media/README.md).
▶ Secuencia completa: https://youtube.com/shorts/nfuCwTv6ebA?feature=share

## Mejoras propuestas
Encoders + control PID por rueda, IMU (MPU6050) para medir el ángulo real y control por WiFi con
transmisión de video de la ESP32-CAM.

## Seguridad
Desconectar la batería al modificar el cableado, verificar polaridad, no alimentar los motores desde el
pin de 5 V del ESP32-CAM y probar primero con el robot elevado.
