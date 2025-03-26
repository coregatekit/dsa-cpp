#include <iostream>
#include <string>

using namespace std;

int main() {
  string name;

  cout << "What's your name? ";
  cin >> name;
  cout << "Your name is " << name << endl;

  char firstCharacter = name[0];
  cout << "Your first name character " << firstCharacter << endl;
  return 0;
}
