# Sensor Ultrassônico SONIC (HC-SR04 compatível)

Pequeno guia didático e exemplo de código para medir distâncias usando o **sensor ultrassônico SONIC** em projetos com **Arduino** (compatível com o clássico HC-SR04).

> **Para que serve?**  
> Medir distâncias de ~2 cm a ~400 cm usando ondas sonoras (40 kHz), muito usado em robótica, obstáculos de carrinhos e projetos STEAM.

---

## Como ele funciona

1. Emissão – O pino TRIG envia um pulso ultrassônico (40 kHz) no ar.


2. Reflexão – Esse som bate em um objeto e retorna.


3. Recepção – O pino ECHO detecta o retorno.


4. Cálculo – O tempo entre o envio e o recebimento é usado para calcular a distância:

<img src="https://latex.codecogs.com/svg.image?&space;Distancia(cm)=\frac{Tempo\;(s)\times&space;Velocidade\;do\;som\;(340\;m/s)}{2}" title=" Distancia(cm)=\frac{Tempo\;(s)\times Velocidade\;do\;som\;(340\;m/s)}{2}" />

O divisor por 2 é porque o som vai e volta.

---

## ⚙️ Especificações rápidas

- **Tensão:** 5 V  
- **Corrente típica:** ~15 mA  
- **Alcance:** 2 cm – 4 m  
- **Precisão:** ±3 mm (condições ideais)  
- **Ângulo efetivo:** ~15°  
- **Pinos:** VCC, TRIG, ECHO, GND

> **Importante (3,3 V):** Se usar ESP8266/ESP32 (3,3 V), **proteja o pino ECHO** com um divisor resistivo (ex.: 1,8 kΩ em série com 3,3 kΩ → ~3,3 V).

---

## 🧭 Pinagem

| Pino | Função                           |
|------|----------------------------------|
| VCC  | +5 V                             |
| TRIG | Disparo do pulso ultrassônico    |
| ECHO | Retorno (largura do pulso)       |
| GND  | Terra (0 V)                      |

---

## 🔌 Ligações (Arduino UNO)

- VCC → **5V**  
- GND → **GND**  
- TRIG → **D9** (exemplo)  
- ECHO → **D10** (exemplo)

> **Dica:** Mantenha cabos curtos e firmes. Evite apontar o sensor para superfícies muito macias (absorvem som) ou muito inclinadas.

---

## ⏱️ Programação Bloqueante vs Não Bloqueante

Ao medir distâncias com o sensor ultrassônico HC-SR04 (SONIC), existem duas abordagens principais de programação:

- **Programação Bloqueante**

Usa a função pulseIn() para medir o tempo do pulso no pino ECHO.

Enquanto espera o retorno, o microcontrolador fica parado, sem executar outras tarefas.

É mais simples e didática, ideal para projetos básicos e testes de bancada.

> long duracao = pulseIn(ECHO, HIGH);  
> float distancia = (duracao * 0.0343) / 2;


➡️ **Desvantagem: se o robô precisa movimentar motores, atualizar um display ou ler outros sensores ao mesmo tempo, tudo fica atrasado porque o código trava durante a medição.**

---

-  **Programação Não Bloqueante**

Não usa pulseIn(). Em vez disso, controla o envio e a leitura do pulso com digitalRead() e micros().

O programa não fica preso esperando; pode executar outras tarefas no loop enquanto aguarda o eco.

É mais complexa, mas essencial em projetos de robótica ou sistemas com múltiplas funções simultâneas.

➡️ **Vantagem:** o microcontrolador continua controlando motores, LEDs, comunicação e outros sensores, sem parar o fluxo do programa.

---

## Exemplos de códigos

- Exemplo 1: Código simples e didático utilizando a função pulseIn. Exemplo de programação bloqueante.

- Exemplo 2: Codigo mais sofisticado, não usa a função pulseIn desta forma temos um exemplo de programação não bloqueante.


---

## ✅ **Resumo:**

- **Bloqueante:** simples e didático, bom para começar.

- **Não bloqueante:** mais avançado, mas indispensável para aplicações em tempo real ou robôs móveis.

---
