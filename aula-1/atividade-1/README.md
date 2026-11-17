# Atividade 1 — Semáforo controlado por botão

## Plataforma e link

- **Plataforma:** Tinkercad
- **Link:** https://www.tinkercad.com/things/cpY7ZR59drs-kaua/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fclassrooms%2F7OjAnbHLZRm%2Factivities%2F4iyOzX8sN5v%3Fview%3Dwork%26type%3Dall

## Imagem do protótipo

<img width="989" height="424" alt="image" src="https://github.com/user-attachments/assets/44e91676-c68a-4bf2-9e7b-323080f26bb7" />

## Componentes utilizados

- Arduino Uno
- Protoboard
- 1 LED vermelho
- 1 LED amarelo
- 1 LED verde
- 3 resistores de 220 Ω
- 1 botão
- Jumpers

## Como funciona

O sistema utiliza três estados: VERMELHO, VERDE e AMARELO.

Ao iniciar, o semáforo permanece no estado VERMELHO. Quando o botão é pressionado, o sistema avança para o estado VERDE. No próximo acionamento, muda para AMARELO e, depois, retorna ao VERMELHO.

O botão permite apenas uma mudança de estado por acionamento. O estado atual também é informado no Monitor Serial.

## Testes realizados

| Teste | Resultado esperado | Resultado observado |
|---|---|---|
| Iniciar o sistema | LED vermelho aceso | Aprovado |
| Primeiro acionamento | LED verde aceso | Aprovado |
| Segundo acionamento | LED amarelo aceso | Aprovado |
| Terceiro acionamento | LED vermelho aceso | Aprovado |
| Manter botão pressionado | Apenas uma mudança de estado | Aprovado |
| Monitor Serial | Exibir o estado atual | Aprovado |
