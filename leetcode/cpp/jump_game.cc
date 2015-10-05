class Solution {
public:
	bool canJump(vector<int> &nums) {
		if (nums.empty())
			return false;
		int reach = 0;
		for (int i = 0; i <= reach && i < nums.size(); i++) {
			int tmp = i + nums[i];
			if (tmp > reach)
				reach = tmp;
			if (reach >= nums.size() - 1)
				return true;
		}
		return false;
	}
};
