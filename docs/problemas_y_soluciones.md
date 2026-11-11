# Problemas encontrados y soluciones

| Problema | Causa probable | Solución |
| --- | --- | --- |
| El ESP32-CAM no arranca con el driver conectado | GPIO12 es pin de strapping | Desconectar IN1 al cargar el código o cambiar de pin |
| Un motor gira al revés | Polaridad de cables invertida | Invertir los cables del motor o la lógica en el código |
| El robot se reinicia al arrancar los motores | Caída de voltaje / picos de corriente | Baterías cargadas, tierras comunes, capacitor |
| El robot no se mueve con PWM bajo | PWM menor al mínimo del motor | Usar velocidad por encima del PWM mínimo medido |
| Los giros cambian entre repeticiones | Batería descargada o superficie distinta | Recalibrar tiempos con batería cargada |
