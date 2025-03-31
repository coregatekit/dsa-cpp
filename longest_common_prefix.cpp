#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string prefix = "";

    for (int i = 0; i < strs[0].length(); i++) {
      char check = strs[0][i];
      for (int j = 1; strs.size(); j++) {
        if (check != strs[i][j]) {
          return prefix;
        }
      }
      prefix += check;
    }

    return prefix;
  }
};

int main() {
  Solution sol;
  vector<string> input = {"flower", "flow", "flight"};
  vector<string> input2 = {"dog", "racecar", "car"};

  string result = sol.longestCommonPrefix(input);
  string result2 = sol.longestCommonPrefix(input2);

  cout << "Result: " << result << endl;
  cout << "Result: " << result2 << endl;

  return 0;
}
