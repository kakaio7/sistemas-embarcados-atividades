# Atividade 3 — Cancela de estacionamento

## Plataforma e link

- **Plataforma:** Tinkercad
- **Link:** https://www.tinkercad.com/things/8WBqUlHi1J5/editel?returnTo=%2Fclassrooms%2F7OjAnbHLZRm%2Factivities%2F4iyOzX8sN5v%3Fview%3Dwork%26type%3Dall

## Imagem do protótipo

<img width="522" height="395" alt="image" src="https://github.com/user-attachments/assets/c1c76b16-bacc-4f14-a9f0-4f3f2192a946" />

## Componentes utilizados

- Arduino Uno
- Micro servo motor
- Botão
- Protoboard
- Jumpers

## Como funciona

O projeto consiste em uma cancela de estacionamento controlada por um Arduino Uno, um botão e um micro servo motor.

O sistema possui quatro estados:

- **FECHADA:** a cancela inicia abaixada, aguardando o acionamento do botão.
- **ABRINDO:** quando o botão é pressionado, o servo começa a levantar a cancela.
- **ABERTA:** a cancela permanece levantada durante 5 segundos.
- **FECHANDO:** após o tempo determinado, o servo abaixa a cancela automaticamente.

Quando a cancela termina de fechar, o sistema retorna ao estado FECHADA e fica aguardando um novo acionamento.

A temporização é realizada utilizando a função `millis()`, evitando o uso de `delay()`.

## Testes realizados

| Nº | Teste | Resultado esperado | Resultado observado |
|---|---|---|---|
| 1 | Iniciar o sistema | A cancela começa fechada | Aprovado |
| 2 | Pressionar o botão | A cancela começa a abrir | Aprovado |
| 3 | Abertura completa | O servo posiciona a cancela em 90° | Aprovado |
| 4 | Aguardar 5 segundos | A cancela permanece aberta durante o tempo determinado | Aprovado |
| 5 | Finalizar o tempo de espera | A cancela começa a fechar automaticamente | Aprovado |
| 6 | Fechamento completo | A cancela retorna à posição inicial | Aprovado |
| 7 | Pressionar novamente | Um novo ciclo de abertura é iniciado | Aprovado |
