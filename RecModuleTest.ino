/*


  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)




*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int i=0,j;
long start_timer;
long stop_timer;
int count=0;
char ch;
bool mode=false;
char buf[150];
int byt_rec=0;


void setup() {
  // put your setup code here, to run once:
pinMode(8,INPUT);
pinMode(9,INPUT_PULLUP);
if(digitalRead(9)==LOW)
{
  mode =true;  
}
Serial.begin(9600);
  
  lcd.begin(16, 2);
  lcd.print("VISBLE LIGHT");
  lcd.setCursor(0, 1);
  lcd.print("COMMUNICATION");
  delay(1500);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BY: Jatin, Madhu");
  lcd.setCursor(0, 1);
  lcd.print("and Ravi");
  delay(1500);
  lcd.clear();
 lcd.setCursor(0,0);
lcd.print("Waiting...");

  
 
    
}

void loop() {

if (mode == false)
{
label: 
ch=ch&(0x00); //resetting
while(digitalRead(8)==LOW); //hold signal
  lcd.clear();
  lcd.setCursor(0,0);
start_timer=millis(); //if low is detected !
while(digitalRead(8)== HIGH); //if its LOW 
stop_timer=millis();

if((stop_timer-start_timer)>=10) //5ms for start signal
{
  Serial.println("Initialized");
    for(i=0;i<7+1;i++)
     {
     
        while(digitalRead(8)==LOW);
       start_timer=millis();
       while(digitalRead(8)==HIGH);
       stop_timer=millis();
     
     if(((stop_timer-start_timer)>=2) && ((stop_timer-start_timer)<=10))
     {
          ch=ch|(0x01);
          //count++;
          ch=ch<<1;
          Serial.print("1");
     }

       else if((stop_timer-start_timer)<2)
        {
           ch=ch|(0x00);
           //count++;
           ch=ch<<1; 
           Serial.print("0");
           
        }          
      
  }  
  ch=ch>>1;
  ch=ch&(0x7f); 
  
 if(ch == '~')
  {
    lcd.setCursor(0,0);
    lcd.print("Rec_String=");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    for(i=0;i<byt_rec;i++)
    {
      if(buf[i]=='\n')
      lcd.setCursor(0,1);
      else
      lcd.write(buf[i]);
      delayMicroseconds(10);
    }
    //while(digitalRead(9)== HIGH); //waiting
    byt_rec=0;
    goto label;
  }
  else
  {
    buf[byt_rec]=ch;
    byt_rec++;  
  
  }
//Serial.println("Verifying!");
/*for(j=0;j<8;j++)
  {
      if((ch&(0x80))== 128) //high
      {
       Serial.print("1");     
      }
      else
      Serial.print("0");
      ch=ch<<1;
      
  }*/


    }

  }

else 
{
  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Sync....");
    delay(1000);

while(1)
{
  if(digitalRead(8)==HIGH)
  { 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("No Illumination !");
    }

    else
    {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Light Received!");   
    }
}
}

}
