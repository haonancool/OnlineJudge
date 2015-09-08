#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int minCut(string s) {
		int len = s.length();
		if (0 == len) return 0;
		vector<int> cut(len, 0);
		vector<vector<int>> dp(len);
		for (int i = 0; i < len; i++)
			dp[i].resize(len, 0);
		for (int j = 0; j < len; j++) {
			cut[j] = j;
			for (int i = 0; i <= j; i++) {
				if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
					dp[i][j] = 1;
					if (i > 0 && cut[j] > cut[i - 1] + 1)
						cut[j] = cut[i - 1] + 1;
					else if (i == 0)
						cut[j] = 0;
				}
			}
		}
		return cut.back();
	}
};

int main() {
	string s;
	cin >> s;
	Solution sol;
	int n = sol.minCut(s);
	cout << n << endl;
	return 0;
}
