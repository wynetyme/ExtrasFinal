// 79_WordSearch_medium.cpp
// LeetCode 79. Word Search (Medium)

#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int R = board.size();
        if (R==0) return false;
        int C = board[0].size();
        vector<vector<char>> b = board;
        function<bool(int,int,int)> dfs = [&](int r,int c,int idx){
            if (idx==(int)word.size()) return true;
            if (r<0||r>=R||c<0||c>=C) return false;
            if (b[r][c]!=word[idx]) return false;
            char saved = b[r][c]; b[r][c] = '#';
            bool ok = dfs(r+1,c,idx+1)||dfs(r-1,c,idx+1)||dfs(r,c+1,idx+1)||dfs(r,c-1,idx+1);
            b[r][c] = saved;
            return ok;
        };
        for (int r=0;r<R;++r) for (int c=0;c<C;++c) if (board[r][c]==word[0]) if (dfs(r,c,0)) return true;
        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << boolalpha << sol.exist(board, string("ABCCED")) << '\n'; // true
    cout << boolalpha << sol.exist(board, string("SEE")) << '\n'; // true
    cout << boolalpha << sol.exist(board, string("ABCB")) << '\n'; // false
    return 0;
}
