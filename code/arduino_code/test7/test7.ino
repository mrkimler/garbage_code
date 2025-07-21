/*
Стандартный ардуиновский ШИМ генератор

Разрядность: 8бит
Вход: 0-255
Выход: ШИМ сигнал со скважностью 0-100%
Функция analonWrite(pin, duty) - пин и значени от 0 до 255
*/
//unsigned long g;
byte a;

void setup() {
  pinMode(6, OUTPUT);
  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //if (millis() - g >= 100) {
    //g = millis();
  a=analogRead(A3)/4; //(unsigned long)analogRead(A3)*255/1024; //Это на 600+ байт эффективнее, чем через float
  //Serial.println(a);
  //a = map(a, 0, 1023, 0, 255);
  //a = constrain(a, 0, 255);
  analogWrite(6, a);
  //}
}
