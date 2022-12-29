#define RPin 4
#define GPin 3
#define BPin 2
#define Led1 5
#define Led2 6                                                  // С помощью #define объявляем пины
#define Led3 7
#define SwPin A0



int colors [7][3] = {
  {255, 0, 0},
  {128, 45, 0},
  {255, 255, 0},                                                // Набор цветов
  {0, 255, 0},
  {0, 255, 255},
  {0, 0, 255},
  {255, 0, 255}
};

int LedColor[3][3] = {
    {128, 45, 0},
    {255, 0, 255},                                              // Храним инфу о текущей расцветке
    {0, 0, 255}
  };

void setup() {
  pinMode(RPin, OUTPUT);
  pinMode(GPin, OUTPUT);
  pinMode(BPin, OUTPUT);                                        // Входы выходы
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(SwPin, INPUT);
}

void loop() {
  static uint32_t timer;                                        // Переменная-таймер (тип нужен, чтоьы избежать переполнения)
  static int speed;                                             // Скорость 
  speed = map(analogRead(SwPin), 0, 1024, 60, 700);             // Задаем скорость с помощью потенциометра
  DynInd();                                                     // Окрашиваем светодиоды
  if(millis() - timer >= speed){                                // Работа таймера
    nextStep();                                                 // Выбираем следующую расцветку
    timer = millis();                                           // Обнуляем таймер
  }
}

void nextStep(){                                                // Выбираем новую расцветку для сетодиодов
  int i = 0;                                                    // Переменная, в которой лежит цвет
  for (int e = 0; e < 3; e++) {                                 // Цикл на 3 раза
    i = random(0, 6);                                           // Выбираем случайный цвет из 7
   for (int Counter = 0; Counter < 3; Counter++) {              // Задаём каждый из 3 параметров
     LedColor[e][Counter] = colors[i][Counter];                 // Копирование из исходника в масс
   }
  }
}
void DynInd(){                                                  // Обнавляем расцветку сетодиодов
  static int port[3] = { Led1, Led2, Led3 };                    // указываем порты gnd светодиодов
      for (int Counter = 0; Counter < 3; Counter++) {           // цикл на обнавление 3 светодиодов
        for(int i = 0; i < 3; i++){                             // цикл на 3 цвета
          analogWrite(RPin, LedColor[Counter][i]);              // пишем яркость
        }
      digitalWrite(port[Counter], LOW);                         // включаем землю на указаном пине
      delay(1);                                                 // чтобы все не смешивалось в белую кашу
      digitalWrite(port[0], HIGH);
      digitalWrite(port[1], HIGH);                              //Выключаем все светодиоды (ТК это земли HIGH это "LOW" и наоборот)
      digitalWrite(port[2], HIGH);
      }
}

