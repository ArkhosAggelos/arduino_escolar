/*
  Código para movimentar um robô com dois motores com Ponte H utilizando chassi modelo 2WD.
  
  Objetivo: Movimentar o robô de chassi modelo 2WD e demonstrar o uso de funções para
  otimizar o código. Ao movimentar o robô para frente e para trás, veja se os motores estão 
  girando no mesmo sentido. Se os motores estiverem girando em sentidos contrários, o robô vai 
  rotacionar sobre o próprio eixo. Neste caso, apenas inverta as conexões do motor que está 
  girando o contrário do que deveria. 
  
  Se desejar movimentar o robô para trás, retire as barras "//" de comentário das linhas correspondentes.
  
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
  frente(120, 150, 2000);   // Motor A = 120, Motor B = 150

  pararMotores(200);
  
  //tras(130, 140, 2000);     // Motor A = 130, Motor B = 140

  //pararMotores(200);
}

// ---- Funções de movimento ----

// Movimento para FRENTE
void frente(int vel_IN1, int vel_IN3, int tempo) {
  analogWrite(IN1, vel_IN1); // Motor A frente
  digitalWrite(IN2, LOW);

  analogWrite(IN3, vel_IN3); // Motor B frente
  digitalWrite(IN4, LOW);

  delay(tempo);
}

// Movimento para TRÁS
void tras(int vel_IN2, int vel_IN4, int tempo) {
  digitalWrite(IN1, LOW);
  analogWrite(IN2, vel_IN2); // Motor A ré

  digitalWrite(IN3, LOW);
  analogWrite(IN4, vel_IN4); // Motor B ré
  
  delay(tempo);
}

// DESLIGA os motores
void pararMotores(int tempo) {
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
  
  delay(tempo);
}

