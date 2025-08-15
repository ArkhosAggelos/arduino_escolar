/*
  Laboratório de Curvas - Robô com Ponte H
  Três tipos de curva:
    1) Curva suave (reduz velocidade de um lado)
    2) Curva em pivô (um lado parado)
    3) Giro no próprio eixo (um lado frente, outro ré)
  
  By Professor Claudio Roberto da Silva
*/

// Pinos PWM (UNO): 5, 6, 9, 10 são válidos
#define IN1 10
#define IN2 9
#define IN3 6
#define IN4 5

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  parar();
  delay(300);
}

void loop() {
  // Curva suave para a direita por 1,5 s
  giroSuaveDireita(150, 1500);
  parar();
  delay(800);
  
  //Curva suave para a esquerda por 1,5s
  giroSuaveEsquerda(150,1500);
  parar();
  delay(800);
}

// Zera todos os PWMs
void parar() {
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
}

// Curva suave à direita: lado direito mais lento
void giroSuaveDireita(int velocidade, int tempo) {
  // Lado esquerdo (Motor A) rápido, para frente
  analogWrite(IN1, velocidade);
  analogWrite(IN2, 0);

  // Lado direito (Motor B) mais lento, para frente
  analogWrite(IN3, velocidade / 2);  // metade da velocidade
  analogWrite(IN4, 0);

  delay(tempo);
}

// Curva suave à esquerda: lado esquerdo mais lento
void giroSuaveEsquerda(int velocidade, int tempo) {
  // Lado esquerdo (Motor A) mais lentos, para frente
  analogWrite(IN1, celocidade /2); // metade da velocidade
  analogWrite(IN2, 0);

  // Lado direito (Motor B) rápido, para frente
  analogWrite(IN3, velocidade); 
  analogWrite(IN4, 0);

  delay(tempo);
}
