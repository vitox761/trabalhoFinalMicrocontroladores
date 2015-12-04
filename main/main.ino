#include <Stepper.h>
#include <Wire.h>
#include <rgb_lcd.h>
#define STEPS 200
 
rgb_lcd lcd;

// Variaveis auxiliares
int var;
int voltas;

// motor de passos
Stepper stepper(STEPS, 8,10, 11, 9);

// Demais componentes
int botao_comeco = 2;
int sensor1 = 4;
int sensor2 = 8;
int cano1 = 6;
int cano2 = 5;

// Estado inicial
int estado = 0;

void setup() {
  // Tamanho display
  lcd.begin(16, 2);
  
  // Define botoes e sensores
  pinMode(botao_comeco,INPUT);
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  
  // Definindo Canos
  pinMode(cano1,OUTPUT);
  pinMode(cano2,OUTPUT);
    
  // Interrupcoes
  attachInterrupt(0,comeco,HIGH);
}
void loop() {
  
  // Estado Iniciao = PARADO
  if(estado == 0){
    // Selecionar cor display
    lcd.setRGB(colorR, colorG, colorB);
    // Mensagem na linha 1
    lcd.setCursor(0, 0);
    lcd.print("Estado Atual: 0"); 
    // Move Cursor LCD para Linha 2
    lcd.setCursor(0, 1);
    lcd.print("Parado");
  }
  // Estado 1 = Enchendo recipiente com liquido 1
  if(estado == 1){
    // Selecionar cor display
    lcd.setRGB(0, 0, 255);
    // Mensagem na linha 1
    lcd.setCursor(0, 0);
    lcd.print("Estado Atual: 1"); 
    // Move Cursor LCD para Linha 2
    lcd.setCursor(0, 1);
    lcd.print("Despeja Liquido1");
    // Abre cano
    digitalWrite(cano1,HIGH);
    
    // Verifica se encheu
    var = digitalRead(sensor1);
    if(var == HIGH)
      estado = 2;
  }
  // Estado 2 = Misturando o liquido 1
  if(estado == 2){
    // Selecionar cor display
    lcd.setRGB(0, 120, 120);
    // Mensagem na linha 1
    lcd.setCursor(0, 0);
    lcd.print("Estado Atual: 2"); 
    // Move Cursor LCD para Linha 2
    lcd.setCursor(0, 1);
    lcd.print("Mistura Liquido1");
    
    // Fecha cano
    digitalWrite(cano1,LOW);
    
    // Misturando
    voltas = 0;
    stepper.setSpeed(50);
    while(voltas < 25){
      stepper.step(200); // 200 passos = 1 volta, 50 voltas = 1 min ; Sentido Anti-horario
      voltas++;
    }
    estado = 3;
  }
  // Estado 3 = Adicionando liquido 2 ao recipiente
  if(estado == 3){
    // Selecionar cor display
    lcd.setRGB(255, 0, 0);
    // Mensagem na linha 1
    lcd.setCursor(0, 0);
    lcd.print("Estado Atual: 3"); 
    // Move Cursor LCD para Linha 2
    lcd.setCursor(0, 1);
    lcd.print("Despeja Liquido2");
    // Abre cano
    digitalWrite(cano2,HIGH);
    
    // Verifica se encheu
    var = digitalRead(sensor2);
    if(var == HIGH){
      estado = 4;
      lcd.clear();
    }
  }
  // Estado 4 = Mistura L1 + L2
  if(estado == 4){
    // Selecionar cor display
    lcd.setRGB(120, 0, 120);
    // Mensagem na linha 1
    lcd.setCursor(0, 0);
    lcd.print("Estado Atual: 4"); 
    // Move Cursor LCD para Linha 2
    lcd.setCursor(0, 1);
    lcd.print("Mistura L1+L2");
    
    // Fecha cano
    digitalWrite(cano2,LOW);
    
    voltas = 0;
    stepper.setSpeed(50);
    while(voltas < 25){
      stepper.step(-200); // 200 passos = 1 volta, 50 voltas = 1 min; Sentido Horario
      voltas++;
    }
    estado = 5;
    lcd.clear();
  }
  // Estado 5 = Deixa Liquido em repouso
  if(estado == 5){
    // Selecionar cor display
    lcd.setRGB(120, 120, 120);
    // Mensagem na linha 1
    lcd.setCursor(0, 0);
    lcd.print("Estado Atual: 5"); 
    // Move Cursor LCD para Linha 2
    lcd.setCursor(0, 1);
    lcd.print("Mistura Repouso");
    
    // Aguarda 30 segundo em repouso
    delay(30000);
    // Volta para Estado Inicial
    estado = 0;
    lcd.clear(); 
  }
}
void comeco(){
  //Inicia processo , apenas se estiver no estado inicial
  if(estado == 0)
    estado = 1;
}

