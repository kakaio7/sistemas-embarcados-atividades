#include <Servo.h>

const int botao = 2;
const int buzzer = 3;
const int pinoServo = 9;

Servo servo;

enum Estado {
  AGUARDANDO,
  AVISANDO,
  ABRINDO,
  FECHANDO
};

Estado estadoAtual = AGUARDANDO;

void mudarEstado(Estado novoEstado);

unsigned long tempoAnterior = 0;
unsigned long ultimoDebounce = 0;

bool leituraAnterior = HIGH;
bool estadoBotao = HIGH;

const unsigned long intervaloAviso = 2000;
const unsigned long intervaloServo = 1500;

void mostrarEstado() {
  switch (estadoAtual) {
    case AGUARDANDO:
      Serial.println("Estado: AGUARDANDO");
      break;

    case AVISANDO:
      Serial.println("Estado: AVISANDO");
      break;

    case ABRINDO:
      Serial.println("Estado: ABRINDO");
      break;

    case FECHANDO:
      Serial.println("Estado: FECHANDO");
      break;
  }
}

void mudarEstado(Estado novoEstado) {
  estadoAtual = novoEstado;
  tempoAnterior = millis();
  mostrarEstado();
}

void avisoSonoro() {
  tone(buzzer, 1000);
}

void abrirServo() {
  servo.write(90);
}

void fecharServo() {
  servo.write(0);
}

void verificarBotao() {
  bool leitura = digitalRead(botao);

  if (leitura != leituraAnterior) {
    ultimoDebounce = millis();
  }

  if (millis() - ultimoDebounce > 50) {
    if (leitura != estadoBotao) {
      estadoBotao = leitura;

      if (estadoBotao == LOW && estadoAtual == AGUARDANDO) {
        mudarEstado(AVISANDO);
        avisoSonoro();
      }
    }
  }

  leituraAnterior = leitura;
}

void executarCiclo() {
  unsigned long tempoAtual = millis();

  switch (estadoAtual) {

    case AGUARDANDO:
      break;

    case AVISANDO:
      if (tempoAtual - tempoAnterior >= intervaloAviso) {
        noTone(buzzer);
        mudarEstado(ABRINDO);
        abrirServo();
      }
      break;

    case ABRINDO:
      if (tempoAtual - tempoAnterior >= intervaloServo) {
        mudarEstado(FECHANDO);
        fecharServo();
      }
      break;

    case FECHANDO:
      if (tempoAtual - tempoAnterior >= intervaloServo) {
        mudarEstado(AGUARDANDO);
        Serial.println("Ciclo concluido!");
      }
      break;
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(botao, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);

  servo.attach(pinoServo);
  servo.write(0);

  mostrarEstado();
}

void loop() {
  verificarBotao();
  executarCiclo();
}
