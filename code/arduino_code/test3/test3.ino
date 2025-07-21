int i = 1;
unsigned long a;
int b = 1;

void setup() {
  Serial.begin(9600);
  delay(1); //Задержка между операциями, 1 = 1 миллисекунде. Макс. значение 4 294 967 295 = 50 суткам или 1200 часам
  for(i; i<=1000; i++){ //Цикл for, про него потом, это я так, от себя.
    delayMicroseconds(1000); //Задержка в микросекундах или 10^-6с. Макс. значение 16383мкс или 16мс, чуть больше
    if (i % 100 == 0) { //% -деление по модулю, т.е. деление без остатка
      Serial.print(i);Serial.println("мкс");
    }
  }
  Serial.print((float)millis()/1000, 3);Serial.println("с"); //millis() - возвращает время работы контроллера. Макс. значение 4 294 967 295, считает только миллисикунды.
  Serial.print((float)micros()/1000000, 6);Serial.println("с"); //micros() - возвращает время работы контроллера. Макс. значение 4 294 967 295мкс - 70мин, считает только по 4мкс.
}

void loop() {
  if (millis() - a >= 1000) { //Счётчик, полноценная замена delay без задержек!
    a = millis();
    Serial.print(b);Serial.println("с");
    //Serial.print((float)millis()/1000, 3);Serial.println("с");
    b++;
  }
  if (round(millis()/5000) % 2 == 0) { //Счётчик с переключением. В данном случае, каждые 5 секунд идёт переключение
    Serial.println("aboba");
  } else {
    Serial.println("obabo");
  }

}
