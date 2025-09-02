/* 
    Código didático de exemplo para uso em aulas de programação e robótica.
    Com um circuito simples contendo apenas um LDR e um resistor, conforme
    o esquema abaixo:

    (5V) --- [LDR] ---+--- [Resistor] --- (GND)
                  |
               (A0)
    
    O resistor pode ser de 10k para começar, pode-se mudar esse valor como 
    for necessário para ajustar a faixa de valores..

    ©2025 By Professor Claudio Roberto da Silva
*/

#define pinoLDR A0                    // Defina o pino onde o LDR está conectado

void setup() {
  Serial.begin(9600);                 // Inicializa a comunicação serial
}

void loop() {
  int valorLDR = analogRead(pinoLDR); // Lê o valor da entrada analógica

  Serial.print("Valor do LDR: ");
  Serial.println(valorLDR);           // Exibe o valor no Monitor Serial

  delay(1000);                        // Aguarda um segundo entre as leituras
}