
// ## Display LCD 16x2
//FUNCIONANDO
#include <LiquidCrystal.h>

//conecta os pinos no arduino isso vem da biblioteca

const int rs = 3, en = 4, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float valor_potencia;
int umidade;//recebe do sensor os valores
int analogIn = A1;

int RawValue= 0;
double Voltage = 0;
double tempC = 0;

void setup() {
  
  // inicia a tela
  lcd.begin(16, 2);//inicia 
  lcd.print("Iniciando...");
  delay(1000);
  lcd.clear();//limpa
  Serial.begin(9600);
}

  
void loop() {
  
  mostrando_umidade();
  mostrando_temperatura();

  }

void mostrando_umidade(){
  
 umidade=analogRead(A0);
// define a entrada analogica na porta A0
  
  
  if (umidade > 450){//se for maior que 450
  lcd.setCursor(0, 0); // posição que ira imprimir na tela
  lcd.print("Grao Umido");
  lcd.setCursor(0, 1);//imprimi no inicio da tela
  lcd.print("Inicie a secagem");
    
  if (umidade == analogRead(LOW)){
  }    
  }else if (umidade < 450){ 
    lcd.print("Grao Seco"); 
   
  
  }
    
  delay(5000);
  lcd.clear();//limpa
   
  
}

void mostrando_temperatura(){
  
  RawValue = analogRead(analogIn);
  Voltage = (RawValue / 1023.0) * 5000; // 5000 to get millivots.
  tempC = (Voltage-500) * 0.1; // 500 is the offset 
  Serial.print("Raw Value = " );                  
  Serial.print(RawValue);      
  Serial.print("\t Temperature in C = ");
  Serial.print(tempC,1);
  
 
   if (tempC <= 8){
   	lcd.setCursor(0, 0); // posição que ira imprimir na tela
  	lcd.print("Temperatura OK"); 
   }else if (tempC > 8 && tempC < 16){//se for maior que 450
    lcd.setCursor(0, 0);//imprimi no inicio da tela
  	lcd.print("Temperatura um");
    lcd.setCursor(0, 1);
    lcd.print("pouco a cima");
  }else if (tempC > 16 ){ 
   lcd.setCursor(0, 0);//imprimi no inicio da tela
  	lcd.print("Temperatura alta");
    lcd.setCursor(0, 1);
    lcd.print("Esfriando...");
  }else if (tempC < 2 ){ 
   lcd.setCursor(0, 0);//imprimi no inicio da tela
  	lcd.print("Temperatura baixa");
    lcd.setCursor(0, 1);
    lcd.print("Esfriando...");
  }
    
  delay(5000);
  lcd.clear();//limpa

  
}


  
  


  



 

