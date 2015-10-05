#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl;
using std::string;

class Solution {
public:
	string intToRoman(int num) {
		string ret;
		const char *ones = "MCXI";
		const char *fives = "_DLV";
		int dividend = 1000;
		for (int i = 0; i < 4; i++) {
			int digit = num / dividend;
			if (digit <= 3) {
				for (int j = 0; j < digit; j++)
					ret.push_back(ones[i]);
			} else if (4 == digit) {
				ret.push_back(ones[i]);
				ret.push_back(fives[i]);
			} else if (digit >= 5 && digit <= 8) {
				ret.push_back(fives[i]);
				for (int j = 5; j < digit; j++)
					ret.push_back(ones[i]);
			} else {
				if (9 == digit)
					ret.push_back(ones[i]);
				ret.push_back(ones[i - 1]);
			}
			num %= dividend;
			dividend /= 10;
		}
		return ret;
	} 	
};

int main() {
	int n = 0;
	Solution sol;
	while (cin >> n) {
		string roman = sol.intToRoman(n);
		cout << roman << endl;
	}
	return 0;
}
