#include"Servo.h"

Servo Motor;

//pino analógico onde o potenciômetro está conectado
int const potenciometroPin = 0;

//pino digital associado ao controle do servomotor
int const servoMotorPin = 9;

//variável usada para armazenar o valor lido no potenciômetro
int valPotenciometro;

void setup() {
  Motor.attach(servoMotorPin);
}

void loop() {
  //lendo o valor do potenciômetro (intervalo entre 0 e 1023)
  valPotenciometro = analogRead(potenciometroPin);
  
  //mapeando o valor para a escala do servo (entre 0 e 180)
  valPotenciometro = map(valPotenciometro, 0, 1023, 0, 180);
  
  //definindo o valor/posição do servomotor
  Motor.write(valPotenciometro);
  
  delay(15);
}
