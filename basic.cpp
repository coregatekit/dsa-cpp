#include <iostream>

using namespace std;

int main() {
  int count = 0;

  cout << "=== While Loop ===\n";
  while (count < 10) {
    cout << "Count = " << count << endl;
    count += 1;
  }

  cout << "=== For Loop ===\n";
  for (int i = 0; i < 10; i++) {
    cout << "Count = " << i << endl;
  }

  cout << "=== Do While Loop ===\n";
  int c = 0;
  do {
    cout << "Count = " << c << endl;
    c += 1;
  } while (c < 10);

  return 0;
}
