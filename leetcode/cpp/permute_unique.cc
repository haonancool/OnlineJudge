class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int> &nums) {
		vector<vector<int>> result;
		if (nums.empty())
			return result;
		perm(result, nums, 0);
		return result;
	}
	void perm(vector<vector<int>> &result, vector<int> &nums, int i) {
		if (i == nums.size())
			result.push_back(nums);
		set<int> s;
		for (int j = i; j < nums.size(); j++) {
			if (s.find(nums[j]) != s.end())
				continue;
			s.insert(nums[j]);
			swap(nums[i], nums[j]);
			perm(result, nums, i + 1);
			swap(nums[i], nums[j]);
		}
	}
};
