int x = 0;
long i;

void setup() {
  Serial.begin(9600);
  boolean b = true;
  int a = 1;
  //if () {} для создания алгоритмов. if - если, что-то произойдёт, то оно выполнится. () - условие(я) выполнения конструкции. {} - там где пишутся команды для выполнения.
  //Если условие будет равно true, то конструкция выполниться. К примеру, если подать в условие лог. единицу, или если 0 == 0, или если 0 != 1, или если a < 0 and b > 1
  if (0 != 1 && a > 0) { //Если 0 не равно 1 и а больше 0 то вывести ba
    Serial.println("true1");
  }

  if (!b == 0) { //если !b true равно false то написать true
    Serial.println("true2");
  }

  /*
  Операторы:
  && - логическое и
  || - логическое или
  ! - отрицание (если !val равно false в переменной, то отрицая мы получаем true)
  */

  if (x == 1) {
    Serial.println("X - равен единице");
  } else { //else {} - иначе, если if == false, то выполняем else, if и else являются цельной конструкцией, в else можно прописать if
    Serial.println("X - не равен единице");
    if (b == 1){
      Serial.println("И то верно!");
    }
  }

}

void loop() {
  if (Serial.available()) {
    i = Serial.parseInt();
    if (i >= 500 && i <= 1000) {
      Serial.println("А ты хорош!");
    } else if (i < 500 || i > 1000 && i <= 35767 && i >= -35768) {
      Serial.println("Сойдёт! В следующий раз получится!");
    } else {
      Serial.println("Ну куда ты вышел за пределы int?!");
    }
    //Так-же есть рассмотр переменной с помощью switch. case вместо равно, т.е. если i (switch (i)) == (case) 1 то что-то выполнить, else (default). break - прерывает рассмотр переменной i
    switch (i) {
      case 1: Serial.println("1");
        break;
      case 2: Serial.println("2");
        break;
      case 3: Serial.println("3");
        break;
      default: break;
    }
  }
}
