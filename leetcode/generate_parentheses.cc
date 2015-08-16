#include <iostream>
#include <vector>
#include <string>

using std::cout; using std::cin; using std::endl;
using std::vector;
using std::string;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ret;
		if (0 == n)
			return ret;
		char *temp = new char[2 * n + 1];
		temp[2 * n] = '\0';
		int sum = 0, n_left = n, i = 0, len = 0;
		while (i >= 0) {
			if (len <= i) {
				if (n_left > 0) {
					temp[i] = '(';
					n_left--;
					sum++;
				} else {
					temp[i] = ')';
					sum--;
				}
				len++;
				if (i == 2 * n - 1)
					ret.push_back(temp);
				if (i < 2 * n - 1)
					i++;
			} else {
				if (temp[i] == '(' && sum >= 2)	{
					temp[i] = ')';
					n_left++;
					sum -= 2;
					if (i < 2 * n - 1)
						i++;
				} else {
					if (temp[i] == '(') {
						sum--;
						n_left++;
					} else {
						sum++;
					}	
					len--;
					i--;
				}
			}
		}
		delete []temp;
		return ret;
	}
};

int main() {
	int n;
	cin >> n;
	Solution sol;
	vector<string> result = sol.generateParenthesis(n);
	for (auto &s : result)
		cout << s << endl;
	return 0;
}
