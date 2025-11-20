// 22_GenerateParentheses_medium.cpp
// LeetCode 22. Generate Parentheses (Medium)

#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        function<void(int,int)> dfs = [&](int open,int close){
            if ((int)cur.size()==2*n){ res.push_back(cur); return; }
            if (open<n){ cur.push_back('('); dfs(open+1, close); cur.pop_back(); }
            if (close<open){ cur.push_back(')'); dfs(open, close+1); cur.pop_back(); }
        };
        dfs(0,0);
        return res;
    }
};

int main(){
    Solution sol;
    auto r = sol.generateParenthesis(3);
    for (auto &s: r) cout << s << '\n';
    return 0;
}
