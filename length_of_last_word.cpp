#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    vector<string> words;
    stringstream ss(s);
    string word;

    while (ss >> word) {
      words.push_back(word);
    }
    
    return words.empty() ? 0 : words.end()[-1].length();
  }
};

int main() {
  Solution sol;

  cout << "Result: " << sol.lengthOfLastWord("Hello World") << endl;
  cout << "Result: " << sol.lengthOfLastWord("   fly me   to   the moon  ")
       << endl;
  cout << "Result: " << sol.lengthOfLastWord("luffy is still joyboy") << endl;

  return 0;
}
