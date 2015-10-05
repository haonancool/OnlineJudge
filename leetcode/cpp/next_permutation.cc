#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int> &nums) {
		if (nums.size() < 2)
			return;
		int i = -1, j = -1;
		for (int k = 1; k < nums.size(); k++) {
			if (nums[k - 1] < nums[k]) {
				i = k - 1;
				j = k;
			} else if (i >= 0 && nums[k] <= nums[j] && nums[k] > nums[i]) {
				j = k;
			}
		}
		if (i >= 0) {
			int tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
		}
		int m = i + 1, n = nums.size() - 1;
		while (m < n) {
			int tmp = nums[m];
			nums[m] = nums[n];
			nums[n] = tmp;
			m++;
			n--;
		}
	}
};

int main() {
	int n;
	vector<int> nums;
	while (cin >> n)
		nums.push_back(n);
	Solution sol;
	sol.nextPermutation(nums);
	for (int num : nums)
		cout << num << " ";
	cout << endl;
	return 0;
}
