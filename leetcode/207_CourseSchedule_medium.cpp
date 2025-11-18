/*
LeetCode 207 - Course Schedule (Medium)

Approach: Detect cycle in directed graph using Kahn's algorithm (topological sort).
Time: O(V+E), Space: O(V+E)
*/

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses, 0);
        vector<vector<int>> g(numCourses);
        for (auto &p : prerequisites) {
            int a = p[0], b = p[1];
            g[b].push_back(a);
            indeg[a]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) if (indeg[i] == 0) q.push(i);
        int seen = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop(); ++seen;
            for (int v : g[u]) {
                if (--indeg[v] == 0) q.push(v);
            }
        }
        return seen == numCourses;
    }
};
