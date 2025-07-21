#include <string.h>
#include <avr/pgmspace.h>
#include <Printable.h>

/*
ООП - объектно-ориентированное программирование
У ООП есть 3 базовы принципа:
Инкапсуляция
Наследование
Полиморфизм

Инкапсуляция - это хранение данных и методов для работы с этими данными вместе.
Наследование - последующие классы могут наследовать методы работы предыдущих классов.

*/

const char* color_array[6] = {"чёрный", "белый", "зелёный", "коричневый", "синий", "красный"};
const char* permission_array[3] = {"проб. ВИП", "ВИП", "Супер ВИП"};

class Hat : public Printable { //class <имя класса> {} - класс, содержит в себе данные и методы для работы с этими данными вместе
public: //public - указывает, что все переменные ниже публичные и могу использоваться в функциях, без указания по умолчанию в классе все переменные приватные и доступны только в классе 
  friend void printHat(const Hat &hat); //friend означает, что данная функция имеет доступ к private

  enum color_t : uint8_t {BLACK, WHITE, GREEN, BROWN, BLUE, RED};
  static const uint8_t STRLEN = 30;

  Hat(const __FlashStringHelper *name, color_t color, uint8_t count); //методы работы
  //Hat(const __FlashStringHelper *name, color_t color, uint8_t count); - это конструктор, он конструирует класс в коде и какие условия нужны для конструирования 
  virtual ~Hat() {
    say(F("Hat::~Hat"));
    --_hats;
  }

  const char *getName() const { //геттер
    return _name;
  }

  color_t getColor() const {
    return _color;
  }

  uint8_t getCount() const {
    return _count;
  }

  static uint8_t getHats() {
    return _hats;
  }

  void setName(const __FlashStringHelper *value); //сеттер

  void setColor(color_t color) {
    _color = color;
  }

  void setCount(uint8_t count) {
    _count = count;
  }
  /*
  virtual указывает на то, что при объявлении нового класса будет использоваться 
  вариант нового класса, а не этого, если именно был применён конструктор нового 
  класса, если старого то будет использвана функция данного класса.
  virtual передаётся последующим классам и не нуждается в прописке у каждого
  последующего класса.
  */

  virtual size_t printTo(Print &p) const;
  virtual void print();

protected: //К нему могут обращаться производные класса, но к нему не могут обращаться извне.
  void say(const __FlashStringHelper *str) {
    Serial.println(str);
  }

private: //private - указывает, что все св-ва ниже приватные и доступны только в классе
  uint8_t _count : 5; //св-ва (хранимые данные)
  char _name[STRLEN];
  color_t _color : 3;
  static uint8_t _hats;
};

uint8_t Hat::_hats = 0;

/*
Всё что было в классе Hat public и protected останется таковым. Если написать 
protected, то все public из Hat в этом классе станут protected, и если написать 
private, то всё станет private в классе Cylinders.
*/

class Permission : public Hat {
public:
  enum permission_t : uint8_t {FREE_VIP, VIP, SUPER_VIP};

  Permission(const __FlashStringHelper *name, color_t color, uint8_t count, permission_t permission);

  ~Permission() {
    say(F("Permssion::~Permssion"));
  }

  permission_t getPermission() const {
    return _permission;
  }

  void setPermission(permission_t permission) {
    _permission = permission;
  }

  size_t printTo(Print &p) const;
  void print();

private:
  permission_t _permission;
};

Hat::Hat(const __FlashStringHelper *name, color_t color, uint8_t count) {
  say(F("Hat::Hat"));
  setName(name);
  setColor(color);
  setCount(count);
  ++_hats;
}

void Hat::print() {
  Serial.print(_name);
  Serial.print(F(": "));
  Serial.print(_count);
  Serial.println(F("шт."));
  Serial.print(F("Цвет: "));
  for (uint8_t i = 0; i < 6; i++) {
    if (_color == i){
      Serial.println(color_array[i]);
    }
  }
}

void Hat::setName(const __FlashStringHelper *value) {
  if (value && pgm_read_byte(value)){
    strncpy_P(_name, (PGM_P)value, sizeof(_name) - 1);
    _name[sizeof(_name) - 1] = '\0';
  } else {
    _name[0] = '\0';
  }
}

Permission::Permission(const __FlashStringHelper *name, color_t color, uint8_t count, permission_t permission) : Hat(name, color, count) {
  say(F("Permssion::Permssion"));
  setPermission(permission);
}

void Permission::print() {
  Hat::print();
  Serial.print(F("Привилегия: "));
  for (uint8_t i = 0; i < 3; i++) {
    if (_permission == i) {
      Serial.println(permission_array[i]);
    }
  }
}

void printHat(const Hat &hat) {
  Serial.print(hat._name);
  Serial.print(F(": "));
  Serial.print(hat._count);
  Serial.println(F("шт."));
  Serial.print(F("Цвет: "));
  for (uint8_t i = 0; i < 6; i++) {
    if (hat._color == i){
      Serial.println(color_array[i]);
    }
  }
}

size_t Hat::printTo(Print &p) const {
  size_t result;

  result = p.print(_name);
  result += p.print(F(": "));
  result += p.print(_count);
  result += p.print(F("шт."));
  result += p.print(F(" Цвет: "));
  for (uint8_t i = 0; i < 6; i++) {
    if (_color == i){
      result += p.print(color_array[i]);
    }
  }
  return result;
}

size_t Permission::printTo(Print &p) const {
  size_t result;

  Hat::printTo(p);
  result += p.print(F(" Привилегия: "));
  for (uint8_t i = 0; i < 3; i++) {
    if (_permission == i) {
      result += p.print(permission_array[i]);
    }
  }
  return result;
}

void setup() {
  Serial.begin(9600);

  Hat *cowboy = new Hat(F("Ковбойская"), Hat::RED, 24);
  Hat *gerczog = new Permission(F("Герцогская"), Hat::GREEN, 31, Permission::VIP);

  Serial.println(cowboy->getHats());
  cowboy->print();
  Serial.println(*cowboy);
  cowboy->setName(F("Абоба"));
  cowboy->setCount(4);
  cowboy->setColor(Hat::BROWN);
  Serial.println(cowboy->getName());
  Serial.println(cowboy->getCount());
  Serial.println(cowboy->getColor());
  gerczog->print();
  Serial.println(*gerczog);
  //cowboy->say(F("bababuy")); - так НИЗЯ say у нас protected
  //Serial.println(cowboy->_name); - так НИЗЯ _name у нас private
  printHat(*cowboy);
  delete gerczog;
  delete cowboy;
  Serial.println(Hat::getHats());
}

void loop() {}