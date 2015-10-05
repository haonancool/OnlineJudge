class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)
			return 1;
		if (n == 1)
			return x;
		bool negative = false;
		if (n < 0) {
			n = -n;
			negative = true;
		}
		double temp = myPow(x, n / 2);
		double ret = 0;
		if (n % 2 == 1)
			ret = temp * temp * x;
		else
			ret = temp * temp;
		if (negative)
		    ret = 1 / ret;
		return ret;
	}
};
