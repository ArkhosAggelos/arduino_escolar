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

- Lampadas automáticas que acendem à noite
- Sistemas de alarme
- Robôs seguidores de linha
- Medidores de luz

### Exemplo prático com Arduino

No Arduino, conectamos o LDR em um dos pinos analógicos. O Arduino lê um valor (de 0 a 1023) que representa a quantidade de luz no ambiente. Quanto mais luz, maior o valor lido.

```
int valorLuz = analogRead(A0); // Lê o valor do sensor LDR
```

---



