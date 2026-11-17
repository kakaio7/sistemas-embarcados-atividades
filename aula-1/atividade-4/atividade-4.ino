#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

enum Estado {
  AGUARDANDO,
  ATENDENDO,
  FINALIZADO
};

Estado estadoAtual = AGUARDANDO;

const int botaoIniciar = 2;
const int botaoFinalizar = 3;

const int ledVerde = 8;
const int ledAmarelo = 9;
const int ledVermelho = 10;

unsigned long tempoFinalizado = 0;
const unsigned long tempoEspera = 2000;

int anteriorIniciar = HIGH;
int anteriorFinalizar = HIGH;

void atualizarEstado() {
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);

  lcd.clear();

  switch (estadoAtual) {

    case AGUARDANDO:
      digitalWrite(ledVerde, HIGH);
      lcd.setCursor(0, 0);
      lcd.print("AGUARDANDO");
      lcd.setCursor(0, 1);
      lcd.print("Pressione iniciar");
      break;

    case ATENDENDO:
      digitalWrite(ledAmarelo, HIGH);
      lcd.setCursor(0, 0);
      lcd.print("ATENDENDO");
      lcd.setCursor(0, 1);
      lcd.print("Em atendimento");
      break;

    case FINALIZADO:
      digitalWrite(ledVermelho, HIGH);
      lcd.setCursor(0, 0);
      lcd.print("FINALIZADO");
      lcd.setCursor(0, 1);
      lcd.print("Atendimento OK");
      break;
  }
}

void setup() {
  pinMode(botaoIniciar, INPUT_PULLUP);
  pinMode(botaoFinalizar, INPUT_PULLUP);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  Wire.begin();

  lcd.init();
  lcd.backlight();

  atualizarEstado();
}

void loop() {
  int leituraIniciar = digitalRead(botaoIniciar);
  int leituraFinalizar = digitalRead(botaoFinalizar);

  if (leituraIniciar == LOW && anteriorIniciar == HIGH) {
    if (estadoAtual == AGUARDANDO) {
      estadoAtual = ATENDENDO;
      atualizarEstado();
    }
  }

  if (leituraFinalizar == LOW && anteriorFinalizar == HIGH) {
    if (estadoAtual == ATENDENDO) {
      estadoAtual = FINALIZADO;
      tempoFinalizado = millis();
      atualizarEstado();
    }
  }

  anteriorIniciar = leituraIniciar;
  anteriorFinalizar = leituraFinalizar;

  if (estadoAtual == FINALIZADO) {
    if (millis() - tempoFinalizado >= tempoEspera) {
      estadoAtual = AGUARDANDO;
      atualizarEstado();
    }
  }
}
