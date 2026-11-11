// ============================================================
// Robot móvil diferencial con ESP32-CAM + driver L298N
// Tarea 4 - Robótica | UAEMex, Facultad de Ingeniería
// Equipo: Brenda Miranda Reyes, Valeria Natasha Bejarano Pallares,
//         Francisco David Nava Segundo
// Core ESP32 3.x (analogWrite disponible)
// ============================================================

// Pines del driver (IN1/IN2 = motor izquierdo, IN3/IN4 = motor derecho)
const int IN1 = 12, IN2 = 13;
const int IN3 = 14, IN4 = 15;

// Parámetros calibrables
int velocidad  = 200;   // PWM 0-255 (debe ser mayor al PWM minimo medido)
int t_adelante = 2000;  // ms
int t_atras    = 2000;  // ms
int t_giro90   = 500;   // ms, calibrar con la cruz de angulos en el piso
int t_giro360  = 1800;  // ms, calibrar para vuelta completa

// Escribe PWM en los 4 pines del driver (core ESP32 3.x)
void motores(int a, int b, int c, int d) {
  analogWrite(IN1, a);
  analogWrite(IN2, b);
  analogWrite(IN3, c);
  analogWrite(IN4, d);
}

void adelante()  { motores(velocidad, 0, velocidad, 0); }  // ambos adelante
void atras()     { motores(0, velocidad, 0, velocidad); }  // ambos en reversa
void izquierda() { motores(0, velocidad, velocidad, 0); }  // giro sobre su eje
void derecha()   { motores(velocidad, 0, 0, velocidad); }  // giro sobre su eje
void detener()   { motores(0, 0, 0, 0); }

// Ejecuta un movimiento, espera su duracion, se detiene y pausa 1 s
void ejecutar(const char* nombre, void (*mov)(), int tiempo) {
  Serial.println(nombre);   // etiqueta visible en el monitor serie (video)
  mov();
  delay(tiempo);
  detener();
  delay(1000);
}

void setup() {
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  Serial.begin(115200);
  detener();
  delay(3000);              // tiempo para colocar el robot en el piso
}

void loop() {
  ejecutar("Adelante",  adelante,  t_adelante);
  ejecutar("Atras",     atras,     t_atras);
  ejecutar("Izquierda", izquierda, t_giro90);
  ejecutar("Derecha",   derecha,   t_giro90);
  ejecutar("360",       izquierda, t_giro360);   // opcional (+10 %)
  while (true);             // termina la secuencia
}
