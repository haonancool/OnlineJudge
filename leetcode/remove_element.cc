class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = -1;
		for (int j = 0; j < nums.size(); j++) {
			if (nums[j] != val) {
				i++;
				int temp = nums[j];
				nums[j] = nums[i];
				nums[i] = temp;
			}
		}
		nums.resize(i + 1);
		return i + 1;
	}
};
