class Solution {
public:
	int climbStairs(int n) {
		if (n == 0)
			return 0;
		int pre = 1, cur = 1;
		for (int i = 0; i < n - 1; i++) {
			int tmp = pre + cur;
			pre = cur;
			cur = tmp;
		}
		return cur;
	}
};
