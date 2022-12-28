#define RPin 4
#define GPin 3
#define BPin 2
#define Led1 5
#define Led2 6
#define Led3 7

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
}

void loop() {
  DynInd();
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

