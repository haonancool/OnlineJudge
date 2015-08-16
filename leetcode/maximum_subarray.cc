class Solution {
public:
	int maxSubArray(vector<int> &nums) {
		if (nums.empty())
			return 0;
		int max_num = nums.front();
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > max_num)
				max_num = nums[i];
		}
		if (max_num <= 0)
			return max_num;
		int sum = 0, max_sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (sum > max_sum)
				max_sum = sum;
			else if (sum < 0)
				sum = 0;
		}
		return max_sum;
	}
};
