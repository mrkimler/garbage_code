/*
АЦП - аналогово-цифровой преобразователь
разрядность 10 бит, от 0 до 1023
Напряжение 0-5В преобразуется в цифровое значение 0-1023


*/
unsigned long g;
float a;
int v;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (millis() - g >= 1000){
    g = millis();
    //a = ((float)analogRead(A3) / 1024.0) * 2000.0; // analogRead() Читает аналоговый вход принимая значение от 0 до 1023
    //Serial.print(a, 3);Serial.println(" Ом");
    v = analogRead(A3);
    v = map(v, 0, 1023, 0, 2000); // Возвращает величину в новом диапозоне. map(value, min, max, minNew, maxNew); value - значение на входе; min, max - диапозон на входе; minNew, maxNew - диапазон на выходе
    v = constrain(v, 0, 2000); // constrain(value, min, max) - ограничить диапозон переменной value до min-max
    if (v>1000){
      Serial.println("ОН ПРЕВЫШАЕТ!!!");
    } else {
      Serial.println("Эх, не превышает :<");
    }

  }
}
