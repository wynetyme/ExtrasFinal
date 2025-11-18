/* LeetCode 127 - Word Ladder (Hard) */

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        unordered_set<string> seen;
        seen.insert(beginWord);
        while (!q.empty()) {
            auto [w, d] = q.front(); q.pop();
            if (w == endWord) return d;
            for (int i = 0; i < (int)w.size(); ++i) {
                string t = w;
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == w[i]) continue;
                    t[i] = c;
                    if (dict.count(t) && !seen.count(t)) {
                        seen.insert(t);
                        q.push({t, d+1});
                    }
                }
            }
        }
        return 0;
    }
};
