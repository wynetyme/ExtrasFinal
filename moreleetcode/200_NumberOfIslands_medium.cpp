// 200_NumberOfIslands_medium.cpp
// LeetCode 200 - Number of Islands (medium)

#include <bits/stdc++.h>
using namespace std;

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    if (m==0) return 0;
    int n = grid[0].size();
    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                ans++;
                queue<pair<int,int>>q; q.push({i,j});
                grid[i][j]='0';
                int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
                while(!q.empty()){
                    auto [r,c]=q.front(); q.pop();
                    for(auto &d:dirs){
                        int nr=r+d[0], nc=c+d[1];
                        if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1'){
                            grid[nr][nc]='0';
                            q.push({nr,nc});
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<char>> g = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << numIslands(g) << "\n"; // expected 3
    return 0;
}
