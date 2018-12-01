void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);
  pinMode(4,INPUT_PULLUP);
  Serial.begin(9600);
  }

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(10,HIGH);
while(digitalRead(4)== HIGH); //hold !
delay(1000);
digitalWrite(10,LOW);
Serial.println("yo");
delay(97);
digitalWrite(10,HIGH);


}
