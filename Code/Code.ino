#define RPin 4
#define GPin 3
#define BPin 2
#define Led1 5
#define Led2 6
#define Led3 7
#define SwPin A0

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int colors [7][3] = {
  {255, 0, 0},
  {128, 45, 0},
  {255, 255, 0},
  {0, 255, 0},
  {0, 255, 255},
  {0, 0, 255},
  {255, 0, 255}
};

int LedColor[3][3] = {
    {128, 45, 0},
    {255, 0, 255},
    {0, 0, 255}
  };

void setup() {
  pinMode(RPin, OUTPUT);
  pinMode(GPin, OUTPUT);
  pinMode(BPin, OUTPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(SwPin, INPUT);
}

void loop() {
  static uint32_t timer;
  static int speed;
  speed = map(analogRead(SwPin), 0, 1024, 60, 700);
  DynInd();
  if(millis() - timer >= speed){
    nextStep();
    timer = millis();
  }
  
}

void nextStep(){
  int i = 0;
  for (int e = 0; e < 3; e++) {
    i = random(0, 7);
   for (int Counter = 0; Counter < 3; Counter++) {
     LedColor[e][Counter] = colors[i][Counter];
   }
  }
}
void DynInd(){
  int port[3] = { Led1, Led2, Led3 };
      for (int Counter = 0; Counter < 3; Counter++) {
      analogWrite(RPin, LedColor[Counter][0]);
      analogWrite(GPin, LedColor[Counter][1]);
      analogWrite(BPin, LedColor[Counter][2]);
      digitalWrite(port[Counter], LOW);
      delay(1);
      digitalWrite(port[0], HIGH);
      digitalWrite(port[1], HIGH);
      digitalWrite(port[2], HIGH);
      }
}

