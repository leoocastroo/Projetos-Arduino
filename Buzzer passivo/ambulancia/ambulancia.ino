#include "pitches.h"

int duracao = 800;
int tempo_entre_notas = 500;

int led_amarelo = 4;
int led_vermelho = 3;
int buzzer = 8;

void setup() {
  pinMode(led_amarelo,OUTPUT);
  pinMode(led_vermelho,OUTPUT);
}

void loop() {
  tone(buzzer,NOTE_C5,duracao);
  digitalWrite(led_amarelo,HIGH);
  delay(tempo_entre_notas);
  digitalWrite(led_amarelo,LOW);
  
  digitalWrite(led_vermelho,HIGH);
  tone(buzzer,NOTE_F5,duracao);
  delay(tempo_entre_notas);
  digitalWrite(led_vermelho,LOW);
}
