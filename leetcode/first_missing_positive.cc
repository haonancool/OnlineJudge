class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		vector<int> flags(nums.size(), 0);
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0 && nums[i] <= flags.size())
				flags[nums[i] - 1] = 1;
		}
		for (int i = 0; i < flags.size(); i++) {
			if (!flags[i])
				return i + 1;
		}
		return flags.size() + 1;
	}
};
