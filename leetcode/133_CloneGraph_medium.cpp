/* LeetCode 133 - Clone Graph (Medium) */

#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0), neighbors(vector<Node*>()) {}
    Node(int _val) : val(_val), neighbors(vector<Node*>()) {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> m;
        return dfs(node, m);
    }
private:
    Node* dfs(Node* u, unordered_map<Node*, Node*>& m) {
        if (m.count(u)) return m[u];
        Node* copy = new Node(u->val);
        m[u] = copy;
        for (Node* v : u->neighbors) copy->neighbors.push_back(dfs(v, m));
        return copy;
    }
};
