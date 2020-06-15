#include <LiquidCrystal.h>
#include <Keypad.h> //Header

LiquidCrystal lcd(12,11,A4,A5,13,10);
const byte ROWS = 4; 
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'7','8','9','C'},
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = { 2, 3, 4, 5 };
byte colPins[COLS] = { 6, 7, 8, 9 };
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int fm = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  //case 1: when there is no face mask
  while(fm==0){
    int fm_temp = 0;
    lcd.setCursor(0,0);
    lcd.print("Number of mask:");
    //input number of face mask
    char key = kpd.getKey();
    if(key){
          Serial.print(key);
      }
    }
  //case 2: when there is one or more face mask
  while(fm!=0){
    lcd.setCursor(0,0);
    lcd.print("Current amount:");
    lcd.setCursor(0,1);
    lcd.print(fm);  
  }  
}
