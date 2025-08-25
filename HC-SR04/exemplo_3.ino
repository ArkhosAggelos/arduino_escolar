/*
  Programação do sensor Ultrassom (HC-SR04) não bloqueante com interrupção no ECHO
  Pinos: TRIG -> D9
  ECHO -> D2 (INT0 no Arduino UNO)
  
  Autor: Prof. Claudio Roberto da Silva
*/

#define TRIG 9
#define ECHO 2  // precisa ser D2 (INT0) no UNO para attachInterrupt

// Controle de medição
const unsigned long TEMPO_MAXIMO_US = 25000UL; // ~4 m
const unsigned long INTERVALO_MS    = 100;     // intervalo entre disparos

// Variáveis compartilhadas com a ISR
volatile unsigned long tInicio = 0;      // marca o início do pulso
volatile unsigned long tFim = 0;         // marca o fim do pulso
volatile bool pulsoPronto = false;       // sinaliza que uma medição terminou
volatile bool aguardandoPulso = false;   // indica se estamos aguardando o eco

unsigned long ultimoDisparoMs = 0;       // controle de tempo para novos disparos

// Interrupção: captura subida e descida do pulso no ECHO
void isrEchoChange() {
  if (digitalRead(ECHO) == HIGH) {
    // início do pulso
    tInicio = micros();
    aguardandoPulso = true;
  } else {
    // fim do pulso (só se já tínhamos início)
    if (aguardandoPulso) {
      tFim = micros();
      pulsoPronto = true;     
      aguardandoPulso = false;
    }
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  digitalWrite(TRIG, LOW);

  pinMode(ECHO, INPUT);
  attachInterrupt(digitalPinToInterrupt(ECHO), isrEchoChange, CHANGE);
}

void disparaTrig() {
  // pulso de 10 µs no TRIG
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
}

void loop() {
  unsigned long agoraMs = millis();

  // 1) Dispara periodicamente se não há leitura pendente
  if (!aguardandoPulso && !pulsoPronto && (agoraMs - ultimoDisparoMs >= INTERVALO_MS)) {
    disparaTrig();
    ultimoDisparoMs = agoraMs;
  }

  // 2) Timeout: se demorou demais e não houve descida, cancela
  if (aguardandoPulso) {
    unsigned long tempoDecorrido = micros() - tInicio;
    if (tempoDecorrido > TEMPO_MAXIMO_US) {
      aguardandoPulso = false;
      Serial.println("Fora de alcance (timeout)");
    }
  }

  // 3) Se temos uma medida pronta, processa
  if (pulsoPronto) {
    noInterrupts();
    unsigned long inicio = tInicio;
    unsigned long fim    = tFim;
    pulsoPronto = false;
    interrupts();

    unsigned long duracao = (fim >= inicio) ? (fim - inicio) : 0;
    if (duracao > 0 && duracao <= TEMPO_MAXIMO_US) {
      float distancia = (duracao * 0.0343f) / 2.0f; // em cm
      if (distancia >= 2 && distancia <= 400) {
        Serial.print("Distancia: ");
        Serial.print(distancia, 1);
        Serial.println(" cm");
      } else {
        Serial.println("Fora de alcance (faixa inválida)");
      }
    } else {
      Serial.println("Fora de alcance (pulso inválido)");
    }
  }

  // 🔄 Aqui pode rodar outras lógicas: motores, displays, sensores etc.
}
