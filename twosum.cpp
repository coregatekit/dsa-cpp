#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    int x, y = 0;
    for (int i = 0; i < nums.size(); i++) {
      x = nums[i];

      for (int j = 0; j < nums.size(); j++) {
        y = nums[j];

        if (i != j && x + y == target) {
          return {i, j};
        }
      }
    }
    return {};
  }
};

int main() {
  Solution s;
  vector<int> input = {2, 7, 11, 15};
  int target = 9;
  vector<int> result = s.twoSum(input, target);

  cout << result[0] << "," << result[1];
  return 0;
}
