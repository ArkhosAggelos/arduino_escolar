# Potenciômetro com Arduino

## O que é um Potenciômetro?

O **potenciômetro** é um componente eletrônico que funciona como um resistor variável. Ele possui três terminais: dois nas extremidades da resistência e um central (cursor), que desliza ao girar o eixo do potenciômetro. Isso permite ajustar manualmente a resistência e, consequentemente, a tensão de saída.

## Como funciona com Arduino?

Ao conectar um potenciômetro ao Arduino, normalmente usamos dois terminais para VCC (5V) e GND, e o terminal do meio (cursor) para um pino analógico do Arduino (exemplo: A0). Assim, ao girar o potenciômetro, variamos a tensão lida pelo Arduino de 0V a 5V, o que resulta em valores de 0 a 1023 na leitura analógica.

### Esquema de ligação

```
 [5V] ---[Potenciômetro]--- [GND]
                |
              [A0]
```

- Terminal 1: 5V
- Terminal 2 (centro): A0 (entrada analógica)
- Terminal 3: GND

---

## Exemplo 1: Lendo o valor do potenciômetro

```cpp
/*
 * Exemplo básico: leitura do potenciômetro
 */

const int pinoPot = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int valor = analogRead(pinoPot); // valor de 0 a 1023
  Serial.print("Valor do potenciometro: ");
  Serial.println(valor);
  delay(200);
}
```

---

## Exemplo 2: Usando como controle de brilho de LED

```cpp
/*
 * Controle de brilho de LED com potenciômetro
 */

const int pinoPot = A0;
const int pinoLED = 9; // Pino PWM

void setup() {
  pinMode(pinoLED, OUTPUT);
}

void loop() {
  int valor = analogRead(pinoPot);
  int brilho = map(valor, 0, 1023, 0, 255); // Ajusta para faixa PWM
  analogWrite(pinoLED, brilho);
}
```

---

## Exemplo 3: Potenciômetro como Joystick (2 eixos)

Quando usamos dois potenciômetros (um para eixo X e outro para eixo Y), podemos simular um joystick analógico simples, muito usado em controles de videogame.

### Esquema

- Potenciômetro 1: cursor em A0 (Eixo X)
- Potenciômetro 2: cursor em A1 (Eixo Y)

### Exemplo de código

```cpp
/*
 * Potenciômetro como Joystick de 2 eixos (X e Y)
 */

const int eixoX = A0;
const int eixoY = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int valorX = analogRead(eixoX); // 0 a 1023
  int valorY = analogRead(eixoY); // 0 a 1023
  Serial.print("X: ");
  Serial.print(valorX);
  Serial.print(" | Y: ");
  Serial.println(valorY);
  delay(200);
}
```

---

## Aplicações do Potenciômetro com Arduino

- Controle de brilho de LEDs
- Ajuste de velocidade de motores
- Navegação em menus (com um botão)
- Controle de servo motores (posição)
- Simulação de joystick analógico (2 ou 3 potenciômetros)
- Ajuste de volume em projetos de áudio

---

## Dicas

- Use potenciômetros lineares (A) para medições proporcionais.
- Fixe bem o potenciômetro na protoboard para evitar mau contato.
- Para projetos de joystick, use potenciômetros de valor entre 10kΩ e 50kΩ.

---

Feito por © 2024 ArkhosAggelos

---

Se quiser adicionar imagens, diagramas ou links para mais exemplos, basta avisar!