#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

enum Estado {
  BLOQUEADO,
  LIBERADO,
  ENCERRANDO
};

Estado estadoAtual = BLOQUEADO;

const int botao = 2;
const int ledVerde = 8;
const int ledVermelho = 9;

unsigned long tempoEstado = 0;

const unsigned long tempoLiberado = 5000;
const unsigned long tempoEncerrando = 1000;

int leituraAnterior = HIGH;

void atualizarEstado() {
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, LOW);

  lcd.clear();

  switch (estadoAtual) {

    case BLOQUEADO:
      digitalWrite(ledVermelho, HIGH);
      lcd.setCursor(0, 0);
      lcd.print("ACESSO BLOQUEADO");
      lcd.setCursor(0, 1);
      lcd.print("Pressione botao");
      Serial.println("BLOQUEADO");
      break;

    case LIBERADO:
      digitalWrite(ledVerde, HIGH);
      lcd.setCursor(0, 0);
      lcd.print("ACESSO LIBERADO");
      lcd.setCursor(0, 1);
      lcd.print("Bem-vindo!");
      Serial.println("LIBERADO");
      break;

    case ENCERRANDO:
      lcd.setCursor(0, 0);
      lcd.print("ENCERRANDO");
      lcd.setCursor(0, 1);
      lcd.print("Aguarde...");
      Serial.println("ENCERRANDO");
      break;
  }
}

void setup() {
  pinMode(botao, INPUT_PULLUP);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  Serial.begin(9600);

  Wire.begin();
  lcd.init();
  lcd.backlight();

  atualizarEstado();
}

void loop() {
  int leitura = digitalRead(botao);

  if (leitura == LOW && leituraAnterior == HIGH) {
    if (estadoAtual == BLOQUEADO) {
      estadoAtual = LIBERADO;
      tempoEstado = millis();
      atualizarEstado();
    }
  }

  leituraAnterior = leitura;

  if (estadoAtual == LIBERADO) {
    if (millis() - tempoEstado >= tempoLiberado) {
      estadoAtual = ENCERRANDO;
      tempoEstado = millis();
      atualizarEstado();
    }
  }

  if (estadoAtual == ENCERRANDO) {
    if (millis() - tempoEstado >= tempoEncerrando) {
      estadoAtual = BLOQUEADO;
      atualizarEstado();
    }
  }
}
