# Atividade 8 — Alimentador automático

## Plataforma e link

- **Plataforma:** Tinkercad
- **Link:** https://www.tinkercad.com/things/48bGFbA3z0p/editel?returnTo=%2Fclassrooms%2F7OjAnbHLZRm%2Factivities%2F4iyOzX8sN5v%3Fview%3Dwork%26type%3Dall

## Imagem do protótipo

<img width="506" height="372" alt="image" src="https://github.com/user-attachments/assets/10e51e77-9eb6-4c67-950f-e9231a529878" />

## Componentes utilizados

- Arduino Uno
- Protoboard
- 1 micro servo motor
- 1 botão
- 1 buzzer
- Jumpers

## Como funciona

O sistema utiliza quatro estados: AGUARDANDO, AVISANDO, ABRINDO e FECHANDO.

Ao iniciar, o sistema permanece no estado AGUARDANDO, esperando o acionamento do botão.

Quando o botão é pressionado, o sistema muda para AVISANDO e aciona o buzzer durante 2 segundos.

Em seguida, muda para ABRINDO, fazendo o servo girar para 90 graus. Após 1,5 segundo, muda para FECHANDO, fazendo o servo retornar para 0 grau.

Depois de concluir o ciclo, o sistema retorna ao estado AGUARDANDO, permitindo iniciar um novo ciclo.

O programa utiliza funções para realizar o aviso sonoro, abrir e fechar o servo e apresentar o estado atual no Monitor Serial.

A função millis() controla o tempo de cada etapa sem utilizar delay(). O sistema também impede que um novo ciclo seja iniciado enquanto o anterior estiver em execução.

## Testes realizados

| Teste | Resultado esperado | Resultado observado |
|---|---|---|
| Iniciar o sistema | Estado AGUARDANDO | Aprovado |
| Pressionar o botão | Iniciar o ciclo | Aprovado |
| Estado AVISANDO | Buzzer acionado | Aprovado |
| Estado ABRINDO | Servo girar para 90 graus | Aprovado |
| Estado FECHANDO | Servo retornar para 0 grau | Aprovado |
| Pressionar o botão durante o ciclo | Impedir um novo ciclo | Aprovado |
| Finalizar o ciclo | Retornar ao estado AGUARDANDO | Aprovado |
