/* LeetCode 1091 - Shortest Path in Binary Matrix (Medium) */

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return -1;
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1; // use grid for distance
        while (!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            int d = grid[r][c];
            if (r == n-1 && c == n-1) return d;
            for (auto &dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0) {
                    grid[nr][nc] = d + 1;
                    q.push({nr,nc});
                }
            }
        }
        return -1;
    }
};
