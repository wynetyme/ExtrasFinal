// 22_GenerateParentheses_medium.cpp
// LeetCode 22 - Generate Parentheses (medium)

#include <bits/stdc++.h>
using namespace std;

vector<string> generateParenthesis(int n) {
    vector<string> res;
    function<void(string,int,int)> dfs = [&](string s,int open,int close){
        if((int)s.size()==2*n){ res.push_back(s); return; }
        if(open<n) dfs(s+"(", open+1, close);
        if(close<open) dfs(s+")", open, close+1);
    };
    dfs("",0,0);
    return res;
}

int main(){
    auto v = generateParenthesis(3);
    for(auto &s: v) cout<<s<<"\n";
    return 0;
}
