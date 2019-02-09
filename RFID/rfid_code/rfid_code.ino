#include <SPI.h>
#include <MFRC522.h>

// --- Mapeamento de Hardware ---
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Cria instância com MFRC522

// --- Configurações Iniciais ---
void setup() {
  Serial.begin(9600);   // Inicia comunicação Serial em 9600 baud rate
  SPI.begin();          // Inicia comunicação SPI bus
  mfrc522.PCD_Init();   // Inicia MFRC522
  
  Serial.println("Aproxime o seu cartao do leitor");
  Serial.println();
} //end setup


void loop() {
  // Verifica novos cartões
  if (mfrc522.PICC_IsNewCardPresent()) {
    // Verifica a leitura dos cartões
    if (mfrc522.PICC_ReadCardSerial()) {
      // Mostra UID na serial
      String id= "";
      for (byte i = 0; i < mfrc522.uid.size; i++) {
         id += String(mfrc522.uid.uidByte[i], HEX);
      }
            
      id.toUpperCase();
      Serial.print("Mensagem : ");
      Serial.println("UID da tag :"+id);

      // Registro dos identificadores
      if (id == "B5E71577") {
        Serial.println("Chaveiro identificado\n");
        delay(1000);
      }
     
      if (id == "52A8A63") {
        Serial.println("Cartao identificado\n");
        delay(1000);
      }
    
      if(id == "B9D975DA"){
          Serial.println("Passe Facil identificado\n");
          delay(1000);
      }
    }
  }  
}
 
 
