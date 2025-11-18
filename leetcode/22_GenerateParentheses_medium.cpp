/* LeetCode 22 - Generate Parentheses (Medium) */

#include <vector>
#include <string>
#include <functional>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
    std::function<void(string&,int,int)> dfs = [&](string& cur, int open, int close){
            if ((int)cur.size() == 2*n) { res.push_back(cur); return; }
            if (open < n) { cur.push_back('('); dfs(cur, open+1, close); cur.pop_back(); }
            if (close < open) { cur.push_back(')'); dfs(cur, open, close+1); cur.pop_back(); }
        };
        string cur; dfs(cur,0,0); return res;
    }
};
