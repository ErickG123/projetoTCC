// Link para o código e explicação original: https://www.filipeflop.com/blog/sensor-ultrassonico-hc-sr04-ao-arduino/
// Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino
// Autor: FILIPEFLOP
 
// Carrega a biblioteca do sensor ultrassonico
// A biblioteca em questão foi baixado no link: https://github.com/filipeflop/Ultrasonic
#include <Ultrasonic.h>
 
// Define os pinos para o trigger e echo
#define pino_trigger 3
#define pino_echo 2
#define pino_led 30
 
// Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  pinMode(pino_led, OUTPUT);
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}
 
void loop()
{
  // Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  // Convertendo a leitura do serno em cm e pol
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  // Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec);
  delay(1000);

  if (cmMsec <= 10) {
    digitalWrite(pino_led, HIGH);
  } else {
    digitalWrite(pino_led, LOW);
  }
}
