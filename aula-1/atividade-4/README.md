# Atividade 4 — Painel de atendimento

## Plataforma e link

- **Plataforma:** Tinkercad
- **Link:** https://www.tinkercad.com/things/7mGYJf3xE0t/editel?returnTo=%2Fclassrooms%2F7OjAnbHLZRm%2Factivities%2F4iyOzX8sN5v%3Fview%3Dwork%26type%3Dall

## Imagem do protótipo

<img width="531" height="382" alt="image" src="https://github.com/user-attachments/assets/c61a5667-730c-4dc5-8f79-acdda8cdbce8" />

## Componentes utilizados

- Arduino Uno
- Display LCD I2C 16x2
- Protoboard
- 2 botões
- 1 LED verde
- 1 LED amarelo
- 1 LED vermelho
- 3 resistores de 220 Ω
- Jumpers

## Como funciona

O projeto consiste em um painel de atendimento desenvolvido com Arduino Uno, display LCD I2C, dois botões e três LEDs.

O sistema possui três estados:

- **AGUARDANDO:** estado inicial do sistema. O LCD exibe a mensagem "AGUARDANDO" e o LED verde permanece aceso.
- **ATENDENDO:** ao pressionar o botão de iniciar, o sistema muda para o estado de atendimento. O LCD exibe "ATENDENDO" e o LED amarelo acende.
- **FINALIZADO:** ao pressionar o botão de finalizar, o sistema exibe "FINALIZADO" e acende o LED vermelho.

Após 2 segundos no estado FINALIZADO, o sistema retorna automaticamente ao estado AGUARDANDO.

A temporização é realizada utilizando a função `millis()`, permitindo controlar o tempo sem interromper o funcionamento do Arduino.

## Testes realizados

| Nº | Teste | Resultado esperado | Resultado observado |
|---|---|---|---|
| 1 | Iniciar o sistema | Exibir AGUARDANDO no LCD e acender o LED verde | Aprovado |
| 2 | Pressionar o botão iniciar | Mudar para ATENDENDO e acender o LED amarelo | Aprovado |
| 3 | Pressionar o botão finalizar | Mudar para FINALIZADO e acender o LED vermelho | Aprovado |
| 4 | Aguardar 2 segundos | Retornar ao estado AGUARDANDO | Aprovado |
| 5 | Iniciar um novo atendimento | Permitir iniciar outro ciclo de atendimento | Aprovado |
| 6 | Pressionar finalizar enquanto aguarda | Permanecer no estado AGUARDANDO | Aprovado |
