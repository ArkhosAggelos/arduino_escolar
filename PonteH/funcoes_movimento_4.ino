/*
  ============================================================
  Laboratório de Curvas - Robô com Ponte H (2WD)
  Três formas de fazer curva:
    1) Curva suave .......... reduz velocidade de um lado
    2) Curva em pivô ........ um lado anda e o outro fica parado
    3) Giro no próprio eixo .. um lado frente e o outro ré (tank turn)

  Dica: ajuste as velocidades para “sentir” cada efeito.
  
  By Professor Claudio Roberto da Silva
  ============================================================
*/

// Pinos PWM (UNO): 5, 6, 9 e 10 são válidos
#define IN1 10  // Motor A - frente
#define IN2 9   // Motor A - ré
#define IN3 6   // Motor B - frente
#define IN4 5   // Motor B - ré

// ---------- Utilitário simples ----------
int clamp255(int v) { return v < 0 ? 0 : (v > 255 ? 255 : v); }

// ---------- Setup ----------
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  parar();                // começa parado (segurança)
  delay(300);
}

// ---------- Demonstração sequencial ----------
void loop() {
  // ============= 1) CURVA SUAVE =============
  // Direita: lado direito mais lento
  giroSuaveDireita(150, 0.5, 1500);   // base=150, lado interno=50% da base
  parar(); delay(800);

  // Esquerda: lado esquerdo mais lento
  giroSuaveEsquerda(150, 0.5, 1500);
  parar(); delay(800);

  // ============= 2) CURVA EM PIVÔ ===========
  // Direita: motor direito parado, esquerdo anda
  pivoDireita(160, 1200);
  parar(); delay(800);

  // Esquerda: motor esquerdo parado, direito anda
  pivoEsquerda(160, 1200);
  parar(); delay(800);

  // ============= 3) GIRO NO EIXO ============
  // Direita: A frente, B ré (horário)
  giroNoEixoDireita(150, 1000);
  parar(); delay(800);

  // Esquerda: A ré, B frente (anti-horário)
  giroNoEixoEsquerda(150, 1000);
  parar(); delay(2000);
}

// ===================================================================
//                            Funções base
// ===================================================================

// Zera todos os PWMs (parada total)
void parar() {
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
}

// ---------------- 1) Curva suave ----------------
// Parâmetros:
//  - base: velocidade do lado externo (0..255)
//  - fator: fração 0.0..1.0 aplicada ao lado interno (ex.: 0.5 = metade)
//  - tempo: duração em ms

// Curva suave à direita: lado direito (Motor B) mais lento
void giroSuaveDireita(int base, float fator, int tempo) {
  int vRap = clamp255(base);
  int vLen = clamp255((int)(base * fator));

  // Lado esquerdo (A) rápido, para frente
  analogWrite(IN1, vRap);
  digitalWrite(IN2, LOW);

  // Lado direito (B) lento, para frente
  analogWrite(IN3, vLen);
  digitalWrite(IN4, LOW);

  delay(tempo);
}

// Curva suave à esquerda: lado esquerdo (Motor A) mais lento
void giroSuaveEsquerda(int base, float fator, int tempo) {
  int vRap = clamp255(base);
  int vLen = clamp255((int)(base * fator));

  // Lado esquerdo (A) lento, para frente
  analogWrite(IN1, vLen);    // (corrigido: era "celocidade /2")
  digitalWrite(IN2, LOW);

  // Lado direito (B) rápido, para frente
  analogWrite(IN3, vRap);
  digitalWrite(IN4, LOW);

  delay(tempo);
}

// ---------------- 2) Curva em pivô ----------------
// Um lado parado, outro anda para frente

void pivoDireita(int velocidade, int tempo) {
  // Esquerdo (A) anda; Direito (B) parado
  analogWrite(IN1, clamp255(velocidade));
  digitalWrite(IN2, LOW);
  analogWrite(IN3, 0);
  digitalWrite(IN4, LOW);
  delay(tempo);
}

void pivoEsquerda(int velocidade, int tempo) {
  // Direito (B) anda; Esquerdo (A) parado
  analogWrite(IN1, 0);
  digitalWrite(IN2, LOW);
  analogWrite(IN3, clamp255(velocidade));
  digitalWrite(IN4, LOW);
  delay(tempo);
}

// ---------------- 3) Giro no próprio eixo (tank turn) ----------------
// Um lado frente e o outro ré, com mesma intensidade

void giroNoEixoDireita(int velocidade, int tempo) {
  int v = clamp255(velocidade);
  // A frente
  analogWrite(IN1, v);
  digitalWrite(IN2, LOW);
  // B ré
  digitalWrite(IN3, LOW);
  analogWrite(IN4, v);
  delay(tempo);
}

void giroNoEixoEsquerda(int velocidade, int tempo) {
  int v = clamp255(velocidade);
  // A ré
  digitalWrite(IN1, LOW);
  analogWrite(IN2, v);
  // B frente
  analogWrite(IN3, v);
  digitalWrite(IN4, LOW);
  delay(tempo);
}
