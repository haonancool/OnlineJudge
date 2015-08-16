class Solution {
public:
	vector<vector<int>> permute(vector<int> &nums) {
		vector<vector<int>> result;
		if (nums.empty())
			return result;
		perm(result, nums, 0);
		return result;
	}
	void perm(vector<vector<int>> &result, vector<int> &nums, int i) {
		if (i == nums.size())
			result.push_back(nums);
		for (int j = i; j < nums.size(); j++) {
			swap(nums[i], nums[j]);
			perm(result, nums, i + 1);
			swap(nums[i], nums[j]);
		}
	}
};
