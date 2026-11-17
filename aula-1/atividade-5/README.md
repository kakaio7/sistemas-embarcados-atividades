# Atividade 5 — Controle de acesso

## Plataforma e link

- **Plataforma:** Tinkercad
- **Link:** https://www.tinkercad.com/things/bARKw7MEeiN-kaua-5/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fclassrooms%2F7OjAnbHLZRm%2Factivities%2F4iyOzX8sN5v%3Fview%3Dwork%26type%3Dall

## Imagem do protótipo

<img width="681" height="473" alt="image" src="https://github.com/user-attachments/assets/597bede5-a103-4d72-a011-f63b781c2470" />

## Componentes utilizados

- Arduino Uno
- Display LCD I2C 16x2
- Protoboard
- 1 botão
- 1 LED verde
- 1 LED vermelho
- 2 resistores de 220 Ω
- Jumpers

## Como funciona

O projeto consiste em um sistema de controle de acesso desenvolvido com Arduino Uno, display LCD I2C, um botão e dois LEDs.

O sistema possui três estados:

- **BLOQUEADO:** estado inicial do sistema. O LCD exibe "ACESSO BLOQUEADO" e o LED vermelho permanece aceso.
- **LIBERADO:** ao pressionar o botão, o acesso é liberado por 5 segundos. O LCD exibe "ACESSO LIBERADO" e o LED verde acende.
- **ENCERRANDO:** após os 5 segundos de liberação, o sistema entra no estado de encerramento. O LCD exibe "ENCERRANDO" e os LEDs permanecem apagados.

Após 1 segundo no estado ENCERRANDO, o sistema retorna automaticamente ao estado BLOQUEADO.

As mudanças de estado e a temporização são controladas utilizando a função `millis()`, sem interromper o funcionamento do Arduino.

## Testes realizados

| Nº | Teste | Resultado esperado | Resultado observado |
|---|---|---|---|
| 1 | Iniciar o sistema | Exibir BLOQUEADO no LCD e acender o LED vermelho | Aprovado |
| 2 | Pressionar o botão | Liberar o acesso e acender o LED verde | Aprovado |
| 3 | Aguardar 5 segundos | Encerrar o acesso automaticamente | Aprovado |
| 4 | Entrar no estado ENCERRANDO | Exibir ENCERRANDO no LCD e apagar os LEDs | Aprovado |
| 5 | Aguardar mais 1 segundo | Retornar ao estado BLOQUEADO | Aprovado |
| 6 | Pressionar o botão novamente | Iniciar um novo ciclo de liberação | Aprovado |
