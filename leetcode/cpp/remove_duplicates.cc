class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int ret = nums.size();
		if (nums.size() > 1) {
			int last = nums[0];
			for (int i = 1, j = 1; i < nums.size(); i++) {
				if (nums[i] == last) {
					ret--;
				} else {
					nums[j] = nums[i];
					j++;
				}	
				last = nums[i];
			}
		}
		nums.resize(ret);
		return ret;
	}
};
