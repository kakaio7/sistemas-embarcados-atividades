#include <Servo.h>

Servo cancela;

const int botao = 2;
const int servoPin = 9;

enum Estado {
  FECHADA,
  ABRINDO,
  ABERTA,
  FECHANDO
};

Estado estadoAtual = FECHADA;

int anguloFechado = 0;
int anguloAberto = 90;

unsigned long tempoAnterior = 0;
unsigned long tempoAberta = 0;

const unsigned long intervaloMovimento = 20;
const unsigned long tempoEspera = 5000;

int anguloAtual = 0;
int leituraAnterior = HIGH;

void setup() {
  pinMode(botao, INPUT_PULLUP);

  cancela.attach(servoPin);
  cancela.write(anguloFechado);

  Serial.begin(9600);
  Serial.println("Cancela FECHADA");
}

void loop() {
  int leitura = digitalRead(botao);

  if (leitura == LOW && leituraAnterior == HIGH && estadoAtual == FECHADA) {
    estadoAtual = ABRINDO;
    Serial.println("Cancela ABRINDO");
  }

  leituraAnterior = leitura;

  switch (estadoAtual) {

    case FECHADA:
      break;

    case ABRINDO:
      if (millis() - tempoAnterior >= intervaloMovimento) {
        tempoAnterior = millis();

        anguloAtual++;
        cancela.write(anguloAtual);

        if (anguloAtual >= anguloAberto) {
          estadoAtual = ABERTA;
          tempoAberta = millis();
          Serial.println("Cancela ABERTA");
        }
      }
      break;

    case ABERTA:
      if (millis() - tempoAberta >= tempoEspera) {
        estadoAtual = FECHANDO;
        Serial.println("Cancela FECHANDO");
      }
      break;

    case FECHANDO:
      if (millis() - tempoAnterior >= intervaloMovimento) {
        tempoAnterior = millis();

        anguloAtual--;
        cancela.write(anguloAtual);

        if (anguloAtual <= anguloFechado) {
          estadoAtual = FECHADA;
          Serial.println("Cancela FECHADA");
        }
      }
      break;
  }
}
