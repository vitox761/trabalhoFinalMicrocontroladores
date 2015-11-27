#include <Stepper.h>
#include <Wire.h>
#include <rgb_lcd.h>
#define STEPS 200
 
rgb_lcd lcd;

const int colorR = 0;
const int colorG = 255;
const int colorB = 0;
int touch = 2;
int var;
Stepper stepper(STEPS, 8,10, 11, 9);

void setup() {
  // Velocidade inicial Motor em RPM
  stepper.setSpeed(50);
  // Tamanho display
  lcd.begin(16, 2);
  pinMode(touch,INPUT);
  Serial.begin(9600);
  attachInterrupt(0,interrupt,HIGH);
}
void loop() {
/*
  delay(2000);
  // Selecionar cor display
  lcd.setRGB(colorR, colorG, colorB);
 
  lcd.clear();
  // Mensagem na linha 1
  lcd.setCursor(0, 0);
  lcd.print("Mensagem Inicial"); 
  // Move Cursor LCD para Linha 2
  lcd.setCursor(0, 1);
  lcd.print("Horario");
  stepper.step(-200);
  
  delay(2000);
  // Selecionar cor display
  lcd.setRGB(colorR, colorB, colorG);
 
  lcd.clear();
  // Mensagem na linha 1
  lcd.setCursor(0, 0);
  lcd.print("Mensagem Inicial"); 
  // Move Cursor LCD para Linha 2 
  lcd.setCursor(0, 1);
  lcd.print("Anti-Horario");
  stepper.step(200);
  
  delay(100);
*/
}
void interrupt(){
  Serial.println("aeh");
  // Selecionar cor display
  lcd.setRGB(colorG, colorB, colorR);
  lcd.clear();
  // Mensagem na linha 1
  lcd.setCursor(0, 0);
  lcd.print("RECIPIENTE CHEIO"); 
}


