/*
  ============================================================
  Projeto: Controle de Robô 2WD com Ponte H
  Placa: Arduino UNO (ou compatível)
  Autor: Professor Claudio Roberto da Silva
  ============================================================

  📌 Descrição:
  Código para movimentar um robô de chassi modelo 2WD
  utilizando uma Ponte H (L298N ou similar). O robô
  possui dois motores DC independentes.

  🎯 Objetivo:
  Demonstrar o uso de funções para otimizar o código e
  facilitar o controle de movimentos como "frente" e "trás".
  Esse código também serve para testar se os motores estão
  girando no mesmo sentido.

  ⚠ Observação Importante:
  - Se ao movimentar para frente o robô girar sobre o próprio eixo,
    significa que um motor está invertido. Basta inverter as conexões
    desse motor na Ponte H.
  - Para habilitar o movimento para trás, remova as barras "//" de
    comentário das linhas correspondentes no loop().

  💡 Dica:
  Ajuste as velocidades de cada motor separadamente para corrigir
  pequenas diferenças e garantir que o robô siga em linha reta.
  
*/

// ================================
// Definição dos pinos conectados à Ponte H
// Cada motor é controlado por dois pinos (sentido frente e sentido ré)
// Motor A -> IN1 e IN2
// Motor B -> IN3 e IN4
// ================================
#define IN1 10  // Motor A - sentido frente
#define IN2 9   // Motor A - sentido ré
#define IN3 6   // Motor B - sentido frente
#define IN4 5   // Motor B - sentido ré

// ================================
// Função de configuração
// ================================
void setup() {
  // Define todos os pinos como saída digital
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Garante que o robô inicie com os motores desligados
  pararMotores();
}

// ================================
// Função principal - loop infinito
// ================================
void loop() {
  // Movimento para frente:
  // Motor A com velocidade 120 (de 0 a 255)
  // Motor B com velocidade 150 (de 0 a 255)
  // Duração: 2000 ms (2 segundos)
  frente(120, 150, 2000);

  // Para os motores por 200 ms
  pararMotores(200);
  
  // Movimento para trás:
  // Motor A com velocidade 120 (de 0 a 255)
  // Motor B com velocidade 150 (de 0 a 255)
  // Duração: 2000 ms (2 segundos)
  // tras(130, 140, 2000);

  // Para os motores por 200 ms (comentado)
  // pararMotores(200);
}

// ================================
// ---- Funções de movimento ----
// ================================

// Movimento para FRENTE
// vel_IN1 -> velocidade do Motor A para frente (0 a 255)
// vel_IN3 -> velocidade do Motor B para frente (0 a 255)
// tempo   -> tempo do movimento em milissegundos
void frente(int vel_IN1, int vel_IN3, int tempo) {
  analogWrite(IN1, vel_IN1); // Motor A recebe PWM para frente
  digitalWrite(IN2, LOW);    // Motor A não recebe sinal de ré

  analogWrite(IN3, vel_IN3); // Motor B recebe PWM para frente
  digitalWrite(IN4, LOW);    // Motor B não recebe sinal de ré

  delay(tempo); // Aguarda o tempo definido antes de encerrar a função
}

// Movimento para TRÁS
// vel_IN2 -> velocidade do Motor A para ré (0 a 255)
// vel_IN4 -> velocidade do Motor B para ré (0 a 255)
// tempo   -> tempo do movimento em milissegundos
void tras(int vel_IN2, int vel_IN4, int tempo) {
  digitalWrite(IN1, LOW);    // Motor A não recebe sinal de frente
  analogWrite(IN2, vel_IN2); // Motor A recebe PWM para ré

  digitalWrite(IN3, LOW);    // Motor B não recebe sinal de frente
  analogWrite(IN4, vel_IN4); // Motor B recebe PWM para ré
  
  delay(tempo); // Aguarda o tempo definido
}

// DESLIGA os motores
// tempo -> tempo de pausa com motores desligados
void pararMotores(int tempo) {
  analogWrite(IN1, 0); // Motor A frente desligado
  analogWrite(IN2, 0); // Motor A ré desligado
  analogWrite(IN3, 0); // Motor B frente desligado
  analogWrite(IN4, 0); // Motor B ré desligado
  
  delay(tempo); // Mantém a pausa com motores desligados
}
