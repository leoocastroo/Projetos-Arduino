#define col_1 4
#define col_2 5
#define col_3 6
#define col_4 7

#define row_1 8
#define row_2 9
#define row_3 10
#define row_4 11

int control = 0x01;

char numbers[10] = {};

void store(char number);

void setup() {
  // put your setup code here, to run once:
  pinMode(col_1, INPUT);
  pinMode(col_2, INPUT);
  pinMode(col_3, INPUT);
  pinMode(col_4, INPUT);
                                                                                                                                                                    
  pinMode(row_1, OUTPUT);
  pinMode(row_2, OUTPUT);
  pinMode(row_3, OUTPUT);
  pinMode(row_4, OUTPUT); 
  
  Serial.begin(9600);
}

void loop() {
  if(control == 0x01){
    control = 0x02;
    digitalWrite(row_1, HIGH);
    digitalWrite(row_2, LOW);
    digitalWrite(row_3, LOW);
    digitalWrite(row_4, LOW);

    if(digitalRead(col_1)) store('1');
    if(digitalRead(col_2)) store('2');
    if(digitalRead(col_3)) store('3');
    if(digitalRead(col_4)) store('A');
    
  } else if (control == 0x02) {
    control = 0x03;
    digitalWrite(row_1, LOW);
    digitalWrite(row_2, HIGH);
    digitalWrite(row_3, LOW);
    digitalWrite(row_4, LOW);

    if(digitalRead(col_1)) store('4');
    if(digitalRead(col_2)) store('5');
    if(digitalRead(col_3)) store('6');
    if(digitalRead(col_4)) store('B');  
  } else if (control == 0x03) {
    control = 0x04;
    digitalWrite(row_1, LOW);
    digitalWrite(row_2, LOW);
    digitalWrite(row_3, HIGH);
    digitalWrite(row_4, LOW);

    if(digitalRead(col_1)) store('7');
    if(digitalRead(col_2)) store('8');
    if(digitalRead(col_3)) store('9');
    if(digitalRead(col_4)) store('C');  
  } else if (control == 0x04) {
    control = 0x01;
    digitalWrite(row_1, LOW);
    digitalWrite(row_2, LOW);
    digitalWrite(row_3, LOW);
    digitalWrite(row_4, HIGH);

    if(digitalRead(col_1)) store('*');
    if(digitalRead(col_2)) store('0');
    if(digitalRead(col_3)) store('#');
    if(digitalRead(col_4)) store('D');  
  }
}

void store(char number) {
  int tam = strlen(numbers);
  numbers[tam] = number;
  for(int i=0; i< tam+1; i++){
    Serial.print(numbers[i]);  
  }
  if(tam+1 >= 5){
    memset(numbers, 0, sizeof(numbers));
  }
  
  Serial.print('\n');
  delay(350);  
}
