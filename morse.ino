#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

String instruction = "Write: ";
String input;

const int letterArraySize = 50;
char letters[letterArraySize];

SoftwareSerial bt_comm(11,10);
LiquidCrystal lcd(9, 8, 4, 5, 6, 7);
int lcd_setup_time = 1000;
int lcd_loop_time = 300;

int led = 3;

int buzzer = 2;
int buzzFreq = 550;

int dotWait = 100;
int dashWait = 300;

int signBreak = 100;
int letterBreak = 300;
int wordBreak = 300;

void dotSound(){
  
  delay(dotWait);
  
}

void dashSound(){
  
  delay(dashWait);
  noTone(buzzer);
}


void dot(){
  digitalWrite(led, HIGH);
  tone(buzzer, buzzFreq);
  lcd.print(".");
  delay(dotWait);
  digitalWrite(led, LOW);
  noTone(buzzer);
}

void dash(){
  digitalWrite(led,HIGH);
  tone(buzzer, buzzFreq);
  lcd.print("-");
  delay(dashWait);
  digitalWrite(led,LOW);
  noTone(buzzer);
}

// Morse code implementation for letters
void A(){
  dot();
  delay(signBreak);
  dash();
  lcd.clear();
}

void B(){
  dash();
  delay(signBreak);
  dot();
  delay(signBreak);
  dot();
  delay(signBreak);
  dot();
  lcd.clear();
}

void C(){
  dash();
  delay(signBreak);
  dot();
  delay(signBreak);
  dash();
  delay(signBreak);
  dot();
  lcd.clear();
}

void D(){
  dash();
  delay(signBreak);
  dot();
  delay(signBreak);
  dot();
  lcd.clear();
}

void E(){
  dot();
  lcd.clear();
}

void Fr(){
  dot();
  delay(signBreak);
  dot();
  delay(signBreak);
  dash();
  delay(signBreak);
  dot();
  lcd.clear();
}

void G(){
  dash();
  delay(signBreak);
  dash();
  delay(signBreak);
  dot();
  lcd.clear();
}

void H(){
  dot();
  delay(signBreak);
  dot();
  delay(signBreak);
  dot();
  delay(signBreak);
  dot();
  lcd.clear();
}

void I(){
  dot();
  delay(signBreak);
  dot();
  lcd.clear();
}

void J(){
  dot();
  delay(signBreak);
  dash();
  delay(signBreak);
  dash();
  delay(signBreak);
  dash();
  lcd.clear();
}

void K(){
  dash();
  delay(signBreak);
  dot();
  delay(signBreak);
  dash();
  lcd.clear();
}

void L(){
  dot();
  delay(signBreak);
  dash();
  delay(signBreak);
  dot();
  delay(signBreak);
  dot();
  lcd.clear();
}

void M(){
  dash();
  delay(signBreak);
  dash();
  lcd.clear();
}

void N(){
  dash();
  delay(signBreak);
  dot();
  lcd.clear();
}

void O(){
  dash();
  delay(signBreak);
  dash();
  delay(signBreak);
  dash();
  lcd.clear();
}

void P(){
  dot();
  delay(signBreak);
  dash();
  delay(signBreak);
  dash();
  delay(signBreak);
  dot();
  lcd.clear();
}

void Q(){
  dash();
  delay(signBreak);
  dash();
  delay(signBreak);
  dot();
  delay(signBreak);
  dash();
  lcd.clear();
}

void R(){
  dot();
  delay(signBreak);
  dash();
  delay(signBreak);
  dot();
  lcd.clear();
}

void S(){
  dot();
  delay(signBreak);
  dot();
  delay(signBreak);
  dot();
  lcd.clear();
}

void T(){
  dash();
  lcd.clear();
}

void U(){
  dot();
  delay(signBreak);
  dot();
  delay(signBreak);
  dash();
  lcd.clear();
}

void V(){
  dot();
  delay(signBreak);
  dot();
  delay(signBreak);
  dot();
  delay(signBreak);
  dash();
  lcd.clear();
}

void W(){
  dot();
  delay(signBreak);
  dash();
  delay(signBreak);
  dash();
  lcd.clear();
}

void X(){
  dash();
  delay(signBreak);
  dot();
  delay(signBreak);
  dot();
  delay(signBreak);
  lcd.clear();
}

void Y(){
  dash();
  delay(signBreak);
  dot();
  delay(signBreak);
  dash();
  delay(signBreak);
  dash();
  lcd.clear();
}

void Z(){
  dash();
  delay(signBreak);
  dash();
  delay(signBreak);
  dot();
  delay(signBreak);
  dot();
  lcd.clear();
}




void setup(){

  bt_comm.begin(9600);
  Serial.begin(9600);
  lcd.begin(16,2);
	pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.print("Hello");
  delay(lcd_setup_time);
}

void loop(){

  delay(80);
  Serial.println(instruction);
  bt_comm.println(instruction);

  while(bt_comm.available() == 0) {}

  input = bt_comm.readString();
  
  int inputLen = input.length(); 
  inputLen = min(inputLen, letterArraySize); // clear unnecessary memory

  for (int i = 0; i < inputLen; i++) {
    letters[i] = toupper(input.charAt(i)); // Store the letters in the array
  }

  for (int i = 0; i < inputLen; i++) { //print the letters with a space between
    bt_comm.print(letters[i]);
  }
  
  bt_comm.println("");


  for (int i = 0; i < inputLen; i++) { 
    switch (letters[i]){
      case 'A': 
        A();
        delay(letterBreak);
        bt_comm.println("A");
        Serial.println("A");
        break;
      case 'B':
        B();
        delay(letterBreak);
        bt_comm.println("B");
        Serial.println("B");
        break;
      case 'C':
        C();
        delay(letterBreak);
        bt_comm.println("C");
        Serial.println("C");
        break;
      case 'D':
        D();
        delay(letterBreak);
        bt_comm.println("D");
        Serial.println("D");
        break;
      case 'E':
        E();
        delay(letterBreak);
        bt_comm.println("E");
        Serial.println("E");
        break;
      case 'F':
          Fr();
          delay(letterBreak);
          bt_comm.println("F");
          Serial.println("F");
          break;
      case 'G':
        G();
        delay(letterBreak);
        bt_comm.println("G");
        Serial.println("G");
        break;
      case 'H':
        H();
        delay(letterBreak);
        bt_comm.println("H");
        Serial.println("H");
        break;
      case 'I':
        I();
        delay(letterBreak);
        bt_comm.println("I");
        Serial.println("I");
        break;
      case 'J':
        J();
        delay(letterBreak);
        bt_comm.println("J");
        Serial.println("J");
        break;
      case 'K':
        K();
        delay(letterBreak);
        bt_comm.println("K");
        Serial.println("K");
        break;
      case 'L':
        L();
        delay(letterBreak);
        bt_comm.println("L");
        Serial.println("L");
        break;
      case 'M':
        M();
        delay(letterBreak);
        bt_comm.println("M");
        Serial.println("M");
        break;
      case 'N':
        N();
        delay(letterBreak);
        bt_comm.println("N");
        Serial.println("N");
        break;
      case 'O':
        O();
        delay(letterBreak);
        bt_comm.println("O");
        Serial.println("O");
        break;
      case 'P':
        P();
        delay(letterBreak);
        bt_comm.println("P");
        Serial.println("P");
        break;
      case 'Q':
        Q();
        delay(letterBreak);
        bt_comm.println("Q");
        Serial.println("Q");
        break;
      case 'R':
        R();
        delay(letterBreak);
        bt_comm.println("R");
        Serial.println("R");
        break;
      case 'S':
        S();
        delay(letterBreak);
        bt_comm.println("S");
        Serial.println("S");
        break;
      case 'T':
        T();
        delay(letterBreak);
        bt_comm.println("T");
        Serial.println("T");
        break;
      case 'U':
        U();
        delay(letterBreak);
        bt_comm.println("U");
        Serial.println("U");
        break;
      case 'V':
        V();
        delay(letterBreak);
        bt_comm.println("V");
        Serial.println("V");
        break;
      case 'W':
        W();
        delay(letterBreak);
        bt_comm.println("W");
        Serial.println("W");
        break;
      case 'X':
        X();
        delay(letterBreak);
        bt_comm.println("X");
        Serial.println("X");
        break;
      case 'Y':
        Y();
        delay(letterBreak);
        bt_comm.println("Y");
        Serial.println("Y");
        break;
      case 'Z':
        Z();
        delay(letterBreak);
        bt_comm.println("Z");
        Serial.println("Z");
        break;
      case ' ':
        delay(wordBreak);   
        bt_comm.println(" ");
        Serial.println(" ");
      default:
        bt_comm.print("");
        Serial.println("");
        break;
     }
  }


  for (int i = 0; i < inputLen; i++) { // clear the string array
    letters[i] = '\0';
  }





}
