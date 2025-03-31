#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] >= target) {
        return i;
      }
    }

    return nums.size();
  }
};

int main() {
  Solution sol;
  vector<int> input = {1, 3, 5, 6};

  int target = 5;
  int result = sol.searchInsert(input, target);

  cout << "Result: " << result << endl;
  return 0;
}
