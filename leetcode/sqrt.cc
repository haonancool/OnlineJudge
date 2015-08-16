class Solution {
public:
	int mySqrt(int x) {
		int left = 0, right = x;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (mid * mid == x) {
				return mid;
			} else if (mid * mid < x) {
				if ((mid + 1) * (mid + 1) > x)
					return mid;
				else
					left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		return 0;
	}
};
