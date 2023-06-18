int led = 4;
int led2 = 7;
int btn = 2;
int time = 500;

volatile bool ledOn = false;
unsigned long previousTime = 0;

void func() {
  previousTime = millis();
}

void setup() {
  Serial.begin(9600);
  pinMode(btn, INPUT_PULLUP);
  pinMode(led, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(btn), func, FALLING);
}

void loop() {

    unsigned long currentTime = millis();
    if (currentTime - previousTime < time) {
      digitalWrite(led, HIGH);
      delay(time);
      digitalWrite(led, LOW);
      
    }
  

  digitalWrite(led2,HIGH);
  delay(time);
  digitalWrite(led2, LOW);
  delay(time);

}
