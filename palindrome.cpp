#include <iostream>

using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    if (x >= 0 && x <= 9) {
      return true;
    }

    if (x % 10 == 0) {
      return false;
    }

    int newX = 0;
    int tempX = x;

    while (tempX > newX) {
      newX = newX * 10;
      newX = newX + (tempX % 10);
      tempX = tempX / 10;
    }

    if ((tempX == newX) || (tempX == (newX / 10))) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  Solution s;
  int input = 2345432;
  bool isPalindrome = s.isPalindrome(input);

  cout << "Number " << input << " is palindrome? " << isPalindrome << endl;
  return 0;
}
