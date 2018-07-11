#include "pitches.h"
 
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
int duration = 500;
int tempo_quinta_parte = 350;
int tempo_sexta_parte = 300;

void setup() {
 
}
 
void loop() {  

  // Primeira parte
  tone(8,melody[0],duration);
  delay(duration);
  tone(8,melody[1],duration);
  delay(duration);
  tone(8,melody[2],duration);
  delay(duration);
  tone(8,melody[3],duration);
  delay(duration);
  tone(8,melody[3],duration);
  delay(duration);
  tone(8,melody[3],duration);
  delay(duration*2);
  
  //Segunda parte
  tone(8,melody[0],duration);
  delay(duration);
  tone(8,melody[1],duration);
  delay(duration);
  tone(8,melody[0],duration);
  delay(duration);
  tone(8,melody[1],duration);
  delay(duration);
  tone(8,melody[1],duration);
  delay(duration);
  tone(8,melody[1],duration);
  delay(duration*2);
    
  //Terceira parte
  tone(8,melody[0],duration);
  delay(duration);
  tone(8,melody[4],duration);
  delay(duration);
  tone(8,melody[3],duration);
  delay(duration);
  tone(8,melody[2],duration);
  delay(duration);
  tone(8,melody[2],duration);
  delay(duration);
  tone(8,melody[2],duration);
  delay(duration*2);
  
  // Quarta parte
  tone(8,melody[0],duration);
  delay(duration);
  tone(8,melody[1],duration);
  delay(duration);
  tone(8,melody[2],duration);
  delay(duration);
  tone(8,melody[3],duration);
  delay(duration);
  tone(8,melody[3],duration);
  delay(duration);
  tone(8,melody[3],duration);
  delay(duration*2);
  
  //Quinta parte
  int i;
  for(i=0;i<2;i++){
    if(i == 1){
      delay(duration);  
    }
    tone(8,melody[0],duration);
    delay(tempo_quinta_parte);
    tone(8,melody[1],duration);
    delay(tempo_quinta_parte);
    tone(8,melody[2],duration);
    delay(tempo_quinta_parte);
    tone(8,melody[3],duration);
    delay(tempo_quinta_parte);
    tone(8,melody[1],duration);
    delay(tempo_quinta_parte);
    tone(8,melody[2],duration);
    delay(tempo_quinta_parte);
    tone(8,melody[3],duration);
    delay(tempo_quinta_parte);
    tone(8,melody[4],duration);
    delay(tempo_quinta_parte);
    tone(8,melody[2],duration);
    delay(tempo_quinta_parte);
    tone(8,melody[3],duration);
    delay(tempo_quinta_parte);
    tone(8,melody[4],duration);
    delay(tempo_quinta_parte);
    tone(8,melody[5],duration);
    delay(tempo_quinta_parte);
    tone(8,melody[3],duration);
    delay(tempo_quinta_parte);
    if(i == 0){
      tone(8,melody[0],duration);
      delay(tempo_quinta_parte);
    }
  }
  delay(600);

  //Sexta parte
  tone(8,melody[0],duration);
  delay(tempo_sexta_parte);
  tone(8,melody[6],duration);
  delay(tempo_sexta_parte);
  tone(8,melody[7],duration);
  delay(tempo_sexta_parte);

  
  delay(2000);// tempo para restart
}

