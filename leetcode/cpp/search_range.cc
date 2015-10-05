#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int> &nums, int target) {
		vector<int> range;
		if (nums.empty()) {
			range.push_back(-1);
			range.push_back(-1);
			return range;
		}
		int left = 0, right = nums.size() - 1;
		int first = -1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] < target) {
				left = mid + 1;
			} else if (nums[mid] > target) {
				right = mid - 1;
			} else {
				if (mid == 0 || nums[mid - 1] < target) {
					first = mid;
					break;
				} else {
					right = mid - 1;
				}
			}
		}
		range.push_back(first);
		left = 0;
		right = nums.size() - 1;
		int last = -1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] < target) {
				left = mid + 1;
			} else if (nums[mid] > target) {
				right = mid - 1;
			} else {
				if (mid == nums.size() - 1 || nums[mid + 1] > target) {
					last = mid;
					break;
				} else {
					left = mid + 1;
				}
			}
		}
		range.push_back(last);
		return range;
	}
};

int main() {
	int target;
	cin >> target;
	int n;
	vector<int> nums;
	while (cin >> n)
		nums.push_back(n);
	Solution sol;
	vector<int> range = sol.searchRange(nums, target);
	cout << range[0] << " " << range[1] << endl;
	return 0;
}
