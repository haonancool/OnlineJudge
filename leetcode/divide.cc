class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0) {
			return INT_MAX;
		} else if (dividend == 0) {
			return 0;
		} else if (divisor == -1) {
			if (dividend == INT_MIN)
				return INT_MAX;
			else
				return -dividend;
		} else if (divisor == 1) {
			return dividend;
		}
		return dividend / divisor;
	}
};
