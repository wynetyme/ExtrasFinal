/* LeetCode 79 - Word Search (Medium) */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i=0;i<m;++i) for (int j=0;j<n;++j) if (board[i][j]==word[0]) {
            if (dfs(board, i, j, word, 0)) return true;
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& b, int i, int j, const string& w, int idx) {
        if (idx == (int)w.size()) return true;
        int m=b.size(), n=b[0].size();
        if (i<0||i>=m||j<0||j>=n||b[i][j]!=w[idx]) return false;
        char tmp=b[i][j]; b[i][j] = '#';
        bool ok = dfs(b,i+1,j,w,idx+1)||dfs(b,i-1,j,w,idx+1)||dfs(b,i,j+1,w,idx+1)||dfs(b,i,j-1,w,idx+1);
        b[i][j]=tmp; return ok;
    }
};
