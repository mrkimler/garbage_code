#define pi 3.141592653589793238; //константа, не является переменной и не изменяется просто константа это сокращение числа для удобства, так же нельзя как-либо выводить
int a = 10; //Целое число принимает от -32768 до 32767; вес 2 байта
float b = 10.0; //Дробное число (десятичная дробь), точность 6-7 знаков; вес 4 байта
char c = 'a'; //Символ, может принять один любой символ из ASCII (-128-127); вес 1 байт
byte n = 1; //Байт, может принять значение от 0 до 255; вес 1 байт
float x = 1.0;
boolean y = true; //Логиский тип данных принимает только 0 (false) и 1 (true); вес 1 байт
#include <Servo.h>; //Включение библиотеки/файла
const int l; //Константа, невозможно поменять в дальнейшем данную переменную, без указания чему равен int, он принимает значение 0
char p = 't';
int h = 32767;
unsigned int h1 = 32768; //Принимает значения от 0 до 65535, вместо unsigned можно использовать word, они эквивалентны; вес 2 байта
long h2 = 2000000000; //Тоже что и int, только от -2 147 483 648 до 2 147 483 647, есть такой-же как и в int вариант unsigned long; вес 4 байта
double u = 1.0; //Эквивалентно float; вес 4 байта
String j = "this is a string";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Скорость обработки байтов, обязательно к указанию
  Serial.println("Hello, World!");
  Serial.println(a);Serial.println(b);Serial.println(c);Serial.println(n);
  float g = (float)a/b*n*pi; //(float)a перевод переменной из int в float
  Serial.println(g);Serial.println(y);Serial.println(l);Serial.println(p);Serial.println(h);Serial.println(h1);Serial.println(h2);Serial.println(j);

  //Математические операции
  Serial.println(sq(2)); //Возведение в степень 2
  Serial.println(sqrt(4)); //Возведение в квадратный корень
  Serial.println(abs(-1)); //Модуль
  Serial.println(sin(sqrt(3)/2)); //Синус
  Serial.println(cos(sqrt(3)/2)); //Косинус
  Serial.println(tan(sin(sqrt(3)/2)/cos(sqrt(3)/2))); //Тангенс
  Serial.println(round(g)); //Округление
  Serial.println(ceil(g)); //Округление в большую сторону
  Serial.println(floor(g)); //Округление в меньшую сторону
  Serial.println(pow(2, 3)); //Возведение в степень, 1-ое значение основание, 2-ое степень.

  //Укорочение слож. выч. и т.д.
  g += 10.0;
  g -= 10.0;
  g *= 2.0;
  g /= 2.0;
  g++; // +1
  g--; // -1
  g++;

  float o = 1*pi;
  Serial.println(g);Serial.println(o);
  Serial.println(o, 5); //Второе значение - кол-во знаков после запятой при выводе

  //Тип системы исчисления (десят. двоич. восьм. и т.д.)
  Serial.println(h, DEC);
  Serial.println(h, HEX);
  Serial.println(h, OCT);
  Serial.println(h, BIN);


}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  if (x == 1.0){
    Serial.print("aboba");
  }
  */

  /*
  if (Serial.available() > 0) { //Проверка буфера на наличие входящих данных
    byte p = Serial.read(); //Прочитать входящие данные в символьном формате согласно ASCII, т.е. можно ввести любые символы из ASCII, а на выводе будет кодировка данного символа в int/byte/long/word
    Serial.println(p);
  }
  */

  /*
  if (Serial.available() > 0) {
    char y = Serial.read(); //Прочитать один любой символ
    Serial.print(y);
  }
  */

  /*
  if (Serial.available() > 0) {
    int s = Serial.read() - '0'; //Прочитать данные в целочисленном формат
    Serial.println(s);
  }
  */

  if (Serial.available() > 0) {
    long z = Serial.parseInt(); //Складывает число из полученных цифр. Т.е если ввели 123, оно объеденит каждую цифру в числе обратно в 123.
    Serial.println(z);
    Serial.flush(); //Очищает буфер порта
  }

}
//Первый тест скетч здесь заканчивается. Пу пу пу.
