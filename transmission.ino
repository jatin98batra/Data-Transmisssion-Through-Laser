char ch= 'b';
char usrArr[100];
int i=0,j=0;
int q=0;
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
q=0;
digitalWrite(10,HIGH);
while(Serial.available() == 0);
while(Serial.available()>0)
{
  ch=Serial.read();
  if(ch == '~') //end of line
  {
    usrArr[q]='~';
    q++;
    break;
    
  }
  else
  {
    usrArr[q]=ch;
    q++;
    if (q==16)
    { 
      usrArr[q]='\n';
      q++;
     }
  }
  
  
}
Serial.print("Sent");
//Serial.print(usrArr);
//delay(1000); //starting !


for(j=0;j<q;j++)
{ ch= usrArr[j];
//initializing
digitalWrite(10,LOW);
delay(30);
digitalWrite(10,HIGH);
for(i=0;i<8;i++)
  {
      if((ch&(0x80))== 128) //high
      {
       //Serial.print("1");
      digitalWrite(10,LOW);
      delayMicroseconds(5500);
      digitalWrite(10,HIGH);
       
      }
      
      else 
      {

        //Serial.print("0");
      digitalWrite(10,LOW);
      delayMicroseconds(1200);
      digitalWrite(10,HIGH);
        
        
      }
      
      
    ch=ch<<1;
  
  }
  
  }

  digitalWrite(10,HIGH);
//while(1);
                                                                                                  

}
