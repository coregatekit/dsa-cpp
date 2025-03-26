#include <iostream>

using namespace std;

int main() {
  int ages[2];
  int sumAge;

  cout << "Please enter the 1st person age: ";
  cin >> ages[0];

  cout << "Please enter the 2nd person age: ";
  cin >> ages[1];

  sumAge = ages[0] + ages[1];

  cout << "The sum of age is " << sumAge << endl;

  return 0;
}
