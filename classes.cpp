#include <iostream>

using namespace std;

// Encapsulation  คือการป้องกันคุณสมบัติไม่ให้คนอื่นมาเปลี่ยนแปลงค่าได้
// คนที่เปลี่ยนค่าได้คือตัวมันเองเท่านั้น
// ตัวอย่าง private properties
// ถ้าต้องการเปลี่ยนแปลงค่าให้ทำผ่าน setter method
// ถ้าต้องการค่าให้เรียกผ่าน getter method

class Person {
private:
  string name; // private attribute
  int age;     // private attribute

  void showPrivateName() {
    cout << "this is private name: " << (name + name) << endl;
  }

public: // Access specifier
  // Attributes
  // string name;
  // int age;

  // Constructure
  Person(string n, int a) : name(n), age(a) {}

  // Method
  void greet() {
    cout << "Hello, my name is " << name << " and I am " << age << " years old."
         << endl;
    showPrivateName();
  }

  // Getter for the name
  string getName() const { return name; }
  // Setter for the name
  // void setName(string n) { name = n; }

  // Getter for the Age
  int getAge() const { return age; }
  // Setter for the Age
  void setAge(int a) { age = a; }
};

// inheritance คือการสืบถอดคุณสมบัติจากคลาสหนึ่งไปอีกคลาสหนึ่ง
// คลาสที่สืบถอดไป สามารถใช้คุณสมบัติของคลาสหลักได้

class Vehicle {
protected: // protected คือตัวแปรที่เป็น private แต่สามารถสืบทอดได้
  string brand;

public:
  Vehicle(string b) : brand(b) {}

  void honk() const { cout << "Beep beep! This is a " << brand << ".\n"; }
};

// Derived class
class Car : public Vehicle {
private:
  string model;

public:
  Car(string b, string m) : Vehicle(b) { model = m; } // Constructure

  void showModel() const {
    cout << "It is a " << model << "and brand " << brand << ".\n";
  }
};

int main() {
  // Creating an object of ther Person class
  Person person1("Alice", 30);
  // Calling a method of the object
  person1.greet();

  // cout << person1.name << endl;

  Person person2("Mike", 24);
  person2.greet();

  // Modifiy the student name and age
  // person2.setName("Aeri");
  person2.setAge(21);
  person2.greet();

  Car myCar("Toyota", "Corolla");
  myCar.honk();
  myCar.showModel();
  return 0;
}
