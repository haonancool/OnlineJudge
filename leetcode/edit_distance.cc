#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.length(), n = word2.length();
		if (m == 0)
			return n;
		if (n == 0)
			return m;
		vector<int> table(n + 1);
		for (int i = 0; i <= n; i++)
			table[i] = i;
		for (int i = 1; i <= m; i++) {
			vector<int> tmp(n + 1);
			tmp[0] = i;
			for (int j = 1; j <= n; j++) {
				int minimum = table[j - 1];
				if (word1[i - 1] != word2[j - 1])
					minimum++;
				if (minimum > table[j] + 1)
					minimum = table[j] + 1;
				if (minimum > tmp[j - 1] + 1)
					minimum = tmp[j - 1] + 1;
				tmp[j] = minimum;
			}
			table = tmp;
		}
		return table.back();
	}
};

int main() {
	string word1, word2;
	cin >> word1 >> word2;
	Solution sol;
	int dist = sol.minDistance(word1, word2);
	cout << dist << endl;
	return 0;
}
