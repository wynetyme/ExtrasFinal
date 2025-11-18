/* LeetCode 78 - Subsets (Medium) */

#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res; vector<int> cur;
    std::function<void(int)> dfs = [&](int idx){
            if (idx == (int)nums.size()) { res.push_back(cur); return; }
            dfs(idx+1);
            cur.push_back(nums[idx]); dfs(idx+1); cur.pop_back();
        };
        dfs(0); return res;
    }
};
