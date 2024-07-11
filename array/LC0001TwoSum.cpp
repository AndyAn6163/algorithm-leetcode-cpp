//
// Created by User on 2024/7/8.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        // 0 1 -> 0 2 -> 0 3
        // 1 2 -> 1 3
        // 2 3
        // 外層 for 只到 0 1 2，最後一個值不計入
        // 內層 for 從外層開始算到最大值
        for (int i = 0; i < nums.size() - 1; i++) {
            cout << "i = " << i << " ,value = " << nums[i] << endl;
            for (int j = i + 1; j < nums.size(); j++) {
                cout << "j = " << j << " ,value = " << nums[j] << endl;
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
            cout << "====================" << endl;
        }
        return {};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    Solution solution;
    solution.twoSum(nums, 22);
}
