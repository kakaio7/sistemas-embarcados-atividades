# Atividade 6 — Alerta de temperatura

## Plataforma e link

- **Plataforma:** Tinkercad
- **Link:** https://www.tinkercad.com/things/b0xFKsavamv/editel?returnTo=%2Fclassrooms%2F7OjAnbHLZRm%2Factivities%2F4iyOzX8sN5v%3Fview%3Dwork%26type%3Dall

## Imagem do protótipo

<img width="806" height="438" alt="image" src="https://github.com/user-attachments/assets/18ce2df1-7924-4c0f-ab4a-0bd60130bd6d" />

## Componentes utilizados

- Arduino Uno
- Protoboard
- 1 sensor de temperatura TMP36
- 1 LED verde
- 1 LED amarelo
- 1 LED vermelho
- 3 resistores de 220 Ω
- 1 buzzer
- Jumpers

## Como funciona

O sistema utiliza três estados: NORMAL, ATENCAO e ALERTA.

Ao iniciar, o sistema realiza a leitura da temperatura através do sensor TMP36. Quando a temperatura está abaixo de 30 °C, permanece no estado NORMAL, mantendo o LED verde aceso.

Quando a temperatura atinge 30 °C, o sistema muda para o estado ATENCAO, acendendo o LED amarelo.

Quando a temperatura atinge 40 °C ou mais, muda para o estado ALERTA, acendendo o LED vermelho e acionando o buzzer.

O programa utiliza funções para separar a leitura do sensor, a conversão da temperatura, a atualização dos LEDs e o controle do buzzer. A função millis() permite atualizar as informações a cada segundo sem utilizar delay().

A temperatura e o estado atual também são apresentados no Monitor Serial.

## Testes realizados

| Teste | Resultado esperado | Resultado observado |
|---|---|---|
| Iniciar o sistema com temperatura abaixo de 30 °C | LED verde aceso | Aprovado |
| Temperatura atingir 30 °C | LED amarelo aceso | Aprovado |
| Temperatura atingir 40 °C | LED vermelho e buzzer acionados | Aprovado |
| Temperatura retornar abaixo de 30 °C | LED verde aceso e buzzer desligado | Aprovado |
| Monitor Serial | Exibir temperatura e estado atual | Aprovado |
| Atualização da leitura | Atualizar a cada segundo | Aprovado |
