boolean button = 0;
boolean led_flag = 0;

byte led_state;

unsigned long millis1;
unsigned long hold_button;
unsigned long index;

void setup() {
  pinMode(6, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  //Serial.begin(9600);
}

void loop() {
  boolean button_state = !digitalRead(6);
  if (millis() - millis1 >= 10){
    millis1 = millis();
    if (button_state == 1 && button == 0) {
      button = 1;
      led_flag = !led_flag;
      hold_button = millis();
      digitalWrite(13, led_flag);
      if (led_flag == 1){
        while (led_flag == 1) {
          if (millis() - millis1 >= 100){
            millis1 = millis();
            index++;
            
            switch (led_state){
              case 0: digitalWrite(2, 1);
                led_state++;
                break;
              case 1: digitalWrite(4, 1);
                led_state++;
                break;
              case 2: digitalWrite(5, 1);
                led_state++;
                break;
              case 3: digitalWrite(2, 0);
                led_state++;
                break;
              case 4: digitalWrite(4, 0);
                led_state++;
                break;
              case 5: digitalWrite(5, 0);
                led_state = 0;
                break;
              default: led_state = 0;
                break;
            }
            
            /*
            for(int d = 2; d < 6; d++){
              if (d == 2) {
                digitalWrite(d, 1);
              }
              if (d == 5 || d == 4){
                digitalWrite(d, 1);
              }
              delay(100);
            }
            for(int d = 2; d < 6; d++){
              if (d == 2) {
                digitalWrite(d, 0);
              }
              if (d == 5 || d == 4){
                digitalWrite(d, 0);
              }
              delay(100);
            }
            */
            if (!digitalRead(6) == 1){
              hold_button += 300;
              if (!digitalRead(6) == 1 && hold_button > millis() + 1000){ 
                digitalWrite(2, 0);
                digitalWrite(4, 0);
                digitalWrite(5, 0);

                led_flag = 0;
                digitalWrite(13, led_flag);
                index = 0;
                break;
              }
            }  

            /*
            if (index == 10000) {
              digitalWrite(2, 0);
              digitalWrite(4, 0);
              digitalWrite(5, 0);

              led_flag = 0;
              digitalWrite(13, led_flag);
              index = 0;
              break;
            }
            */

            if (index % 60 == 0){
              hold_button = millis();
              //Serial.println(hold_button);
            }
          }
        }
      }  
    } else if (button_state == 0 && button == 1) {
      button = 0;
    }
  }
}
