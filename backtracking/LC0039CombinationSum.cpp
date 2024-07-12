//
// Created by User on 2024/7/12.
//
#include <iostream>
#include <vector>
#include <fmt/ranges.h>
#include <fmt/core.h>
using namespace std;

/*
 *  2
 *  2 2
 *  2 2 2
 *  2 2 2 2 return
 *  2 2 2 3 return
 *  2 2 2 6 return
 *  2 2 2 7 return
 *  2 2 3 correct
 *  2 2 6 return
 *  2 2 7 return
 *  回溯算法模板
 *  https://blog.csdn.net/zhongzhehua/article/details/126796775
 */

class Solution {
private:
    vector<int> path;
    vector<vector<int> > result;
    void backtracking(vector<int> &candidates, int target, int sum, int startIndex) {
        // 終止條件-超出邊界
        if (sum > target) {
            fmt::print("because sum {} > target {}, return\n", sum, target);
            return;
        }
        // 終止條件-滿足條件
        if (sum == target) {
            fmt::print("because sum {} == target {}, return correct\n", sum, target);
            result.push_back(path);
            return;
        }
        // 遍歷
        for (int i = startIndex; i < candidates.size(); i++) {
            sum = sum + candidates[i];
            path.push_back(candidates[i]);
            fmt::print("int i = {}, value = {}, sum is {}, path = {}\n", i, candidates[i], sum, path);
            backtracking(candidates, target, sum, i);
            // return 完往回退繼續試探
            sum = sum - candidates[i];
            path.pop_back();
            fmt::print("============================\n");
            fmt::print("rollback, path = {}, start to find i = {}\n", path, i+1);
        }
    }

public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    Solution solution;
    vector<vector<int> > result = solution.combinationSum(candidates, target);
    fmt::print("==========================================\n");
    fmt::print("result = {}\n", result);
}
