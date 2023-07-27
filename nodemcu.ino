int sensor_pin = A0;
int relay1 = 5;

void setup(){
Serial.begin(9600);
pinMode(relay1, OUTPUT);
}

void loop(){
int s1=analogRead(sensor_pin);
Serial.println(s1);
delay(100);

if(s1>400){
  digitalWrite(relay1, LOW);
  Serial.println("Hidup");
  delay(1000);
} else {
  digitalWrite(relay1, HIGH);
  Serial.println("Mati");
  delay(1000);
  }
}
