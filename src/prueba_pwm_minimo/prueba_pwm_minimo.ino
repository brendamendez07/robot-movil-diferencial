// ============================================================
// Prueba individual de motores (Parte B) - PWM mínimo de arranque
// Ejecutar con las LLANTAS EN EL AIRE.
// Sube el PWM de 0 a 255 en pasos de 5 (1.5 s por paso) y lo imprime
// en el monitor serie. Anoten el valor en que cada llanta empieza a girar.
// Primero prueba el motor izquierdo y después el derecho.
// Core ESP32 3.x
// ============================================================

const int IN1 = 12, IN2 = 13;   // motor izquierdo
const int IN3 = 14, IN4 = 15;   // motor derecho

void apagar() {
  analogWrite(IN1, 0); analogWrite(IN2, 0);
  analogWrite(IN3, 0); analogWrite(IN4, 0);
}

// pinAdelante: pin que mueve el motor hacia adelante
void barrido(const char* nombre, int pinAdelante) {
  Serial.print("== Motor "); Serial.println(nombre);
  for (int pwm = 0; pwm <= 255; pwm += 5) {
    analogWrite(pinAdelante, pwm);
    Serial.print("PWM = "); Serial.println(pwm);
    delay(1500);
  }
  apagar();
  delay(2000);
}

void setup() {
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  Serial.begin(115200);
  apagar();
  delay(3000);
  barrido("izquierdo", IN1);
  barrido("derecho",   IN3);
  Serial.println("Fin de la prueba");
}

void loop() {}
