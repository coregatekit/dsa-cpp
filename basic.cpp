#include <iostream>

using namespace std;

int main() {
  int age;
  cout << "How old are you? ";
  cin >> age;

  if (age >= 18 && age <= 60) {
    cout << "You are over 18 pass the criteria.\n";
  } else if (age > 60) {
    cout << "You are over 60 over the criteria.\n";
  } else {
    cout << "You are under 18.\n";
  }

  return 0;
}
