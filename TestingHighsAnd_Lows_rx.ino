int stop_t,start;
void setup() {
  // put your setup code here, to run once:
pinMode(8,INPUT_PULLUP);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(digitalRead(8)== HIGH);
  start=millis();
  while(digitalRead(8)== LOW);
  stop_t=millis();

  Serial.write(stop_t-start);

}
