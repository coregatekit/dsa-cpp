#include <cmath>
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

// abstraction class คือการสร้างคลาสต้นแบบเมื่อมีตนเรียกใช้
// คลาสนั้นจะต้อง implement ตามคลาสต้นแบบนั้นๆ แต่เนื้อหาข้างในอาจจะต่างกันไป

// keyword virtual ใช้สำหรับบอกว่า ตัวแปรหรือฟังก์ชันนั้นจะถูก override ได้

// Abstract base class
class Shape {
public:
  // Pure virtual function
  virtual double
  calculateArea() const = 0; // No implementation must be override

  // Virtual destructure for safe polymorphic use
  // มันจะ clear memory เมื่อมีการลบ instance นี้ออกไป
  virtual ~Shape() {}
};

// Derived class
class Circle : public Shape {
private:
  double radius;

public:
  Circle(double r) : radius(r) {}

  double calculateArea() const override {
    return M_PI * radius * radius; // implement for circle area
  }
};

// Another derived class
class Rectangle : public Shape {
private:
  double length, width;

public:
  Rectangle(double l, double w) : length(l), width(w) {}

  double calculateArea() const override {
    return length * width; // implement for rectangle area
  }
};

// another example
class Base {
public:
  virtual void show() const { // Virtual function
    cout << "Base show" << endl;
  }

  virtual ~Base() {} // Virtual destructure
};

class Derived : public Base {
public:
  void show() const override { // Override base class function
    cout << "Derived show" << endl;
  }
};

void callShow(const Base &obj) {
  obj.show(); // Dynamic binding happens here
}

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

  Circle circle(5);
  Rectangle rectangle(10, 20);

  cout << "Circle area: " << circle.calculateArea() << endl;
  cout << "Rectangle area: " << rectangle.calculateArea() << endl;

  Base base;
  Derived derived;

  callShow(base);
  callShow(derived);
  return 0;
}
