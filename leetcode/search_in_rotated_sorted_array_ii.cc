#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool search(vector<int> &nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] < target) {
				if (nums[mid] < nums[right]) {
					if (nums[right] >= target)
						left = mid + 1;
					else
						right = mid - 1;
				} else if (nums[mid] > nums[right]) {
					left = mid + 1;
				} else {
				    right--;
				}
			} else if (nums[mid] > target) {
				if (nums[mid] < nums[right]) {
					right = mid - 1;
				} else if (nums[mid] > nums[right]) {
					if (nums[left] <= target)
						right = mid - 1;
					else
						left = mid + 1;
				} else {
				    right--;
				}
			} else {
				return true;
			}
		}
		return false;
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
	int index = sol.search(nums, target);
	cout << index << endl;
	return 0;
}
