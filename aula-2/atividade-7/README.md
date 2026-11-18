# Atividade 7 — Temporizador ajustável

## Plataforma e link

- **Plataforma:** Tinkercad 
- **Link:** https://www.tinkercad.com/things/gXpZ1PPkz61/editel?returnTo=%2Fclassrooms%2F7OjAnbHLZRm%2Factivities%2F4iyOzX8sN5v%3Fview%3Dwork%26type%3Dall

## Imagem do protótipo

<img width="923" height="383" alt="image" src="https://github.com/user-attachments/assets/30c53cf7-ec44-4993-8549-b69575b94ce0" />

## Componentes utilizados

- Arduino Uno
- Protoboard
- 1 potenciômetro de 10 kΩ
- 1 botão
- 1 LED
- 1 resistor de 220 Ω
- Jumpers

## Como funciona

O sistema utiliza três estados: CONFIGURANDO, CONTANDO e FINALIZADO.

No estado CONFIGURANDO, o usuário utiliza o potenciômetro para escolher o tempo do temporizador, que pode variar de 1 até 60 segundos. O tempo selecionado é apresentado no Monitor Serial.

Ao pressionar o botão, o sistema muda para o estado CONTANDO e inicia a contagem regressiva utilizando a função millis().

Quando o tempo termina, o sistema muda para o estado FINALIZADO e acende o LED para indicar que a contagem foi concluída.

O programa utiliza funções para realizar a leitura do potenciômetro, iniciar a contagem, verificar o botão e atualizar o temporizador.

Após a finalização, um novo acionamento do botão permite configurar outro tempo.

## Testes realizados

| Teste | Resultado esperado | Resultado observado |
|---|---|---|
| Iniciar o sistema | Estado CONFIGURANDO | Aprovado |
| Girar o potenciômetro | Alterar o tempo selecionado | Aprovado |
| Pressionar o botão | Iniciar a contagem | Aprovado |
| Durante a contagem | Apresentar o tempo restante no Monitor Serial | Aprovado |
| Finalizar a contagem | LED aceso | Aprovado |
| Pressionar o botão após finalizar | Retornar ao estado CONFIGURANDO | Aprovado |
