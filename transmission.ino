char ch= 'b';
char arr[]="PIET\nSucks";
int i=0,j=0;
int strLen;
void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT);
  pinMode(4,INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

//Code: Do you want to send the data /syncronize !
//press 1 to sync 
// press 2 to send !
strLen=strlen(arr);
//ch='b';
digitalWrite(10,HIGH);
while(digitalRead(4)== HIGH);
delay(1000); //starting !


for(j=0;j<strLen;j++)
{ ch= arr[j];
//initializing
digitalWrite(10,LOW);
delay(55);
digitalWrite(10,HIGH);
for(i=0;i<8;i++)
  {
      if((ch&(0x80))== 128) //high
      {
       //Serial.print("1");
      digitalWrite(10,LOW);
      delay(15+15);
      digitalWrite(10,HIGH);
       
      }
      
      else 
      {

        //Serial.print("0");
      digitalWrite(10,LOW);
      delay(5);
      digitalWrite(10,HIGH);
        
        
      }
      
      
    ch=ch<<1;
  
  }
  
  }

  digitalWrite(10,HIGH);
Serial.println("DONE!\n");
//while(1);
                                                                                                  

}
