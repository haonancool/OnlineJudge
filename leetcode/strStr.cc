#include <iostream>
#include <vector>
#include <string>

using std::cout; using std::cin; using std::endl;
using std::vector;
using std::string;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty())
			return 0;
		vector<int> p(needle.size());
		p[0] = 0;
		int k = 0;
		for (int i = 1; i < needle.size(); i++) {
			while (k > 0 && needle[k] != needle[i])
				k = p[k - 1];
			if (needle[k] == needle[i])
				k++;
			p[i] = k;
		}
		int q = 0;
		for (int i = 0; i < haystack.size(); i++) {
			while (q > 0 && needle[q] != haystack[i])
				q = p[q -1];
			if (needle[q] == haystack[i])
				q++;
			if (q == needle.size())
				return (i + 1 - needle.size());
		}
		return -1;
	}
};

int main() {
	string haystack, needle;
	cin >> haystack >> needle;
	Solution sol;
	int index = sol.strStr(haystack, needle);
	cout << index << endl;
	return 0;
}
