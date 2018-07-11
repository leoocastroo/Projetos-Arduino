/*
Retirado do datasheet
Table 1 Instruction set
+------------+-----+-----------------------------------------------+-----------------------------+
|            |     |                  COMMAND BYTE                 |                             |
|            |     +-----------------------------------------------+                             |
|INSTRUCTION | D/C | DB7 | DB6 | DB5 | DB4 | DB3 | DB2 | DB1 | DB0 |         DESCRIPTION         |
+------------+-----+-----------------------------------------------+-----------------------------+
|(H = 0 or 1)                                                                                    |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------------------------+
|NOP         |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |No Operation                 |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------------------------+
|Func. set   |  0  |  0  |  0  |  1  |  0  |  0  |  PD |  V  |  H  |power down control;          |
|            |     |     |     |     |     |     |     |     |     |entry mode;                  |
|            |     |     |     |     |     |     |     |     |     |extended instruction set     | 
|            |     |     |     |     |     |     |     |     |     |control (H)|                 |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------------------------+
|Write Data  |  1  |  D7 |  D6 |  D5 |  D4 |  D3 |  D2 |  D1 |  D0 |Write Data to display        |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------------------------+
|(H = 0) use basic instruction set                                                               |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------------------------+
|Reseverd    |  0  |  0  |  0  |  0  |  0  |  0  |  1  |  X  |  X  |Do not use                   |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------------------------+
|Disp Control|  0  |  0  |  0  |  0  |  0  |  1  |  D  |  0  |  E  |Sets Display Configuration   |
|            |     |     |     |     |     |     |     |     |     |DE                           |
|            |     |     |     |     |     |     |     |     |     |00 - display blank           | 
|            |     |     |     |     |     |     |     |     |     |01 - all display segment on  |
|            |     |     |     |     |     |     |     |     |     |10 - normal mode             | 
|            |     |     |     |     |     |     |     |     |     |11 - inverse video mode      |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------------------------+
|Reseverd    |  0  |  0  |  0  |  0  |  1  |  X  |  X  |  X  |  X  |Do not use                   |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------------------------+
|SetY ad. RAM|  0  |  0  |  1  |  0  |  0  |  0  |  y2 |  y1 |  y0 |sets Y-address of RAM;       |
|            |     |     |     |     |     |     |     |     |     |0 ≤ Y ≤ 5                   |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------------------------+
|SetX ad. RAM|  0  |  1  |  x6 |  x5 |  x4 |  x3 |  x2 |  x1 |  x0 |sets Y-address of RAM;       |
|            |     |     |     |     |     |     |     |     |     |0 ≤ x ≤ 83                  |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------------------------+
|(H = 1)  use extended instruction set                                                           |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------------------------+
|Reseverd    |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  1  |Do not use                   |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------------------------+
|Reseverd    |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  1  |  X  |Do not use                   |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------------------------+
|Temp Control|  0  |  0  |  0  |  0  |  0  |  0  |  1  | Tc1 | Tc0 |set Temperature Coefficient  |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------------------------+
|Reseverd    |  0  |  0  |  0  |  0  |  0  |  1  |  X  |  X  |  X  |Do not use                   |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------------------------+
|Bias System |  0  |  0  |  0  |  0  |  1  |  0  | BS2 | BS1 | BS0 |set Bias System (BSx)        |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------------------------+
|Reseverd    |  0  |  1  |VOP6 |VOP5 |VOP4 |VOP3 |VOP2 |VOP1 |VOP0 |write VOP to register        |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------------------------+
*/
#define LCD_NOKIA_DATA HIGH
#define LCD_NOKIA_CMD  LOW
 
const int pin_sclk = 3;  // pin 8 - Serial clock out (SCLK)
const int pin_din  = 4;  // pin 9 - Serial data out (DIN)
const int pin_dc   = 5; // pin 10 - Data/Command select (D/C)
const int pin_cs   = 7; // pin 11 - LCD chip select (CS/CE)
const int pin_rst  = 6; // pin 12 - LCD reset (RST)
 
void lcd_write(byte mode, byte w){
  digitalWrite(pin_dc, mode);
  digitalWrite(pin_cs, LOW);
  shiftOut(pin_din, pin_sclk, MSBFIRST, w);
  digitalWrite(pin_cs, HIGH);
}
 
void setup() {
  Serial.begin(9600);
  pinMode(pin_din, OUTPUT);
  pinMode(pin_sclk, OUTPUT);
  pinMode(pin_dc, OUTPUT);
  pinMode(pin_rst, OUTPUT);
  pinMode(pin_cs, OUTPUT);
   
  digitalWrite(pin_rst, LOW); 
  digitalWrite(pin_rst, HIGH);
   
  lcd_write(LCD_NOKIA_CMD, B00100001 );  // LCD Extended Commands.  00100001
  lcd_write(LCD_NOKIA_CMD, B10101111 );  // Set LCD Vop (Contraste) 10101111 
  lcd_write(LCD_NOKIA_CMD, B00000100 );  // Set Temp coefficent     00000100
  lcd_write(LCD_NOKIA_CMD, B00010100 );  // LCD bias mode 1:48      00010100
   
  lcd_write(LCD_NOKIA_CMD, B00100000 );  // LCD Basic Commands.     00100000
  lcd_write(LCD_NOKIA_CMD, B00001100 );  // LCD no modo normal      00001100
   
  lcd_write(LCD_NOKIA_CMD, B01000000);   // X-ADDRESS = 0
  lcd_write(LCD_NOKIA_CMD, B10000000);   // Y-ADDRESS = 0
   
  for (int i=0; i<504; i++){
    lcd_write(LCD_NOKIA_DATA, B00000000);
  }
}

void loop() {
   static boolean horizontal = true;
  for (int i=0; i<504; i++){
    lcd_write(LCD_NOKIA_DATA, B11111111);
    delay(20);
  }
   
  for (int i=0; i<504; i++){
    lcd_write(LCD_NOKIA_DATA, B00000000);
    delay(20);
  }
   
  horizontal = !horizontal;
   
  if (horizontal) {
    lcd_write(LCD_NOKIA_CMD, B00100000 );  // LCD Basic Commands.     00100000
  } else {
    lcd_write(LCD_NOKIA_CMD, B00100010 );  // LCD Basic Commands.     00100000
  }
}
