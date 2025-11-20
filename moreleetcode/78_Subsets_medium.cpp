// 78_Subsets_medium.cpp
// LeetCode 78. Subsets (Medium)
// Backtracking solution with small test harness.

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> cur;
		function<void(int)> dfs = [&](int i){
			if (i == (int)nums.size()) {
				res.push_back(cur);
				return;
			}
			// exclude
			dfs(i+1);
			// include
			cur.push_back(nums[i]);
			dfs(i+1);
			cur.pop_back();
		};
		dfs(0);
		return res;
	}
};

// Small test harness: runs the example cases from the problem statement.
int main() {
	Solution sol;
	vector<int> a1 = {1,2,3};
	auto r1 = sol.subsets(a1);
	cout << "Input: [1,2,3]\n";
	cout << "Output:\n";
	for (auto &v : r1) {
		cout << "[";
		for (size_t i=0;i<v.size();++i) {
			if (i) cout << ",";
			cout << v[i];
		}
		cout << "]\n";
	}

	vector<int> a2 = {0};
	auto r2 = sol.subsets(a2);
	cout << "\nInput: [0]\nOutput:\n";
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

