
#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>
#include <SPI.h>

#define SS_PIN 53
#define RST_PIN 49

const int led1 =11;
const int led2 =12;
const int led3 =13;
const int led4 =10;

MFRC522 mfrc522(SS_PIN, RST_PIN); // Instance of the class

void setup() {
   Serial.begin(9600);
   SPI.begin();       // Init SPI bus
   mfrc522.PCD_Init(); // Init MFRC522
   pinMode(led1,OUTPUT);
   pinMode(led2,OUTPUT);
   pinMode(led3,OUTPUT);
   pinMode(led4,OUTPUT);
   Serial.println("RFID reading UID");
}

void loop(){
   Read(); 
}


void Read() {
  //  Rfid Sense Code
  if ( mfrc522.PICC_IsNewCardPresent())
    {
        if ( mfrc522.PICC_ReadCardSerial())
        {
           Serial.print("Tag UID:");

                   if (mfrc522.uid.uidByte[0] == 74||  mfrc522.uid.uidByte[1] == 219|| mfrc522.uid.uidByte[2] == 54||  mfrc522.uid.uidByte[3] == 73) 
                  {
                    Serial.println("Blue CARD");
                    digitalWrite(led4, HIGH);
                  }
                  if (mfrc522.uid.uidByte[0] == 45||  mfrc522.uid.uidByte[1] == 179|| mfrc522.uid.uidByte[2] == 237||  mfrc522.uid.uidByte[3] == 43) 
                  {
                    Serial.println("WHITE CARD");
                    digitalWrite(led4, LOW);
                  }


          
            Serial.println();
            mfrc522.PICC_HaltA();
        } 
    }
}

//RedLight
void Red() {  
digitalWrite(led1,HIGH);
delay(10000);
digitalWrite(led1,LOW);
delay(600);
}


//YellowLight
void Yellow(){
digitalWrite(led2,HIGH);
delay(5000);
digitalWrite(led2,LOW);
delay(600);
}

//GreenLight
void Green(){
digitalWrite(led3,HIGH);
delay(10000);
digitalWrite(led3,LOW);
delay(500);

digitalWrite(led3,HIGH);
delay(500);
digitalWrite(led3,LOW);
delay(500);

digitalWrite(led3,HIGH);
delay(500);
digitalWrite(led3,LOW);
delay(500);

digitalWrite(led3,HIGH);
delay(500);
digitalWrite(led3,LOW);
delay(600);
}
