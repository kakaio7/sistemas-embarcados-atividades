# Atividade 2 — Sistema de alarme

## Plataforma e link

- **Plataforma:** Tinkercad
- **Link:** https://www.tinkercad.com/things/lh7jG5iNBU5/editel?returnTo=%2Fclassrooms%2F7OjAnbHLZRm%2Factivities%2F4iyOzX8sN5v%3Fview%3Dwork%26type%3Dall

## Imagem do protótipo

<img width="529" height="319" alt="image" src="https://github.com/user-attachments/assets/33f21c63-fc34-47ef-9592-e6805bb90eb9" />

## Componentes utilizados

- Arduino Uno
- Protoboard
- 1 LED vermelho
- 1 resistor de 220 Ω
- 2 botões
- 1 buzzer
- Jumpers

## Como funciona

O sistema possui três estados: DESATIVADO, ATIVADO e ALERTA.

Ao iniciar, o sistema permanece no estado DESATIVADO, com o LED apagado e o buzzer desligado.

Ao pressionar o primeiro botão, o sistema passa para o estado ATIVADO, acendendo o LED. Ao pressionar o segundo botão, que representa uma detecção, o sistema muda para ALERTA, mantendo o LED aceso e acionando o buzzer com bipes repetidos.

Ao pressionar novamente o primeiro botão, o sistema retorna ao estado DESATIVADO, desligando o LED e o buzzer.

Todas as mudanças de estado são informadas no Monitor Serial.

## Testes realizados

| Teste | Resultado esperado | Resultado observado |
|---|---|---|
| Iniciar o sistema | Estado DESATIVADO | Aprovado |
| Pressionar botão de ativação | LED aceso e estado ATIVADO | Aprovado |
| Pressionar botão de detecção | Estado ALERTA e buzzer tocando | Aprovado |
| Verificar o som do buzzer | Emitir bipes repetidos no ALERTA | Aprovado |
| Pressionar botão de ativação novamente | Desligar LED e buzzer | Aprovado |
| Monitor Serial | Informar cada transição | Aprovado |
