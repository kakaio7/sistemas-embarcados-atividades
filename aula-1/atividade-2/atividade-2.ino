const int led = 8;
const int botaoAtivar = 2;
const int botaoDeteccao = 3;
const int buzzer = 10;

enum Estado {
  DESATIVADO,
  ATIVADO,
  ALERTA
};

Estado estadoAtual = DESATIVADO;

bool anteriorAtivar = HIGH;
bool anteriorDeteccao = HIGH;

unsigned long tempoAnterior = 0;
bool somLigado = false;

void atualizarSistema() {
  digitalWrite(led, estadoAtual != DESATIVADO);

  if (estadoAtual != ALERTA) {
    noTone(buzzer);
    somLigado = false;
  }

  Serial.print("Estado atual: ");

  switch (estadoAtual) {
    case DESATIVADO:
      Serial.println("DESATIVADO");
      break;

    case ATIVADO:
      Serial.println("ATIVADO");
      break;

    case ALERTA:
      Serial.println("ALERTA");
      tempoAnterior = millis();
      break;
  }
}

void setup() {
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(botaoAtivar, INPUT_PULLUP);
  pinMode(botaoDeteccao, INPUT_PULLUP);

  Serial.begin(9600);

  atualizarSistema();
}

void loop() {
  bool leituraAtivar = digitalRead(botaoAtivar);
  bool leituraDeteccao = digitalRead(botaoDeteccao);

  if (anteriorAtivar == HIGH && leituraAtivar == LOW) {
    if (estadoAtual == DESATIVADO) {
      estadoAtual = ATIVADO;
    } else {
      estadoAtual = DESATIVADO;
    }

    atualizarSistema();
    delay(30);
  }

  if (anteriorDeteccao == HIGH && leituraDeteccao == LOW) {
    if (estadoAtual == ATIVADO) {
      estadoAtual = ALERTA;
      atualizarSistema();
    }

    delay(30);
  }

  anteriorAtivar = leituraAtivar;
  anteriorDeteccao = leituraDeteccao;

  if (estadoAtual == ALERTA) {
    if (millis() - tempoAnterior >= 200) {
      tempoAnterior = millis();
      somLigado = !somLigado;

      if (somLigado) {
        tone(buzzer, 1000);
      } else {
        noTone(buzzer);
      }
    }
  }
}
