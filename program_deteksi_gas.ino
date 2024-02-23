#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //jika alamat register I2C 0x27 tidak bisa maka ganti dengan 0x3f

int merah = 8;
int hijau = 9;
int buzzer = 10;
int mq = 2;
int nilaimq = 0;

void setup() {
  Serial.begin(9600);
  pinMode (merah, OUTPUT);
  pinMode (hijau, OUTPUT);
  pinMode (buzzer, OUTPUT);
  pinMode (mq, INPUT);

  lcd.init();
  lcd.backlight();
  //lcd.noBacklight();
  lcd.setCursor(2, 0);
  lcd.print("KELOMPOK 10");
  lcd.setCursor(3, 1);
  lcd.print("SENSOR GAS");

  digitalWrite(merah, HIGH);
  digitalWrite(hijau, HIGH);
  digitalWrite(buzzer, HIGH); 
  delay(1000);
  digitalWrite(merah, LOW);
  digitalWrite(hijau, LOW);
  
 alarm(5, 100);
 lcd.clear();
    
  }

void loop() {
  nilaimq = digitalRead(mq);
  Serial.println(nilaimq);
  
  if(nilaimq == 0) {
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("GAS BOCOR");
  lcd.setCursor(3, 1);
  lcd.print("TERDETEKSI");
  delay(1000);
  alarm(10, 1000);
  lcd.clear();
 
  }
  
  else {
  digitalWrite(merah, LOW);
  digitalWrite(hijau, HIGH);

  lcd.setCursor(5, 0);
  lcd.print("KONDISI");
  lcd.setCursor(6, 1);
  lcd.print("AMAN");
  digitalWrite(merah, LOW);
  digitalWrite(hijau, LOW);
   
  }

}

void alarm(int x, int y){

   for (int i=0; i<x;i++){
    tone (buzzer, 4000,200);
    digitalWrite(merah, HIGH);
    //lcd.noBacklight();
    //delay (y);
    //digitalWrite(merah, LOW);
    lcd.backlight();
    delay(y);
    
   }
}
