#include <iostream>
#include <string>

using namespace std;

void greet() { cout << "Hello Gieselle" << endl; }
string hi() { return "Hello Karina"; }
int add(int a, int b) { return a + b; }
float areaOfCircle(float radius) { return 3.14159265359 * 0.5 * radius; }

int main() {
  greet();
  string helloKarina = hi();
  cout << helloKarina << endl;

  int sumNumber = add(3, 5);
  cout << sumNumber << endl;

  float areaCircle = areaOfCircle(3);
  cout << areaCircle << endl;
  return 0;
}
