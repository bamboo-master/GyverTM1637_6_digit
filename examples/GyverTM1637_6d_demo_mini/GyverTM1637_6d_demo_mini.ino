/*
   Пример вывода на дисплей с регистром TM1637
   показывает все возможности библиотеки GyverTM1637_6d
   AlexGyver Technologies http://alexgyver.ru/
*/

#define CLK 12
#define DIO 13

#include "GyverTM1637_6d.h"
GyverTM1637_6d disp(CLK, DIO);

uint32_t Now, clocktimer;
boolean flag;

void setup() {
  Serial.begin(9600);
  disp.clear();
  disp.brightness(7);  // яркость, 0 - 7 (минимум - максимум)

}

void loop() {
  runningText();
  normClock();
  ints();
  fadeBlink();
}

void fadeBlink() {
  // пишем HELL
  disp.displayByte(_H, _E, _L, _L, _O, _U);

  Now = millis();
  while (millis () - Now < 3000) {    // 3 секунды
    for (int i = 7; i > 0; i--) {
      disp.brightness(i);   // меняем яркость
      delay(40);
    }
    for (int i = 0; i < 8; i++) {
      disp.brightness(i);   // меняем яркость
      delay(40);
    }
  }
}



void normClock() {
  byte hrs = 15, mins = 0, degs = 25;
  uint32_t tmr;
  Now = millis();
  while (millis () - Now < 5000) {   // 10 секунд
    if (millis() - tmr > 500) {       // каждые полсекунды
      tmr = millis();
      flag = !flag;
      disp.point(flag);   // выкл/выкл точки

      // ***** часы! ****
      mins ++;
      if (mins > 59) {
        mins = 0;
        hrs++;
        if (hrs > 24) hrs = 0;
      }
      // ***** часы! ****
      disp.displayClock(hrs, mins, degs);   // выводим время функцией часов
    }
  }
  disp.point(0);   // выкл точки
}

void ints() {
  // тупо отправляем цифры
  disp.displayInt(-999);
  delay(200);
  disp.displayInt(-99);
  delay(200);
  disp.displayInt(-9);
  delay(200);
  disp.displayInt(0);
  delay(200);
  disp.displayInt(6);
  delay(200);
  disp.displayInt(66);
  delay(200);
  disp.displayInt(666);
  delay(200);
  disp.displayInt(6666);
  delay(200);
}

void runningText() {
  byte welcome_banner[] = {_H, _E, _L, _L, _O, _empty, _empty,
                           _t, _n, _1, _6, _3, _7,
                          };
  disp.runningString(welcome_banner, sizeof(welcome_banner), 150);  // 200 это время в миллисекундах!
}
