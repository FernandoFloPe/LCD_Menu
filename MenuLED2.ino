#include <LiquidCrystal.h>

const int RS=12, E=11, DB4=5, DB5=4, DB6=3, DB7=2;
LiquidCrystal lcd(RS, E, DB4, DB5, DB6, DB7);

int Button1=10;
int Button2=9;
int selectButton3=8;
int menu=1;
int LED=7;

//--------------------------------------------------------------------------------------------

void setup() {
  lcd.begin(16,2);

  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);
  pinMode(selectButton3, INPUT_PULLUP);

  pinMode(LED, OUTPUT);
  updateMenu();
}

//--------------------------------------------------------------------------------------------
void loop() {
  if (!digitalRead(Button2))
  {
    menu++;
    updateMenu();
    delay(100);
  }
  if (!digitalRead(Button1))
  {
    menu--;
    updateMenu();
    delay(100);
  }
  if (!digitalRead(selectButton3))
  {
    execute();
    updateMenu();
    delay(100);
  }
}

//---------------------------------------------------------------------------------------------
//Actualizacion

void updateMenu(){
  switch(menu)
  {
    case 0:
    menu=1;
    break;
    case 1:
    lcd.clear();
    lcd.print(">>LED ON<<");
    lcd.setCursor(0,1);
    lcd.print(" LED OFF");
    break;
    case 2:
    lcd.clear();
    lcd.print(" LED ON");
    lcd.setCursor(0,1);
    lcd.print(">>LED OFF<<");
    break;
    case 3:
    lcd.clear();
    lcd.print(">>DESVANECIDO<<");
    lcd.setCursor(0,1);
    lcd.print(" INTERMITENTE");
    break;
    case 4:
    lcd.clear();
    lcd.print(" DESVANECIDO");
    lcd.setCursor(0,1);
    lcd.print(">>INTERMITENTE<<");
    break;
    case 5:
    menu=4;
    break;
  }
}

//--------------------------------------------------------------------------------------------

void execute(){
  switch(menu)
  {
    case 1:
    action1();
    break;
    case 2:
    action2();
    break;
    case 3:
    action3();
    break;
    case 4:
    action4();
    break;
  }
}

//---------------------------------------------------------------------------------------------
//Acciones

void action1(){
  lcd.clear();
  lcd.print(">>LED ON<<");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");

  digitalWrite(LED, HIGH);
  delay(500);
}

void action2(){
  lcd.clear();
  lcd.print(">>LED OFF<<");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");

  digitalWrite(LED, LOW);
  delay(500);
}

void action3(){
  lcd.clear();
  lcd.print(">>DESVANECIDO<<");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  funcDesvanecido(2);
  delay(1500);
}

void action4(){
  lcd.clear();
  lcd.print(">>INTERMITENTE<<");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  intermitente();
  delay(1500);
}

void funcDesvanecido(int temp){
  int periodo=temp;
  unsigned long tiempo1=0;
  unsigned long tiempo2=0;
  int brillo;
  for (brillo=0; brillo<=255; brillo++)
  {
    analogWrite(LED,brillo);
    tiempo1= millis();
    while(millis()<tiempo1+periodo){
      //Espera
    }
  }
  for(brillo=255; brillo>=0; brillo--){
    analogWrite(LED,brillo);
    tiempo2=millis();
    while(millis()<tiempo2+periodo){
      //Espera
    }
  }
}

void intermitente(){
  digitalWrite(LED,HIGH);
  delay(300);
  digitalWrite(LED,LOW);
  delay(300);
  digitalWrite(LED,HIGH);
  delay(300);
  digitalWrite(LED,LOW);
  delay(300);
}
