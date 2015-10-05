class Solution {
public:
	int searchInsert(vector<int> &nums, int target) {
		if (nums.empty())
			return 0;
		else if (nums.front() > target) 
			return 0;
		else if (nums.back() < target)
			return nums.size();
		int index = 0;
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] < target) {
				left = mid + 1;
			} else if (nums[mid] > target) {
				if (mid == 0 || nums[mid - 1] < target) {
					index = mid;
					break;
				} else {
					right = mid - 1;
				}
			} else {
				index = mid;
				break;
			}
		}
		return index;
	}
};
