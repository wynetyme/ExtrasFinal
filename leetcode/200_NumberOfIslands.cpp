/* LeetCode 200 - Number of Islands (Medium) */

#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return count;
    }

private:
    void dfs(vector<vector<char>>& g, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (g[i][j] != '1') return;
        g[i][j] = '0';
        dfs(g, i+1, j, m, n);
        dfs(g, i-1, j, m, n);
        dfs(g, i, j+1, m, n);
        dfs(g, i, j-1, m, n);
    }
};
