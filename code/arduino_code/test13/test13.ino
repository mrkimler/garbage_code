#include <string.h>
#include <avr/pgmspace.h>

union { //объединяет несколько полей в одной и той же области памяти
  uint32_t u32;
  uint16_t u16[2];
  uint8_t u8[4];
} u;

enum color_t : uint8_t { //enum <имя> {значения} - это создание типа данных принимающего опр. значения, нумерация значений изначально идёт от 0 
  BLACK, //0
  WHITE, //1
  GREEN, //2
  BROWN, //...
  BLUE,
  RED
};

const char* color_array[6] = {"чёрный", "белый", "зелёный", "коричневый", "синий", "красный"};

struct hat_t { 
/*  
struct <имя> {переменные} - создание своего типа данных состоящих из опред. переменных. Для использования 
данного типа данных мы вводм <имя struct> <переменная>, а далее все переменные в данном типе данных используем 
чере точку: <переменная с типом данных struct>[к какому номеру будет обращаться].<переменная из struct>
*/
  uint8_t count : 5;
  char name[11];
  color_t color : 3;
};

hat_t hats[2];

const char str[] PROGMEM = "Hi!!!";

void printHat(hat_t &hat) {
  Serial.print(hat.name);
  Serial.print(F(": "));
  Serial.print(hat.count);
  Serial.println(F(" штук"));
  Serial.print(F("Цвет: "));
  for (uint8_t i = 0; i < 6; i++) {
    if (hat.color == i){
      Serial.println(color_array[i]);
    }
  }
}

void setup() {
  Serial.begin(9600);

  char str1[80];

  strcpy(str1, "Hello");//тут низя загонять во флэш память
  strcat(str1, ", World! Dynamic Memory");
  Serial.println(str1);

  strcpy_P(str1, PSTR("Hello"));//тут можно загонять во флэш память
  strcat_P(str1, PSTR(", World! PSTR"));
  Serial.println(str1);

  Serial.println(F("Hello, World! F")); //Перемещение из динамической памяти во флэш память

  Serial.println((const __FlashStringHelper*)str);

  strcpy_P(hats[0].name, PSTR("Ковбоские"));
  hats[0].count = 17;
  hats[0].color = BROWN;
  printHat(hats[0]);

  strcpy_P(hats[1].name, PSTR("Герцогские"));
  hats[1].count = 9;
  hats[1].color = BLACK;
  printHat(hats[1]);
}

void loop() {}