/*
 * Criado por Kaique, Luiz, Thiago
 * 
 *  Data 23/10/2023
 *
 */
 
#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 5
#define RST_PIN 6


MFRC522 mfrc522(SS_PIN, RST_PIN);   // Cria a instancia do MFRC522

void setup() 
{	
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, INPUT);
  Serial.begin(9600);   // Inicia uma comunicacao serial na velocidade 9600
  SPI.begin();      // Inicia SPI bus
  mfrc522.PCD_Init();   // Inicia MFRC522
}
void loop() 
{
  // Led pra saber se esta em funcionamento
	digitalWrite(8, HIGH);

  //Espera um cartao e reinicia o loop se nao tiver 
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }

  if ( ! mfrc522.PICC_ReadCardSerial() ) // verifica se foi lido algum codigo serial do cartao
  {
    return;
  }
  //Mostra UID no monitor serial
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
         
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Mensagem : ");
  content.toUpperCase();
  if (content.substring(1) == "63 8C E5 C7") //Aqui fica o C�digo do cartao em Hexadecimal que sera verificado
  {
		digitalWrite(8, LOW);
    Serial.println("Acesso autorizado");
 
    digitalWrite(10, HIGH);// LED VERDE acende mostrando a liberacao
    delay(3000);
    digitalWrite(10, LOW);
    
    Serial.println();
		digitalWrite(8, HIGH);
  }
 
 else   {
		digitalWrite(8, LOW);
    Serial.println(" Acesso restrito");
    
    digitalWrite(9, HIGH);// LED VERMELHO acende mostrando liberacao
    delay(3000);
    digitalWrite(9, LOW);

		digitalWrite(8, HIGH);
    
  }
} 