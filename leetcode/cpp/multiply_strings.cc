#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";
		string reverse;
		int len1 = num1.length(), len2 = num2.length();
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				int carry = (num1[len1 - 1 - i] - '0') * (num2[len2 - 1 - j] - '0');
				bool first = true;
				for (int k = i + j; first || carry > 0; k++) {
					if (first)
						first = false;
					if (k >= reverse.length()) {
						reverse.push_back(carry % 10 + '0');
					} else {
						carry += reverse[k] - '0';
						reverse[k] = carry % 10 + '0';
					}
					carry /= 10;
				}
			}
		}
		return string(reverse.rbegin(), reverse.rend());
	}
};

int main() {
	string num1, num2;
	cin >> num1 >> num2;
	Solution sol;
	string num = sol.multiply(num1, num2);
	cout << num << endl;
	return 0;
}
