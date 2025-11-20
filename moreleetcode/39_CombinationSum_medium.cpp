// 39_CombinationSum_medium.cpp
// LeetCode 39. Combination Sum (Medium)

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        function<void(int,int)> dfs = [&](int i, int remain){
            if (remain == 0) {
                res.push_back(cur);
                return;
            }
            if (i >= (int)candidates.size() || remain < candidates[i]) return;
            // take current candidate multiple times
            // try using candidates[i] k times
            // option 1: skip
            dfs(i+1, remain);
            // option 2: take one and stay at i
            cur.push_back(candidates[i]);
            dfs(i, remain - candidates[i]);
            cur.pop_back();
        };
        dfs(0, target);
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> cand1 = {2,3,6,7};
    auto r1 = sol.combinationSum(cand1, 7);
    cout << "Input: [2,3,6,7], target=7\nOutput:\n";
    for (auto &v: r1) {
        cout << "[";
        for (size_t i=0;i<v.size();++i){ if (i) cout << ","; cout << v[i]; }
        cout << "]\n";
    }

    vector<int> cand2 = {2,3,5};
    auto r2 = sol.combinationSum(cand2, 8);
    cout << "\nInput: [2,3,5], target=8\nOutput:\n";
    for (auto &v: r2) {
        cout << "[";
        for (size_t i=0;i<v.size();++i){ if (i) cout << ","; cout << v[i]; }
        cout << "]\n";
    }
    return 0;
}
