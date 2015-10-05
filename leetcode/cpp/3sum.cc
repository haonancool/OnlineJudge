#include <iostream>
#include <vector>
#include <algorithm>

using std::cout; using std::cin; using std::endl;
using std::vector;
using std::sort;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		if (nums.size() < 3)
			return ret;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++) {
			int j = i + 1, k = nums.size() - 1;
			// avoid duplicate solutions
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			while (j < k) {
				int sum = nums[i] + nums[j] + nums[k];
				if (sum == 0) {
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[j]);
					temp.push_back(nums[k]);
					ret.push_back(temp);
					j++;
					while (j < k && nums[j - 1] == nums[j])
						j++;
					k--;
					while (j < k && nums[k] == nums[k + 1])
						k--;
				} else if (sum < 0) {
					j++;
				} else {
					k--;
				}
			}
		}
		return ret;
	}
};

int main() {
	Solution sol;
	vector<int> nums;
	int n = 0;
	while (cin >> n)
		nums.push_back(n);
	vector<vector<int>> result = sol.threeSum(nums);
	for (int i = 0; i < result.size(); i++) {
		cout << '(';
		for (int j = 0; j < result[i].size(); j++) {
			if (j > 0)
				cout << ", ";
			cout << result[i][j];
		}
		cout << ')' << endl;
	}
	return 0;
}
