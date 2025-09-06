#include <iostream>

using namespace std;

class Person {
private:
  string name;
  int age;

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

  return 0;
}
