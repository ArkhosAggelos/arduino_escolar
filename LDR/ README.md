# SENSOR DE LUZ LDR


## O que é um Sensor LDR?

O **LDR** (Light Dependent Resistor) é um sensor que detecta a intensidade da luz. Em português, é chamado de **resistor dependente de luz** ou **fotocélula**.

### Como funciona?

O LDR é um componente eletrônico cuja resistência elétrica muda conforme a quantidade de luz que incide sobre ele:

- **Ambiente claro:** a resistência do LDR diminui.
- **Ambiente escuro:** a resistência do LDR aumenta.

Isso significa que ele permite mais ou menos passagem de corrente elétrica de acordo com a luz do ambiente.

### Para que serve?

O sensor LDR é usado em projetos que precisam detectar se está claro ou escuro, como:

- Lâmpadas automáticas que acendem à noite
- Sistemas de alarme
- Robôs seguidores de linha
- Medidores de luz

### Exemplo prático com Arduino

No Arduino, conectamos o LDR em um dos pinos analógicos. O Arduino lê um valor (de 0 a 1023) que representa a quantidade de luz no ambiente. Quanto mais luz, maior o valor lido.

```
int valorLuz = analogRead(A0); // Lê o valor do sensor LDR
```

---

## Informações Técnicas sobre o LDR

- **Princípio de funcionamento:** O LDR é feito de um material semicondutor (geralmente sulfeto de cádmio, CdS). Quando a luz incide sobre ele, elétrons ganham energia e aumentam a condutividade do material, diminuindo a resistência.
- **Faixa de resistência:** Pode variar de alguns poucos centenas de ohms (Ω) em ambientes muito claros até vários megaohms (MΩ) no escuro total.
- **Tempo de resposta:** Os LDRs não respondem instantaneamente à mudança de luz. O tempo de resposta pode variar de algumas dezenas a centenas de milissegundos, dependendo do modelo.
- **Tensão máxima:** Normalmente suportam tensões baixas (geralmente até 150V, mas em projetos com Arduino, usam-se tensões de 3,3V ou 5V).
- **Temperatura de operação:** Normalmente operam entre -30ºC e +70ºC.

### Ligação típica de um LDR com Arduino

Normalmente, o LDR é ligado em um divisor de tensão junto com um resistor fixo. O ponto entre eles é conectado ao pino analógico do Arduino.

**Exemplo de ligação:**
```
(5V) --- [LDR] ---+--- [Resistor] --- (GND)
                  |
             Pino Analógico (A0)
```
- O valor do resistor fixo é escolhido conforme a sensibilidade desejada, geralmente entre 10kΩ e 100kΩ.

### Curiosidades e Limitações

- O LDR é sensível principalmente à luz visível, mas não detecta infravermelho.
- Não é recomendado para medições precisas de intensidade luminosa, pois a resposta não é linear e varia entre modelos.
- Para aplicações mais precisas, usa-se fotodiodos ou fototransistores.

---


