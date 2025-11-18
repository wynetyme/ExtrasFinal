/* LeetCode 46 - Permutations (Medium) */

#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res; vector<int> cur; vector<int> used(nums.size(),0);
    std::function<void()> dfs = [&]{
            if ((int)cur.size() == (int)nums.size()) { res.push_back(cur); return; }
            for (int i=0;i<(int)nums.size();++i) if (!used[i]){ used[i]=1; cur.push_back(nums[i]); dfs(); cur.pop_back(); used[i]=0; }
        };
        dfs(); return res;
    }
};
