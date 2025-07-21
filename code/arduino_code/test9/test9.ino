/*
random(min, max) - генерирует случайное число от min до max-1;
random(max) - от 0 до max-1;
randomSeed(value) - функция задающая начало отсчёта генератору псевдослучайных чисел

Serial.write() - написать символ ASCII
*/

void setup() {
  // put your setup code here, to run once:
  randomSeed(analogRead(A3));
  pinMode(3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(3, 1);
  delay(random(analogRead(A3))*10);
  digitalWrite(3, 0);
  delay(random(analogRead(A3))*10);
}
