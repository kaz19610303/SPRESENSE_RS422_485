/*
  Spresense RS-422/485 ボード(NS-SPR-0301)　テストプログラム
  rS-422/485 test
  Set Jummper
  SJ1　1-2ショート　　
  SJ2　1-2ショート　　
  SJ3　ショート
  SJ4　ショート
  SJ5　ショート

  Next Step LLC
  https://next-step.asia/
  https://github.com/kaz19610303/SPRESENSE_RS422_485
*/

#define Receive_Enable 21                     // 受信許可ピン Active LOW
#define Transmit_Enable 20                    // 送信許可ピン Active High


void setup() {
  // initialize both serial ports:
  Serial.begin(115200);                         // Monitor terminal
  Serial2.begin(115200);                        // RS-422/485 terminal
  pinMode(21,OUTPUT);
  pinMode(20,OUTPUT);
  digitalWrite(Receive_Enable, LOW);          // Receive Enable
}

void loop() {
  Serial.println("Send unit_3 : ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  digitalWrite(Transmit_Enable, HIGH);        // Transmit Enable
  Serial2.println("ABCDEFGHIJKLMNOPQRSTUVWXYZ");              // Send RS-422/485 
  Serial.flush();
  digitalWrite(Transmit_Enable, LOW);         // Transmit Enable
  while (Serial2.available()) {               // Recive RS-422/485
    Serial.write(Serial2.read());             // Send Monitor terminal 
  }
  delay(1000);
}
