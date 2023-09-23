#include <LiquidCrystal.h>
#include <Servo.h>
Servo servo;
#define Rs 2
#define E 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
LiquidCrystal lcd(Rs,E,D4,D5,D6,D7);
int LEDR = 12;
int LEDG = 13;
float temp0 = 0;
float temp = 0;
void setup() {
  lcd.begin(16,2);
  servo.attach(9,300,2400);
  pinMode(LEDG,OUTPUT);
  pinMode(LEDR,OUTPUT);
}

void loop() {
  temp = analogRead(A0);
  temp = 0.4888*temp;
  if (temp0==temp)
  {
  }
  else{
  lcd.clear();
  if (int(temp)>= 25){
    lcd.setCursor(0,0);
    lcd.print(temp);
    lcd.print(" C");
    lcd.setCursor(0,1);
    lcd.print("Temp is high");
    servo.write(180);
    digitalWrite(LEDG,LOW);
    digitalWrite(LEDR,HIGH);
  }
    else if (int(temp)<= 23){
    lcd.setCursor(0,0);
    lcd.print(temp);
    lcd.print(" C");
    lcd.setCursor(0,1);
    lcd.print("Temp is normal");
    servo.write(103);
    digitalWrite(LEDR,LOW);
    digitalWrite(LEDG,HIGH);
  }
      else{
    lcd.setCursor(0,0);
    lcd.print(temp);
    lcd.print(" C");
  }
  }
  delay(1000);
  temp0 = temp;
}
