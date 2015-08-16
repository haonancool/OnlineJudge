class Solution {
public:
	vector<vector<int>> ret;
	vector<int> cur;
	vector<int> index;
	vector<vector<int>> subsets(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		helper(nums);
		return ret;
	}
	void helper(vector<int> &nums) {
		ret.push_back(cur);
		if (cur.size() == nums.size())
			return;
		int i = 0;
		if (!index.empty())
			i = index.back() + 1;
		for (; i < nums.size(); i++) {
			cur.push_back(nums[i]);
			index.push_back(i);
			helper(nums);
			index.pop_back();
			cur.pop_back();
		}
	}
};
