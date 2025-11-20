// 1091_ShortestPathBinaryMatrix_medium.cpp
// LeetCode 1091 - Shortest Path in Binary Matrix (medium)
// Minimal solution with a small smoke test in main.

#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n==0 || grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    queue<pair<int,int>> q;
    dist[0][0]=1;
    q.push({0,0});
    int dirs[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    while(!q.empty()){
        auto [r,c]=q.front(); q.pop();
        if (r==n-1 && c==n-1) return dist[r][c];
        for(auto &d:dirs){
            int nr=r+d[0], nc=c+d[1];
            if (nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && dist[nr][nc]==INT_MAX){
                dist[nr][nc]=dist[r][c]+1;
                q.push({nr,nc});
            }
        }
    }
    return -1;
}

int main(){
    vector<vector<int>> g = {{0,1},{1,0}}; // answer: 2
    cout << shortestPathBinaryMatrix(g) << "\n";
    return 0;
}
