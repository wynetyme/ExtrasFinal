// 37_SudokuSolver_hard.cpp
// LeetCode 37. Sudoku Solver (Hard)

#include <iostream>
#include <vector>
#include <array>
#include <functional>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        array<int,9> row{}; row.fill(0);
        array<int,9> col{}; col.fill(0);
        array<int,9> box{}; box.fill(0);
        vector<pair<int,int>> empties;
        for (int r=0;r<9;++r){
            for (int c=0;c<9;++c){
                if (board[r][c]=='.') { empties.emplace_back(r,c); continue; }
                int v = board[r][c]-'1';
                int b = (r/3)*3 + c/3;
                row[r] |= 1<<v;
                col[c] |= 1<<v;
                box[b] |= 1<<v;
            }
        }
        function<bool(int)> dfs = [&](int idx){
            if (idx==(int)empties.size()) return true;
            auto [r,c]=empties[idx];
            int b = (r/3)*3 + c/3;
            int used = row[r] | col[c] | box[b];
            for (int v=0;v<9;++v){
                if (used & (1<<v)) continue;
                board[r][c] = char('1'+v);
                row[r] |= 1<<v; col[c] |= 1<<v; box[b] |= 1<<v;
                if (dfs(idx+1)) return true;
                row[r] &= ~(1<<v); col[c] &= ~(1<<v); box[b] &= ~(1<<v);
                board[r][c]='.';
            }
            return false;
        };
        dfs(0);
    }
};

int main(){
    Solution sol;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    sol.solveSudoku(board);
    cout << "Solved board:\n";
    for (auto &r: board){
        for (char c: r) cout << c << ' ';
        cout << '\n';
    }
    return 0;
}
