/*
Функция -фрагмент программного кода (подпрограмма), к которому можно обратиться из другого места программы.

Функция объявляется вне другой функции.

Два типа функций: 
Не возвращает результат(void)
Возвращает результат(тип данных)

Структура функций:

void/типДанных name_of_function(переменная1, переменная2...) {
  Код
}
return - возвращает результат функции
*/
int f, g;

int proportion(int a, int b){
  int s = a+b;
  Serial.print(a);Serial.print(" + ");Serial.print(b);Serial.print("=");Serial.println(s);
}

byte multiply(long a, long b){
  return a*b*255/1028115;
}

void setup() {
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(3, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  f = analogRead(A4);
  g = analogRead(A5);
  Serial.println(multiply(g, f));
  analogWrite(3, multiply(g, f));
  //Serial.println(g);
  //Serial.println(f);
  //unsigned long c = g*f;
  //Serial.println(c);
  delay(100);
}
