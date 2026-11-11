# Calibración y resultados

## Prueba individual de motores (Parte B)

| Motor | PWM mínimo | Sentido correcto | Observaciones |
| --- | --- | --- | --- |
| Izquierdo | 95 | Sí | Inicia movimiento estable desde PWM=95. Cables directos (OUT1/OUT2). |
| Derecho | 100 | Sí | Requiere PWM=100 para vencer la fricción estática. Se invirtió la polaridad en OUT3/OUT4. |

## Calibración de movimientos (Parte D, promedio de 3 repeticiones)

| Movimiento | Tiempo (ms) | Resultado esperado | Resultado medido | Error |
| --- | --- | --- | --- | --- |
| Adelante | 2000 | Línea recta de 1 m | Desviación lateral: 4.2 cm | 4.2 % |
| Atrás | 2000 | Regreso al punto de inicio | Distancia al origen: 3.8 cm | 3.8 % |
| Izquierda | 500 | 90° | 87.5° | 2.77 % |
| Derecha | 500 | 90° | 91.8° | 2 % |
| 360° (opc.) | 1800 | 360° | 355° | 1.38 % |

## Modelo cinemático

v = (vR + vL) / 2  ,  ω = (vR − vL) / L

Giro sobre su eje (vR = +v, vL = −v): ω = 2v/L

- t₉₀ = πL / (4v)
- t₃₆₀ = πL / v

Datos del equipo: L = 0.135 m, v = 0.50 m/s → t₉₀ teórico = 0.212 s, t₉₀ medido = 0.500 s
(error ≈ 135.85 %). La diferencia se explica por el patinaje, la aceleración inicial de los
motores, la fricción y el nivel de batería.
