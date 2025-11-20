// 51_N-Queens_hard.cpp
// LeetCode 51. N-Queens (Hard)

#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> cols(n, -1);
        function<bool(int,int)> ok = [&](int r, int c){
            for (int i=0;i<r;++i){
                if (cols[i]==c) return false;
                if (abs(cols[i]-c)==r-i) return false;
            }
            return true;
        };
        function<void(int)> dfs = [&](int r){
            if (r==n){
                vector<string> board(n, string(n, '.'));
                for (int i=0;i<n;++i) board[i][cols[i]]='Q';
                res.push_back(board);
                return;
            }
            for (int c=0;c<n;++c){
                if (!ok(r,c)) continue;
                cols[r]=c;
                dfs(r+1);
                cols[r]=-1;
            }
        };
        dfs(0);
        return res;
    }
};

int main(){
    Solution sol;
    int n1 = 4;
    auto r1 = sol.solveNQueens(n1);
    cout << "Input: n=4\nOutput:\n";
    for (auto &board: r1){
        for (auto &row: board) cout << row << "\n";
        cout << "---\n";
    }

    int n2 = 1;
    auto r2 = sol.solveNQueens(n2);
    cout << "\nInput: n=1\nOutput:\n";
    for (auto &board: r2){
        for (auto &row: board) cout << row << "\n";
        cout << "---\n";
    }
    return 0;
}
