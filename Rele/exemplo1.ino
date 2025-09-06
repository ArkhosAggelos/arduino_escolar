/*
  Exemplo: Controle de Relé com Arduino
  Liga e desliga um relé no pino 7 a cada 2 segundos.
  Professor Claudio Roberto da Silva
*/

#define PIN_RELE 7   // Pino de controle do relé

void setup() {
  pinMode(PIN_RELE, OUTPUT);
  digitalWrite(PIN_RELE, LOW); // Relé inicia desligado
}

void loop() {
  digitalWrite(PIN_RELE, HIGH); // Liga relé
  delay(2000);                  // Aguarda 2s
  digitalWrite(PIN_RELE, LOW);  // Desliga relé
  delay(2000);                  // Aguarda 2s
}