
const int sensor = A0;

const int ledVerde = 2;
const int ledAmarelo = 3;
const int ledVermelho = 4;
const int buzzer = 5;

enum Estado {
  NORMAL,
  ATENCAO,
  ALERTA
};

Estado estadoAtual = NORMAL;

unsigned long tempoAnterior = 0;
const unsigned long intervalo = 1000;

float temperatura = 0;

int lerSensor() {
  return analogRead(sensor);
}

float converterTemperatura(int leitura) {
  float tensao = leitura * (5.0 / 1023.0);
  return (tensao - 0.5) * 100.0;
}

void atualizarEstado() {
  if (temperatura < 30) {
    estadoAtual = NORMAL;
  } 
  else if (temperatura < 40) {
    estadoAtual = ATENCAO;
  } 
  else {
    estadoAtual = ALERTA;
  }
}

void atualizarLEDs() {
  digitalWrite(ledVerde, estadoAtual == NORMAL);
  digitalWrite(ledAmarelo, estadoAtual == ATENCAO);
  digitalWrite(ledVermelho, estadoAtual == ALERTA);
}

void atualizarBuzzer() {
  if (estadoAtual == ALERTA) {
    tone(buzzer, 1000);
  } else {
    noTone(buzzer);
  }
}

void mostrarSerial() {
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" °C | Estado: ");

  if (estadoAtual == NORMAL) {
    Serial.println("NORMAL");
  } 
  else if (estadoAtual == ATENCAO) {
    Serial.println("ATENCAO");
  } 
  else {
    Serial.println("ALERTA");
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual;

    int leitura = lerSensor();
    temperatura = converterTemperatura(leitura);

    atualizarEstado();
    atualizarLEDs();
    atualizarBuzzer();
    mostrarSerial();
  }
}
