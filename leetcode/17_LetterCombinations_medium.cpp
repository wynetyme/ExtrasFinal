/* LeetCode 17 - Letter Combinations of a Phone Number (Medium) */

#include <vector>
#include <string>
#include <functional>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> map = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
    std::function<void(int,string&)> dfs = [&](int idx, string& cur){
            if (idx == (int)digits.size()) { res.push_back(cur); return; }
            string letters = map[digits[idx]-'0'];
            for (char c: letters) { cur.push_back(c); dfs(idx+1,cur); cur.pop_back(); }
        };
        string cur; dfs(0,cur); return res;
    }
};
