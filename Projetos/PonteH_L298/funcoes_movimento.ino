/*
  Código para movimentar um robô com dois motores com Ponte H L298N (padrão e mini),
  utilizando chassi modelo 2WD.
  Objetivo: Movimentar o robô de chassi modelo 2WD e demonstrar o uso de funções para
  otimizar o código
  
  By Professor Claudio Roberto da Silva
*/

// Definição dos pinos conectados à Ponte H
#define IN1 10  // Motor A - entrada 1
#define IN2 9   // Motor A - entrada 2
#define IN3 6   // Motor B - entrada 1
#define IN4 5   // Motor B - entrada 2

// Velocidade dos motores (0 a 255)
int velocidade = 150; // Velocidade média

void setup() {
  // Configura todos os pinos como saída
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Motores começam desligados
  pararMotores();
}

void loop() {
  // Sequência de testes de movimento
  frente();
  delay(2000);

  virarDireitaFrente();
  delay(1500);

  virarEsquerdaFrente();
  delay(1500);

  pararMotores();
  delay(1000);

  tras();
  delay(2000);

  virarDireitaTras();
  delay(1500);

  virarEsquerdaTras();
  delay(1500);

  pararMotores();
  delay(2000);
}

// --- Funções de movimento ---

// Movimento para frente
void frente() {
  analogWrite(IN1, velocidade); // Motor A
  digitalWrite(IN2, LOW);

  analogWrite(IN3, velocidade); // Motor B
  digitalWrite(IN4, LOW);
}

// Movimento para trás
void tras() {
  digitalWrite(IN1, LOW);
  analogWrite(IN2, velocidade); // Motor A

  digitalWrite(IN3, LOW);
  analogWrite(IN4, velocidade); // Motor B
}

// Virar para a direita enquanto avança
void virarDireitaFrente() {
  analogWrite(IN1, velocidade); // Motor A
  digitalWrite(IN2, LOW);

  analogWrite(IN3, velocidade / 2); // Motor B mais lento
  digitalWrite(IN4, LOW);
}

// Virar para a esquerda enquanto avança
void virarEsquerdaFrente() {
  analogWrite(IN1, velocidade / 2); // Motor A mais lento
  digitalWrite(IN2, LOW);

  analogWrite(IN3, velocidade); // Motor B
  digitalWrite(IN4, LOW);
}

// Virar para a direita enquanto anda de ré
void virarDireitaTras() {
  digitalWrite(IN1, LOW);
  analogWrite(IN2, velocidade); // Motor A

  digitalWrite(IN3, LOW);
  analogWrite(IN4, velocidade / 2); // Motor B mais lento
}

// Virar para a esquerda enquanto anda de ré
void virarEsquerdaTras() {
  digitalWrite(IN1, LOW);
  analogWrite(IN2, velocidade / 2); // Motor A mais lento

  digitalWrite(IN3, LOW);
  analogWrite(IN4, velocidade); // Motor B
}

// Parar motores
void pararMotores() {
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
}
