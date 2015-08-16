class Solution {
public:
	string getPermutation(int n, int k) {
		string ret;
		k--;
		int div = 1;
		vector<char> nums;
		for (int i = 1; i <= n; i++)
			nums.push_back(i + '0');
		for (int i = 1; i <= n - 1; i++)
			div *= i;
		for (int i = n - 1; i >= 0; i--) {
			if (i == 0) {
				ret.push_back(nums[i]);
			} else {
				int j = k / div;
				ret.push_back(nums[j]);
				nums.erase(nums.begin() + j);
				k %= div;
				div /= i;
			}
		}
		return ret;
	}
};
