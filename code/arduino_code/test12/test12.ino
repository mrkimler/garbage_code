#include <string.h> //не требует импортирования, нооо, WHY NOT?!

int16_t f[10];
char str1[10] = { 'a', 'b', 'c', 'd', 'e', 'f' };//Здесь 0 элемента в конце не будет
char h[] = "bababuy"; //Когда мы в символьный массив загоняем строку в конце есть 0 элемент
char str2[10] = "aboba";

void setup() {
  Serial.begin(9600);

  for (int8_t i = 0; i < 10; i+=3){
    Serial.print(accumulation(i));
    Serial.print(" ");
  }

  int16_t g = 3;
  mul4(g);
  Serial.println();
  Serial.println(g);

  mul2(&g); //&переменная - взятие АДРЕССА переменной
  Serial.println(g);

  mul3(g);
  Serial.println(g);

  for (int8_t i = 0; i < 10; i++) {
    f[i] = i+1;
  }
  print_array(f);
  print_arrayWA(&f[0]);

  char str[80];

  strcpy(str, "Hello"); //тут тоже будет в конце 0 элемент, strcpy(array, string) - мы указываем в какой массив будет скопирована строка 
  strcat(str, ", World!"); //strcat(array, string) - мы указываем к какому массиву мы приращиваем строку
  Serial.println(str);

  char string1[] = "Hello";
  char string2[] = "Hello, World!";

  if (string1 != string2) { //тут сравниваются не значения массива, а лишь указатели, т.е. они всегда будут не равны
    Serial.print("not ");
  }
  Serial.println("equal adresses");

  if (strcmp(string1, string2)) { //если string1 != string2 то вывести, иначе не выводить, тут проверяются на равенство именно массивы. strcmp(array1, array2)
    Serial.print("not ");
  }
  Serial.println("equal");

  if (strcmp(string1, string2)) { //тоже самое, что и strcmp, но с указанием кол-ва сравниваемых символов
    Serial.print("not ");
  }
  Serial.println("equal 5 first symbols");
  Serial.println(strlen(string1)); //strlen(array) - длинна массива без учёта 0 в конце
}

void loop() {

}

int16_t accumulation (int16_t number) {
  static int16_t result; 
  /*
  static - объявление локальной переменной глобально, но эта переменная всё ещё остаётся в пределах функции. 
  Т.е. после завершения функции значение переменной не обнуляется, но и использовать за пределами функции нельзя.
  */
  result+=number;
  return result;
}

int16_t mul2(int16_t *number) { //*переменная - указатель на знаковое целое. Оно ожидает АДРЕСС переменной, а не саму переменную.
  *number*=2;
  return *number; //Меняет значение переменной g
}

int16_t mul3(int16_t &number) { //&переменная - передача параметра по ссылке. Оно ожидает ПЕРЕМЕННУЮ.
  number*=3;
  return number; //Меняет значение переменной g
}

int16_t mul4(int16_t number) {
  number*=4;
  return number; //Не меняет значение переменной g
}

void print_array(int16_t arr[]) {
  for (int8_t i = 0; i < 10; i++) {
    Serial.print(arr[i]);
    if (i < 9) {
      Serial.print(" ");
    } else {
      Serial.println();
    }
  }
}

void print_arrayWA(int16_t *arr) {
  for (int8_t i = 0; i < 10; i++) {
    Serial.print((int16_t)(arr + i));
    Serial.print(":");
    Serial.print(*(arr + i));
    if (i < 9) {
      Serial.print(" ");
    } else {
      Serial.println();
    }
  }
}