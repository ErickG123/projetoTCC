// Importando as bibliotecas do Bluetooth e do Servo Motor
#include <SoftwareSerial.h>
#include <Servo.h>

// Definindo os pinos do módulo bluetooth
#define pinBT_RX 10
#define pinBT_TX 11

// Definindo os pinos dos led's
#define pinCanal1 3
#define pinCanal2 4
#define pinCanal3 5
#define pinCanal4 6
#define pinCanal5 7
#define pinCanal6 8
// Definindo o pino do Servo Motor
#define pinServo 9

// Configuração do módulo bluetooth
SoftwareSerial serialBT(pinBT_RX, pinBT_TX);
// Configuração do servo motor
Servo myservo;

// Variáveis para controlar os Led's
String comando;
int portas[] = { pinCanal1, pinCanal2, pinCanal3, pinCanal4, pinCanal5, pinCanal6 };

void setup() {
  // Iniciando o Monitor Serial
  Serial.begin(9600);
  serialBT.begin(9600);

  // Atribuindo o pinServo a função
  myservo.attach(pinServo);

  //Laço de repetição que define as portas dos Led's como OUTPUT
  for (int i = 0; i < 7; i++) {
    pinMode(portas[i], OUTPUT);
  }
  // Print que inicial do Monitor Serial
  Serial.println("Sketch Iniciado!");
}

void loop() {
  if (serialBT.available() > 0) {
    // Led | Servo
    char byteRec = serialBT.read();
    comando += byteRec;
    
    // Led
    if (byteRec == ';') {
      Serial.print("Comando Recebido: ");
      Serial.println(comando);

      if (comando.substring(0, 1) == "C") {
        String canal = comando.substring(1, 2);
        bool nivel = ( comando.indexOf("true") != -1 );

        digitalWrite(portas[canal.toInt()], nivel);
      }
      comando = "";
    }

    // Servo Motor
    if (byteRec == 0){
      myservo.write(byteRec);
    } else if (byteRec == 45) {
      myservo.write(byteRec);
    } else {
     myservo.write(byteRec); 
    }
    
    Serial.println(byteRec);
  }
}
