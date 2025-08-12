/*
  Código para movimentar um robô com dois motores com Ponte H L298N (padrão e mini),
  utilizando chassi modelo 2WD.
  Objetivo: Movimentar o robô de chassi modelo 2WD e demonstrar o uso de funções para
  otimizar o código.
  
  By Professor Claudio Roberto da Silva
*/

// Definição dos pinos conectados à Ponte H
#define IN1 10  // Motor A - sentido frente
#define IN2 9   // Motor A - sentido ré
#define IN3 6   // Motor B - sentido frente
#define IN4 5   // Motor B - sentido ré

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pararMotores();
}

void loop() {
  frente(120, 150);   // Motor A = 120, Motor B = 150
  delay(2000);

  pararMotores();
  delay(200);
  
  tras(130, 140);     // Motor A = 130, Motor B = 140
  delay(2000);

  pararMotores();
  delay(200);
}

// ---- Funções de movimento ----

// Avançar
void frente(int vel_IN1, int vel_IN3) {
  analogWrite(IN1, vel_IN1); // Motor A frente
  digitalWrite(IN2, LOW);

  analogWrite(IN3, vel_IN3); // Motor B frente
  digitalWrite(IN4, LOW);
}

// Ré
void tras(int vel_IN2, int vel_IN4) {
  digitalWrite(IN1, LOW);
  analogWrite(IN2, vel_IN2); // Motor A ré

  digitalWrite(IN3, LOW);
  analogWrite(IN4, vel_IN4); // Motor B ré
}

// Parar
void pararMotores() {
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
}
