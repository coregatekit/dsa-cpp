#include <iostream>
#include <iterator>

using namespace std;

class Solution {
public:
  int romanValue(char r) {
    switch (r) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
    }
    return -1;
  }

  int romanToInt(string s) {
    int sumRoman = 0;
    for (int i = 0; i < s.length(); i++) {
      int current = romanValue(s[i]);
      int nextValue = 0;

      if (i + 1 < s.length()) {
        nextValue = romanValue(s[i + 1]);
      }
      if (current < nextValue) {
        sumRoman -= current;
      } else {
        sumRoman += current;
      }
    }
    return sumRoman;
  }
};

int main() {
  Solution sol;
  string input = "III";
  string input2 = "LVIII";
  string input3 = "MCMXCIV";

  int result = sol.romanToInt(input);
  int result2 = sol.romanToInt(input2);
  int result3 = sol.romanToInt(input3);

  cout << "Result: " << result << endl;
  cout << "Result: " << result2 << endl;
  cout << "Result: " << result3 << endl;

  return 0;
}
