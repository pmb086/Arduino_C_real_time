#include <LiquidCrystal.h>

const int ledPin =  8; 
const int mo =  7; 
const int mo2 =  6; 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
unsigned int flux3,flux4,flux5,flux11,flux12,flux13,flux14,flux15 ;   

unsigned char flux1,flux2,val1=165,val2=86,val3=82,val4=83,aa=0,bb=0;   // value output to the PWM (analog out)//val1=181,val2=86,val3=83,val4=82;
 //unsigned int val1=0,val2=333,val3=350,val4=344;
unsigned int a,b,c,d;


void setup() 
{
    Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(ledPin, OUTPUT);
  pinMode(mo, OUTPUT);
  pinMode(mo2, OUTPUT);
  // Print a message to the LCD.
  //lcd.print("hello, world!");
}

void loop() {
  flux11 = analogRead(A0);
 flux12 = analogRead(A2); 
 flux13 = analogRead(A1);


 
flux2=(flux11/4);
//flux2=(flux12/4);
flux3=(flux13/4);
//flux4=flux3-180;
flux1=flux2/6;

 if(flux1<35){digitalWrite(ledPin, HIGH);}
 if(flux1>37){digitalWrite(ledPin, LOW);}
  
  
  if(flux13<70 && aa==0){digitalWrite(mo, LOW);digitalWrite(mo2, HIGH);delay(560);aa=1;bb=0;digitalWrite(mo, HIGH);digitalWrite(mo2, HIGH);}

   if(flux13>70 && bb==0){digitalWrite(mo, HIGH);digitalWrite(mo2, LOW);delay(560);aa=0;bb=1;digitalWrite(mo, HIGH);digitalWrite(mo2, HIGH);}
 if( flux12>200 &&  flux12<300){ flux14=99;}
  if(  flux12<200){ flux14=95;}
  if(  flux12>300){ flux14=97;}
  lcd.setCursor(0, 0);
  lcd.print("TEM:");
   lcd.setCursor(4, 0);
    lcd.print(flux1);


   //lcd.setCursor(9, 1);
  //lcd.print("L:");
  // lcd.setCursor(11, 1);
  //  lcd.print(flux2);
    
  lcd.setCursor(8, 0);
  lcd.print("H:");
  lcd.setCursor(10, 0);
  lcd.print(flux13);
 lcd.setCursor(0, 1);
  lcd.print("S:");
  lcd.setCursor(3, 1);
  lcd.print(flux14);
   //EEPROM.write(addr, val);  
   //  addr = addr + 1;
  //if (addr == EEPROM.length()) {
   // addr = 0;
 // }

 //value = EEPROM.read(address);


    
  Serial.print("*" );
   Serial.print(flux1);
   //Serial.print("   L= " );
  // Serial.print(flux2);
    //Serial.print("   H= " );
   Serial.print(flux13);
    Serial.print(flux14);
 
  delay(260);flux14=98;
  delay(260); flux14=96;
  delay(26); 
}
