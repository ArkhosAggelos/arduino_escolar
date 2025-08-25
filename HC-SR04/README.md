# Sensor Ultrassônico (HC-SR04 compatível)

Pequeno guia didático e exemplos de código para medir distâncias usando o **sensor ultrassônico** em projetos com **Arduino** (compatível com o clássico HC-SR04).

> **Para que serve?**  
> Medir distâncias de ~2 cm a ~400 cm usando ondas sonoras (40 kHz).  
> Muito usado em robótica, detecção de obstáculos em carrinhos e projetos STEAM.

---

## Como o sensor funciona

1. **Emissão** – O pino **TRIG** envia um pulso ultrassônico (40 kHz) no ar.  
2. **Reflexão** – Esse som bate em um objeto e retorna.  
3. **Recepção** – O pino **ECHO** detecta o retorno.  
4. **Cálculo** – O tempo entre o envio e o recebimento é usado para calcular a distância:

<img src="https://latex.codecogs.com/svg.image?&space;Distancia(cm)=\frac{Tempo\;(s)\times&space;Velocidade\;do\;som\;(340\;m/s)}{2}" title=" Distancia(cm)=\frac{Tempo\;(s)\times Velocidade\;do\;som\;(340\;m/s)}{2}" />

O divisor por 2 é necessário porque o som percorre o caminho **de ida e volta**.

---

## Especificações rápidas

- **Tensão de alimentação:** 5 V  
- **Corrente típica:** ~15 mA  
- **Alcance:** 2 cm – 4 m  
- **Precisão:** ±3 mm (condições ideais)  
- **Ângulo efetivo:** ~15°  
- **Pinos:** VCC, TRIG, ECHO, GND  

> ⚠️ **Importante (3,3 V):**  
> Se usar ESP8266/ESP32 (3,3 V), proteja o pino **ECHO** com um divisor resistivo (ex.: 1,8 kΩ em série com 3,3 kΩ → ~3,3 V).

---

## Pinagem

| Pino | Função                        |
|------|-------------------------------|
| VCC  | +5 V                          |
| TRIG | Disparo do pulso ultrassônico |
| ECHO | Retorno (largura do pulso)    |
| GND  | Terra (0 V)                   |

---

## Ligações (Arduino UNO)

- **VCC** → 5V  
- **GND** → GND  
- **TRIG** → D9 (exemplo)  
- **ECHO** → D10 (exemplo)  

> **Dica:** mantenha cabos curtos e firmes.  
> Evite apontar o sensor para superfícies macias (absorvem som) ou muito inclinadas (refletem mal).

---

## Programação Bloqueante vs Não Bloqueante

### Programação **Bloqueante**
- Usa a função `pulseIn()` para medir o tempo no **ECHO**.  
- Enquanto espera o retorno, o microcontrolador **fica parado**.  
- Simples e didática, ótima para começar.  

```cpp
long duracao = pulseIn(ECHO, HIGH);
float distancia = (duracao * 0.0343) / 2;
```

**Desvantagem:** atrasa o robô se ele precisar controlar motores, atualizar um display ou ler outros sensores ao mesmo tempo.

---

### Programação **Não Bloqueante**
Existem duas formas principais:

1. **Polling com `micros()`** – o programa acompanha o pino ECHO dentro do `loop()`.  
   - Vantagem: não trava, permite rodar outras tarefas.  
   - Desvantagem: se o `loop()` estiver muito pesado, pode perder a leitura.  

2. **Com Interrupções** – usa `attachInterrupt` para capturar automaticamente as bordas do ECHO.  
   - Vantagem: mais robusto, não perde pulsos mesmo em código extenso.  
   - Desvantagem: código mais avançado.

---

## Exemplos de códigos

- **Exemplo 1 – Bloqueante (simples com `pulseIn`)**  
  Didático, fácil de aplicar em sala de aula e testes de bancada.  

- **Exemplo 2 – Não Bloqueante (polling com `micros`)**  
  Mais sofisticado, não trava o programa, mas depende de um loop rápido.  

- **Exemplo 3 – Não Bloqueante com Interrupções**  
  Captura o pulso via hardware, garantindo medições confiáveis mesmo em sistemas complexos, com muitas linhas de código.  

---

## Resumo

- **Bloqueante:** simples, ótimo para aprender e começar.  
- **Não bloqueante (polling):** evita travamentos, mas pode falhar se o código estiver muito carregado.  
- **Não bloqueante (interrupções):** mais robusto, indicado para projetos em tempo real e robôs móveis.  

---

## Bibliotecas Populares

Além do código manual apresentado aqui, existem bibliotecas mantidas pela comunidade que facilitam o uso do sensor HC-SR04:

- **NewPing**  
  - Repositório oficial: [github.com/livetronic/Arduino-NewPing](https://github.com/livetronic/Arduino-NewPing)  
  - Também disponível diretamente no **Arduino IDE**, pelo **Library Manager** (procure por **NewPing**).  
  - Indicada para projetos de maior desempenho e múltiplos sensores.

- **Ultrasonic**  
  - Repositório oficial: [github.com/ErickSimoes/Ultrasonic](https://github.com/ErickSimoes/Ultrasonic)  
  - Também disponível no **Arduino IDE**, pelo **Library Manager** (procure por **Ultrasonic**).  
  - Indicada para projetos educacionais e iniciantes.  

> 💡 **Dica:** Para instalar via IDE, vá em:  
> **Sketch → Include Library → Manage Libraries…**  
> Pesquise o nome da biblioteca, clique em **Install** e pronto.


