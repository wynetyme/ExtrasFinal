// 17_LetterCombinations_medium.cpp
// LeetCode 17. Letter Combinations of a Phone Number (Medium)

#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        static const vector<string> M = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        string cur;
        function<void(int)> dfs = [&](int i){
            if (i==(int)digits.size()){ res.push_back(cur); return; }
            int d = digits[i]-'0';
            for (char ch: M[d]){ cur.push_back(ch); dfs(i+1); cur.pop_back(); }
        };
        dfs(0);
        return res;
    }
};

int main(){
    Solution sol;
    auto r = sol.letterCombinations("23");
    for (auto &s: r) cout << s << '\n';
    return 0;
}
