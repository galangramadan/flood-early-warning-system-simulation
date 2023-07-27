int sensor_pin = A0;

void setup(){
Serial.begin(9600);
}

void loop(){
int s1=analogRead(sensor_pin);
Serial.println(s1);
delay(100);
}
