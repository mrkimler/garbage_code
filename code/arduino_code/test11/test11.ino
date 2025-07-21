/*
Прерывание - считывает состояния пина не зависимо от кода, его нахождения и всегда реагирует на его состояние.

attachInterrupt(pin, function, mode); - подключить прерывание; dettachInterrupt(pim) - отключить прерывание;
function - функция, которую мы вызываем при срабатывании
mode - условие срабатывания
Условия срабатывания:
LOW - срабатывает, когда на пине LOW;
RISING - срабатывает, когда пин переходит и 0 на 1;
FALLING - против. RISING;
CHANGE - срабатывает и при падении и при повышении сигнала;

noInterrupts(); - приостановить обработку прерываний
interrupts(); - продолжить обработку прерываний
*/
volatile boolean f; //чтобы менять переменную в функции прерывания, она должна иметь аттрибут volatile
volatile unsigned long k;
unsigned long g;

void first_interrupt(){
  f = 1;
  k = millis();
  //millis(); не изменяется в функции прерывания
  //delay(); не работает в функции прерывания
}

void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(1, first_interrupt, FALLING);

}

void loop() {
  if (f == 1 && millis()-g>50){
    g = millis();
    Serial.print("INTERRUPT!!! ");
    Serial.println(k);
    f = 0;
  }
}
