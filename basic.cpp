#include <iostream>
#include <string>

using namespace std;

int main() {
  int ages[5];
  int sumAge = 0;

  for (int i = 0; i < 5; i++) {
    cout << "person no " << (i + 1) << ": ";
    cin >> ages[i];
    sumAge += ages[i];
  }

  cout << "Sum of ages 5 person = " << sumAge << endl;

  for (int i = 0; i < 5; i++) {
    cout << "The age of person no" << (i + 1) << "is " << ages[i] << endl;
  }

  string name;
  cout << "What's your name? ";
  cin >> name;

  cout << "Your name is " << name << endl;

  for (int i = 0; i < name.length(); i++) {
    cout << "character no " << (i + 1) << " is " << name[i] << endl;
  }

  return 0;
}
