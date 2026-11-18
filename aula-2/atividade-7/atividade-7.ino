const int potenciometro = A0;
const int botao = 2;
const int led = 3;

enum Estado {
  CONFIGURANDO,
  CONTANDO,
  FINALIZADO
};

Estado estadoAtual = CONFIGURANDO;

int tempoSelecionado = 1;

unsigned long tempoInicial = 0;
unsigned long ultimoTempo = 0;
unsigned long ultimoDebounce = 0;

bool leituraAnterior = HIGH;
bool estadoBotao = HIGH;

int lerPotenciometro() {
  int leitura = analogRead(potenciometro);
  return map(leitura, 0, 1023, 1, 60);
}

void iniciarContagem() {
  tempoInicial = millis();
  ultimoTempo = 0;
  estadoAtual = CONTANDO;
  digitalWrite(led, LOW);

  Serial.println("Contagem iniciada!");
}

void verificarBotao() {
  bool leitura = digitalRead(botao);

  if (leitura != leituraAnterior) {
    ultimoDebounce = millis();
  }

  if (millis() - ultimoDebounce > 50) {
    if (leitura != estadoBotao) {
      estadoBotao = leitura;

      if (estadoBotao == LOW) {
        if (estadoAtual == CONFIGURANDO) {
          iniciarContagem();
        } 
        else if (estadoAtual == FINALIZADO) {
          estadoAtual = CONFIGURANDO;
          digitalWrite(led, LOW);
          Serial.println("Configure um novo tempo.");
        }
      }
    }
  }

  leituraAnterior = leitura;
}

void mostrarConfiguracao() {
  static unsigned long ultimaExibicao = 0;

  if (millis() - ultimaExibicao >= 250) {
    ultimaExibicao = millis();

    Serial.print("Tempo selecionado: ");
    Serial.print(tempoSelecionado);
    Serial.println(" segundos");
  }
}

void atualizarContagem() {
  unsigned long decorrido = (millis() - tempoInicial) / 1000;

  if (decorrido != ultimoTempo) {
    ultimoTempo = decorrido;

    int restante = tempoSelecionado - decorrido;

    if (restante > 0) {
      Serial.print("Tempo restante: ");
      Serial.print(restante);
      Serial.println(" segundos");
    }
  }

  if (millis() - tempoInicial >= (unsigned long)tempoSelecionado * 1000) {
    estadoAtual = FINALIZADO;
    digitalWrite(led, HIGH);
    Serial.println("TEMPO FINALIZADO!");
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);

  digitalWrite(led, LOW);
}

void loop() {
  verificarBotao();

  if (estadoAtual == CONFIGURANDO) {
    tempoSelecionado = lerPotenciometro();
    mostrarConfiguracao();
  }

  else if (estadoAtual == CONTANDO) {
    atualizarContagem();
  }
}
