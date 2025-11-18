/* LeetCode 39 - Combination Sum (Medium) */

#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res; vector<int> cur;
        sort(candidates.begin(), candidates.end());
    std::function<void(int,int)> dfs = [&](int idx, int sum){
            if (sum == target) { res.push_back(cur); return; }
            if (sum > target) return;
            for (int i = idx; i < (int)candidates.size(); ++i) {
                cur.push_back(candidates[i]); dfs(i, sum + candidates[i]); cur.pop_back();
            }
        };
        dfs(0,0); return res;
    }
};
