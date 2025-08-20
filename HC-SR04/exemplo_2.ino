/*
  Exemplo não bloqueante - Sensor Ultrassônico HC-SR04
  Mede distância sem usar pulseIn(), usando micros() e máquina de estados.
  Autor: Prof. Claudio Roberto da Silva
*/

#define TRIG 9
#define ECHO 10

// Controle do pulso
unsigned long inicioPulso = 0;  // marca o início do pulso de eco
unsigned long duracao = 0;      // duração do pulso em microssegundos
bool aguardandoEco = false;     // indica se estamos esperando pelo eco

// Controle de tempo para não disparar o TRIG toda hora
unsigned long ultimoDisparo = 0;
const unsigned long intervaloMedida = 100; // em ms

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  digitalWrite(TRIG, LOW);
}

void loop() {
  unsigned long agora = millis();

  // Dispara o TRIG periodicamente
  if (!aguardandoEco && (agora - ultimoDisparo >= intervaloMedida)) {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    aguardandoEco = true;
    inicioPulso = 0;
    duracao = 0;
    ultimoDisparo = agora;
  }

  // Verifica o ECHO sem travar
  if (aguardandoEco) {
    if (digitalRead(ECHO) == HIGH && inicioPulso == 0) {
      // início do pulso
      inicioPulso = micros();
    }
    if (digitalRead(ECHO) == LOW && inicioPulso > 0) {
      // fim do pulso
      duracao = micros() - inicioPulso;
      aguardandoEco = false;

      // Calcula a distância
      float distancia = (duracao * 0.0343) / 2;
      if (distancia >= 2 && distancia <= 400) {
        Serial.print("Distancia: ");
        Serial.print(distancia, 1);
        Serial.println(" cm");
      } else {
        Serial.println("Fora de alcance");
      }
    }
  }

  // 🔄 Aqui pode rodar outras lógicas do robô
  // mover motores, ler botões, atualizar display, etc.
}
