class Solution {
public:
	string addBinary(string a, string b) {
		string c;
		int i = a.length() - 1, j = b.length() - 1;
		int carry = 0;
		while (i >= 0 && j >= 0) {
			int n = (a[i] - '0') + (b[j] - '0') + carry;
			c.push_back(n % 2 + '0');
			carry = n / 2;
			i--;
			j--;
		}
		while (i >= 0) {
			int n = (a[i] - '0') + carry;
			c.push_back(n % 2 + '0');
			carry = n / 2;
			i--;
		}
		while (j >= 0) {
			int n = (b[j] - '0') + carry;
			c.push_back(n % 2 + '0');
			carry = n / 2;
			j--;
		}
		if (carry)
		    c.push_back('1');
		reverse(c.begin(), c.end());
		return c;
	}
};
