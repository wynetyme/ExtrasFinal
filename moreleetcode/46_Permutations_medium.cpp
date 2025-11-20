// 46_Permutations_medium.cpp
// LeetCode 46. Permutations (Medium)
// Backtracking solution with small test harness.

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> cur;
		vector<char> used(nums.size(), 0);
		function<void()> dfs = [&]() {
			if (cur.size() == nums.size()) {
				res.push_back(cur);
				return;
			}
			for (size_t i=0;i<nums.size();++i) {
				if (used[i]) continue;
				used[i] = 1;
				cur.push_back(nums[i]);
				dfs();
				cur.pop_back();
				used[i] = 0;
			}
		};
		dfs();
		return res;
	}
};

int main() {
	Solution sol;
	vector<int> a1 = {1,2,3};
	auto r1 = sol.permute(a1);
	cout << "Input: [1,2,3]\nOutput:\n";
	for (auto &v : r1) {
		cout << "[";
		for (size_t i=0;i<v.size();++i) {
			if (i) cout << ",";
			cout << v[i];
		}
		cout << "]\n";
	}

	vector<int> a2 = {0,1};
	auto r2 = sol.permute(a2);
	cout << "\nInput: [0,1]\nOutput:\n";
	for (auto &v : r2) {
		cout << "[";
		for (size_t i=0;i<v.size();++i) {
			if (i) cout << ",";
			cout << v[i];
		}
		cout << "]\n";
	}
	return 0;
}

