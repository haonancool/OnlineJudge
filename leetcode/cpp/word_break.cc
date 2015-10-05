#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &wordDict) {
		vector<int> table(s.length(), 0);
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j <= i; j++) {
				if (wordDict.find(s.substr(j, i - j + 1)) != wordDict.end()
					&& (0 == j || table[j - 1])) {
					table[i] = 1;
					break;
				}
			}
		}	
		return table.back();
	}
};

int main() {
	string s;
	cin >> s;
	unordered_set<string> wordDict;
	string tmp;
	while (cin >> tmp)
		wordDict.insert(tmp);
	Solution sol;
	bool flag = sol.wordBreak(s, wordDict);
	cout << flag << endl;
	return 0;
}
