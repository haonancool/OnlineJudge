#include <iostream>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int i = 0, j = 0, starIndex = -1, iIndex = -1;
		while (i < s.length()) {
			if (j < p.length() && (p[j] == '?' || s[i] == p[j])) {
				i++;
				j++;
			} else if (j < p.length() && p[j] == '*') {
				starIndex = j;
				iIndex = i;
				j++;
			} else if (starIndex != -1) {
				j = starIndex + 1;
				i = iIndex + 1;
				iIndex++;
			} else {
				return false;
			}
		}
		while (j < p.length() && p[j] == '*')
			j++;
		return j == p.length();
	}
};

int main() {
	string s, p;
	cin >> s >> p;
	Solution sol;
	bool match = sol.isMatch(s, p);
	cout << match << endl;
	return 0;
}
