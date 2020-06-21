const int analogInPin = A5;
const int digitalPin = 30;
int sensorValue = 0; 
int setpoint = 30;                     

void setup() {
  Serial.begin(9600);                    
}

void loop() {
  
  sensorValue = analogRead(analogInPin);
  Serial.print("Leitura do Sensor de Luminosidade => " ); 
  Serial.println(sensorValue);      
  
  if(sensorValue > setpoint){  
     digitalWrite(digitalPin, HIGH); 
  } else {  
   digitalWrite(digitalPin, LOW);
  }
  delay(2);             
}
