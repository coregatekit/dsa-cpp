#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    map<int, int> counts;

    for (int i = 0; i < nums.size(); i++) {
      if (counts.find(nums[i]) == counts.end()) {
        counts.insert(make_pair(nums[i], 1));
      } else {
        counts[nums[i]]++;
      }
    }

    int result = 0;
    for (auto it = counts.begin(); it != counts.end(); ++it) {
      cout << it->first << " is " << it->second << endl;
      if (it->second < 2) {
        result = it->first;
      }
    }

    return result;
  }
};

int main() {
  Solution sol;
  vector<int> input = {4, 1, 2, 1, 2};

  int result = sol.singleNumber(input);
  cout << "The result: " << result << endl;

  return 0;
}
