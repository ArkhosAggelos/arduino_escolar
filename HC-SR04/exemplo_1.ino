/*
  Sensor Ultrassônico (HC-SR04 ou compatível)
  Exemplo simples sem bibliotecas.
  Mede e mostra a distância em centímetros.
*/

#define TRIG 9   // Pino do TRIG
#define ECHO 10  // Pino do ECHO

void setup() {
  Serial.begin(9600);       // Comunicação serial
  pinMode(TRIG, OUTPUT);    // TRIG como saída
  pinMode(ECHO, INPUT);     // ECHO como entrada
}

void loop() {
  long duracao;     // Duração do tempo de ida e volta do pulso sonoro.
  float distancia;  // Variável para amarzenar o valor da distância do obstáculo.

  // Gera pulso no TRIG
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Mede o tempo de resposta no ECHO
  duracao = pulseIn(ECHO, HIGH);

  // Converte tempo em distância (cm) do obstáculo.
  distancia = (duracao * 0.0343) / 2;

  // Exibe no Serial Monitor
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  delay(500); // espera meio segundo
}