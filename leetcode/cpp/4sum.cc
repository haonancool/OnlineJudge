#include <iostream>
#include <vector>
#include <algorithm>

using std::cout; using std::cin; using std::endl;
using std::vector;
using std::sort;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int> &nums, int target) {
		vector<vector<int>> ret;
		if (nums.size() < 4)
			return ret;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			for (int p = i + 1; p < nums.size() - 2; p++) {
				if (p > i + 1 && nums[p] == nums[p - 1])
					continue;
				int q = p + 1, r = nums.size() - 1;
				while (q < r) {
					int sum = nums[i] + nums[p] + nums[q] + nums[r];
					if (sum == target) {
						vector<int> temp;
						temp.push_back(nums[i]);
						temp.push_back(nums[p]);
						temp.push_back(nums[q]);
						temp.push_back(nums[r]);
						ret.push_back(temp);
						q++;
						while (q < r && nums[q] == nums[q - 1])
							q++;
						r--;
						while (q < r && nums[r] == nums[r + 1])
							r--;
					} else if (sum < target) {
						q++;
					} else {
						r--;
					}
				}
			}
		}
		return ret;
	}
};

int main() {
	int target, n = 0;
	cin >> target;
	vector<int> nums;
	while (cin >> n)
		nums.push_back(n);
	Solution sol;
	vector<vector<int>> result = sol.fourSum(nums, target);
	for (int i  = 0; i < result.size(); i++) {
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
