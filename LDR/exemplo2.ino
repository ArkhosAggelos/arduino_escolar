/* 
    Código didático de exemplo para uso em aulas de programação e robótica.
    Com um circuito simples contendo um LDR, um resistor e um led, conforme
    o esquema abaixo:

    (5V) --- [LDR] ---+--- [Resistor] --- (GND)
                      |
                     (A0)

    O resistor pode ser de 10k para começar, pode-se mudar esse valor como 
    for necessário para ajustar a faixa de valores..

    No Arduino.
    (D13) --- [LED] --- [Resistor 220Ω] --- (GND)
    
    ©2025 By Professor Claudio Roberto da Silva
*/

#define pinoLDR A0            // Pino analógico onde o divisor de tensão está ligado
#define pinoLED 13            // Pino digital onde o LED está ligado
const int limiar = 500;       // Valor de corte para acender ou apagar o LED

void setup() {
  pinMode(pinoLED, OUTPUT);   // Define o pino do LED como saída
  Serial.begin(9600);         // Inicializa a comunicação serial
}

void loop() {
  int valorLDR = analogRead(pinoLDR); // Lê o valor do sensor LDR

  Serial.print("Valor LDR: ");
  Serial.println(valorLDR);           // Exibe o valor no monitor serial

  // Acende o LED se estiver escuro (valor alto no LDR)
  if (valorLDR > limiar) {
    digitalWrite(pinoLED, HIGH);      // Liga o LED
  } else {
    digitalWrite(pinoLED, LOW);       // Desliga o LED
  }

  delay(200); // Aguarda um pouco antes da próxima leitura
}