/*
  Código para teste de motores com Ponte H L298N (padrão e mini)
  Objetivo: verificar se os motores giram para frente
  
  By Professor Claudio Roberto da Silva
*/

// Definição dos pinos conectados à Ponte H
#define IN1 10  // Entrada 1 do Motor A 
#define IN2 9   // Entrada 2 do Motor A
#define IN3 6   // Entrada 1 do Motor B 
#define IN4 5   // Entrada 2 do Motor B

void setup() {
    // Configura todos os pinos como saída
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    // Garante que todos os motores comecem desligados
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void loop() {
    /*
      Para girar um motor em uma direção:
      - Um pino recebe PWM (controle de velocidade)
      - O outro pino fica em LOW (0V)
      
      Aqui configuramos ambos os motores para girar "para frente"
      com velocidade média (150 de 0 a 255).
      Caso um ou os dois motores girem "para trás", inverta os cabos 
      de ligação do motor na Ponte H.
    */

    // Motor A (ligado em IN1 e IN2) - frente
    analogWrite(IN1, 150);  // Sinal PWM para velocidade
    digitalWrite(IN2, LOW); 

    // Motor B (ligado em IN3 e IN4) - frente
    analogWrite(IN3, 150);  // Sinal PWM para velocidade
    digitalWrite(IN4, LOW);
}

/*
  Depois dos testes ser concluídos é hora de criar as funções dos movimentos.
  Isso vai fazer com que o código fique bem mais claro e limpo.
*/