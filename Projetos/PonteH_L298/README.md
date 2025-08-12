# 🚗 Projeto: Ponte H L298N — Controle de Motores DC

Este diretório contém exemplos didáticos para controle de motores DC usando o CI **L298N** ou **TC1508** ou ainda **MX1508** em duas versões de módulo:

1. **Módulo Padrão - L298N** — Possui pinos **ENA/ENB** para controle de velocidade via PWM.  
2. **Módulo Mini - TC1508 ou MX1508** — Não possui pinos ENA/ENB dedicados; o PWM é aplicado diretamente nos pinos IN.

No módulo padrão com L298N e dissipador de calor, é possível fornecer uma corrente um pouco maior aos motores.
Esse modelo possui pinos ENA e ENB para controle de velocidade via PWM, permitindo usar apenas duas portas PWM do Arduino (uma para cada motor).
Quando os pinos ENA e ENB estão com jumpers, eles permanecem permanentemente habilitados, e o controle de velocidade deve ser feito diretamente nas entradas IN1...IN4.
Nesse caso, o funcionamento é semelhante ao do módulo mini, que normalmente usa os CIs TC1508 ou MX1508, não possuindo pinos ENABLE dedicados e 
exigindo quatro portas PWM do Arduino — uma para cada entrada da ponte H.

---

## 📜 Objetivo
Demonstrar de forma clara e prática como:
- Controlar o sentido de rotação de dois motores DC.
- Ajustar a velocidade com PWM.
- Adaptar o código para diferentes versões do módulo L298N.

Estes códigos foram escritos para fins **educacionais** e priorizam clareza em vez de otimização.

---

## 🛠 Materiais
- Arduino UNO (ou compatível)
- Módulo L298N (padrão) ou Módulo MINI com TC1508 ou MX1508
- 2 motores DC
- Fonte para motores (6–12V)
- Jumpers

---

## 📎 Observação
- Sempre interligue o **GND do Arduino** ao **GND da Ponte H**.
- Não alimente motores diretamente pelo 5V do Arduino.
- Verifique a temperatura do módulo em uso contínuo.

---

## 🧑‍💻 Autor
**Professor Claudio Roberto da Silva**


