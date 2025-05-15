#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>  // Inclui a biblioteca DHT

#define col 16
#define lin 2
#define ende 0x27

LiquidCrystal_I2C lcd(ende, col, lin);

// =============== DHT11 ===============
#define DHTPIN 2          // Pino conectado ao DHT11
#define DHTTYPE DHT11     // Tipo do sensor
DHT dht(DHTPIN, DHTTYPE); // Instancia o sensor

float tempC = 0;
int UmidadePor = 0;

// ====================================

int ledVerde = 13;
int ledAmarelo = 12;
int ledVermelho = 11;
int buzzer = 8;
int ldrPIN = A0;

// Variáveis para média
float somaT = 0;
int mediaT = 0;
float somaU = 0;
int mediaU = 0;
unsigned long tempoAnterior = 0;
const unsigned long intervalo = 8000;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);

  dht.begin(); // Inicializa o sensor DHT
}

void loop() {
  // ================= Leitura do DHT11 =================
  tempC = dht.readTemperature();       // Lê temperatura em Celsius
  UmidadePor = dht.readHumidity();     // Lê umidade relativa

  // Verifica se a leitura falhou
  if (isnan(tempC) || isnan(UmidadePor)) {
    Serial.println("Falha ao ler do DHT11!");
    return;
  }

  int valorLuz = analogRead(ldrPIN);
  valorLuz = map(valorLuz, 0, 1023, 0, 100);
  Serial.print("Luz: ");
  Serial.println(valorLuz);

  if (valorLuz > 66) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ambiente muito");
    lcd.setCursor(0, 1);
    lcd.print("claro");

    unsigned long startTime = millis();
    while (millis() - startTime < 3000) {
      digitalWrite(buzzer, HIGH);
    }
    digitalWrite(buzzer, LOW);
    delay(900);
  } else if (valorLuz > 33) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ambiente a meia");
    lcd.setCursor(0, 1);
    lcd.print("luz");
    delay(500);
  } else {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("luminozidade ok");
    delay(500);
  }

  // Temperatura
  if (tempC >= 15) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperatura alta");
    lcd.setCursor(0, 1);
    lcd.print("temp:");
    lcd.setCursor(11, 1);
    lcd.print(tempC);
    delay(500);
  } else if (tempC > 10) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperatura ok");
    lcd.setCursor(0, 1);
    lcd.print("temp:");
    lcd.setCursor(11, 1);
    lcd.print(tempC);
    delay(500);
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperatura baixa");
    lcd.setCursor(0, 1);
    lcd.print("temp:");
    lcd.setCursor(11, 1);
    lcd.print(tempC);
    delay(500);
  }

  // Umidade
  if (UmidadePor > 70) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Umidade Alta");
    lcd.setCursor(0, 1);
    lcd.print("Umid:");
    lcd.setCursor(12, 1);
    lcd.print(UmidadePor);
    lcd.print("%");

    unsigned long startTime = millis();
    while (millis() - startTime < 3000) {
      digitalWrite(buzzer, HIGH);
    }
    digitalWrite(buzzer, LOW);
    delay(500);
  } else if (UmidadePor > 50) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Umidade ok");
    lcd.setCursor(0, 1);
    lcd.print("Umid:");
    lcd.setCursor(12, 1);
    lcd.print(UmidadePor);
    lcd.print("%");
    delay(500);
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Umidade baixa");
    lcd.setCursor(0, 1);
    lcd.print("Umid:");
    lcd.setCursor(11, 1);
    lcd.print(UmidadePor);
    lcd.print("%");
    delay(500);
  }

  // Acumula valores para média
  somaT += tempC;
  mediaT++;
  somaU += UmidadePor;
  mediaU++;

  // Após 8 segundos, mostra a média
  if (millis() - tempoAnterior >= intervalo) {
    tempoAnterior = millis();

    if (mediaT > 0 && mediaU > 0) {
      float mediaTemp = somaT / (float)mediaT;
      float mediaUmid = somaU / (float)mediaU;

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Media Temp:");
      lcd.setCursor(12, 0);
      lcd.print(mediaTemp, 1);

      lcd.setCursor(0, 1);
      lcd.print("Media Umid:");
      lcd.setCursor(13, 1);
      lcd.print(mediaUmid, 1);
      lcd.print("%");

      delay(3000);

      somaT = 0;
      mediaT = 0;
      somaU = 0;
      mediaU = 0;
    }
  }

  delay(100); // Pequeno delay
}
