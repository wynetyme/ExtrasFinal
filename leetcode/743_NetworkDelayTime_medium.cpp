/* LeetCode 743 - Network Delay Time (Medium) */

#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> g(n+1);
        for (auto &t : times) g[t[0]].push_back({t[1], t[2]});
        const int INF = numeric_limits<int>::max()/4;
        vector<int> dist(n+1, INF);
        using P = pair<int,int>; // dist, node
        priority_queue<P, vector<P>, greater<P>> pq;
        dist[k] = 0; pq.push({0,k});
        while (!pq.empty()) {
            auto [d,u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;
            for (auto &e : g[u]) {
                int v = e.first, w = e.second;
                if (dist[v] > d + w) { dist[v] = d + w; pq.push({dist[v], v}); }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INF) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
