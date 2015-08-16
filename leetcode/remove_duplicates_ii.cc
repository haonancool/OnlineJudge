class Solution {
public:
	int removeDuplicates(vector<int> &nums) {
		int flag = 0;
		int j = -1;
		for (int i = 0; i < nums.size(); i++) {
			if (i == 0 || nums[i] != nums[i - 1]) {
				flag = 1;
				nums[++j] = nums[i];
			} else {
				if (flag < 2) {
					nums[++j] = nums[i];
					flag++;
				}
			}
		}
		nums.resize(j + 1);
		return j + 1;
	}
};
