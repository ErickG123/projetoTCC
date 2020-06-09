// Declarando as portas
const int analogInPin = A5;
const int digitalPin = 12;
int sensorValue = 0;
int setpoint = 30;

void setup() {
  // Iniciando o Monitor Serial
  Serial.begin(9600);
}

void loop() {
  // Armazenando o valor enviado pelo sensor
  sensorValue = analogRead(analogInPin);
  // Exibindo o valor lido no Monitor Serial
  Serial.print("Leitura do Sensor de Luminosidade => " );
  Serial.println(sensorValue);

  // Liga/Desliga do Led
  if (sensorValue > setpoint) {
    digitalWrite(digitalPin, HIGH);
  } else {
    digitalWrite(digitalPin, LOW);
  }
  delay(2);
}
