/*
Первый код для REAL LIFE

GPIO(пин) - порт ввода-вывода
Цифровые пины: D2-D13; D0(RX), D1(TX)
Аналоговые пины: A0-A7

Все порты могут принимать и выдавать цифровой сигнал
A0-A5 - умеют работать как цифровые. Т.е. цифровые датчики, кнопки, светодиоды и реле подключать к ним можно (A6 и A7 - НЕТ)

Аналоговые порты умеют измерять напряжение.
АЦП(ADP) - аналогово-цифровой преобразователь.
Т.е. к ним можно подключать аналоговые датчики.

На Arduino Nano и UNO ШИМ пины - D3, D5, D6, D9, D10, D11

Аналоговые и цифровые пины могут работать как вход, и как выход. По умолчанию все пины работают как ВХОД
*/
unsigned long d;

void setup() {
  /*
  pinMode(19, OUTPUT); //Настроить порт, первое знач. - пин от 0 до 13 цифровые, от 14 до 19 аналоговые, второе знач. режим работы
  pinMode(12, OUTPUT); //OUTPUT - выход выдаёт 0В или 5В; INPUT - вход, принимает сигнал; INPUT_PULLUP - вход с подтяжкой к 5В
  pinMode(13, OUTPUT);
  digitalWrite(19, 0); //digitalWrite(pin, signal) - подать цифровой сигнал; signal - какой сигнал 0/LOW/false - 0В, 1/HIGH/true - 5В
  digitalWrite(12, 1);
  digitalWrite(13, 0);
  */
  pinMode(3, INPUT_PULLUP);
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  boolean a = !digitalRead(3);
  boolean b = digitalRead(13);
  //boolean c = digitalRead(12);

  Serial.print(a);Serial.print("A5, ");
  Serial.print(b);Serial.println("D13");
  if (a == 1) {
    digitalWrite(13, 1);
  } else {
    digitalWrite(13, 0);
  }
}
