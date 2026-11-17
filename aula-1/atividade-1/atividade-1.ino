const int ledVermelho = 8;
const int ledAmarelo = 9;
const int ledVerde = 10;
const int botao = 2;

enum Estado {
  VERMELHO,
  VERDE,
  AMARELO
};

Estado estadoAtual = VERMELHO;

bool botaoAnterior = HIGH;

void atualizarSemaforo() {
  digitalWrite(ledVermelho, estadoAtual == VERMELHO);
  digitalWrite(ledVerde, estadoAtual == VERDE);
  digitalWrite(ledAmarelo, estadoAtual == AMARELO);

  Serial.print("Estado atual: ");

  switch (estadoAtual) {
    case VERMELHO:
      Serial.println("VERMELHO");
      break;

    case VERDE:
      Serial.println("VERDE");
      break;

    case AMARELO:
      Serial.println("AMARELO");
      break;
  }
}

void avancarEstado() {
  switch (estadoAtual) {
    case VERMELHO:
      estadoAtual = VERDE;
      break;

    case VERDE:
      estadoAtual = AMARELO;
      break;

    case AMARELO:
      estadoAtual = VERMELHO;
      break;
  }

  atualizarSemaforo();
}

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  pinMode(botao, INPUT_PULLUP);

  Serial.begin(9600);

  atualizarSemaforo();
}

void loop() {
  bool leituraBotao = digitalRead(botao);

  if (botaoAnterior == HIGH && leituraBotao == LOW) {
    avancarEstado();
  }

  botaoAnterior = leituraBotao;
  delay(30);
}
